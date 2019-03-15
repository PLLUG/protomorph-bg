#include "src/ProtomorphBGApplication.hpp"

#include "src/constants/Enums.hpp"
#include "src/dataobjects/EditorComponent.hpp"
#include "src/helpers/QmlHelper.hpp"
#include "src/helpers/UISizeAdapter.hpp"
#include "src/models/ComponentDecorationsModel.hpp"
#include "src/models/GameIconsFilterModel.hpp"
#include "src/models/GameIconsListModel.hpp"
#include "src/models/SizesListModel.hpp"
#include "src/qmlitems/SvgPainter.hpp"
#include "src/store/ComponentEditorStore.hpp"

#include <QuickFlux>

#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QFontDatabase>
#include <QIcon>
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QQmlContext>

ProtomorphBGApplication::ProtomorphBGApplication(int argc, char *argv[])
    : QApplication{argc, argv}
    , m_engine{new QQmlApplicationEngine{this}}
    , m_appDispatcher{QFAppDispatcher::instance(m_engine)}
    , m_splashScreen{new QSplashScreen}
    , m_component{std::make_shared<EditorComponent>()}
{
    configureApplicationStyle();
    initSplashScreen();
    registerQmlComponents();
}

ProtomorphBGApplication::~ProtomorphBGApplication() = default;

void ProtomorphBGApplication::initSplashScreen()
{
    connect(m_engine, &QQmlApplicationEngine::objectCreated, m_splashScreen, &QSplashScreen::close, Qt::UniqueConnection);
    connect(m_engine, &QQmlApplicationEngine::objectCreated, m_splashScreen, &QSplashScreen::deleteLater, Qt::UniqueConnection);

    auto splashScreenPixmap = QPixmap{QStringLiteral(":/splashscreen/splashScreen.png")};
    m_splashScreen->setPixmap(splashScreenPixmap);
    m_splashScreen->show();
    processEvents();
}

void ProtomorphBGApplication::configureApplicationStyle()
{
    setApplicationName(QStringLiteral("Protomorph BG"));

    //Set application style to material
    QQuickStyle::setStyle(QStringLiteral("Material"));

    //Load and set application font
    if (const auto id = QFontDatabase::addApplicationFont(QStringLiteral(":/Roboto-Regular.ttf")); id != -1)
    {
        auto familiesList = QFontDatabase::applicationFontFamilies(id);
        Q_ASSERT(!familiesList.empty());
        setFont(QFont(familiesList.at(0)));
    }

    setWindowIcon(QIcon{QStringLiteral(":/icons/protomorph-bg.ico")});
}

void ProtomorphBGApplication::registerQmlComponents()
{
    //Register qml item
    qmlRegisterType<SvgPainter>("protomorph.svgimage", 1, 0, "SvgPainter");

    //Register models
    qmlRegisterType<SizesListModel>("protomorph.sizelistmodel", 1, 0, "SizesListModel");

    qmlRegisterSingletonType<GameIconsListModel>("protomorph.gameiconsmodel", 1, 0, "GameIconsListModel", [](auto qmlEngine, auto jsEngine) -> QObject* {
        Q_UNUSED(jsEngine)
        qmlEngine->setObjectOwnership(GameIconsListModel::instance(), QQmlEngine::CppOwnership);
        return GameIconsListModel::instance();
    });

    GameIconsFilterModel::instance()->setSourceModel(GameIconsListModel::instance());
    qmlRegisterSingletonType<GameIconsFilterModel>("protomorph.gameiconsmodel", 1, 0, "GameIconsFilterModel", [](auto qmlEngine, auto jsEngine) -> QObject* {
        Q_UNUSED(jsEngine)
        qmlEngine->setObjectOwnership(GameIconsFilterModel::instance(), QQmlEngine::CppOwnership);
        return GameIconsFilterModel::instance();
    });

    //Register stores
    auto &componentEditorStore = ComponentEditorStore::instance();
    componentEditorStore.setComponent(m_component);
    componentEditorStore.setBindSource(m_appDispatcher);
    qmlRegisterSingletonType<ComponentEditorStore>("protomorph.componenteditorstore", 1, 0, "ComponentEditorStore", [](auto qmlEngine, auto jsEngine) -> QObject* {
        Q_UNUSED(jsEngine)
        qmlEngine->setObjectOwnership(&ComponentEditorStore::instance(), QQmlEngine::CppOwnership);
        return &ComponentEditorStore::instance();
    });

    m_engine->rootContext()->setContextProperty(QStringLiteral("ComponentDecorationsModel"),
                                                &componentEditorStore.componentDecorationsModel());

    //Register singletons
    qmlRegisterSingletonType<Helper::QmlHelper>("protomorph.qmlhelper", 1, 0, "QmlHelper", [](auto qmlEngine, auto jsEngine) -> QObject* {
        Q_UNUSED(jsEngine)
        qmlEngine->setObjectOwnership(Helper::QmlHelper::instance(), QQmlEngine::CppOwnership);
        return Helper::QmlHelper::instance();
    });

    qmlRegisterSingletonType<Helper::UISizeAdapter>("protomorph.uisizeadapter", 1, 0, "UISizeAdapter", [](auto qmlEngine, auto jsEngine) -> QObject* {
        Q_UNUSED(jsEngine)
        qmlEngine->setObjectOwnership(Helper::UISizeAdapter::instance(), QQmlEngine::CppOwnership);
        return Helper::UISizeAdapter::instance();
    });

    //Register enums
    qmlRegisterUncreatableType<Enums>("protomorph.enums", 1, 0, "Enums", "Enums");
}

bool ProtomorphBGApplication::runQmlEngine()
{
    m_engine->addImportPath(QStringLiteral("qrc:///")); //Add "qrc://" to QML import path
    m_engine->load(QStringLiteral("qrc:/main.qml"));

    if (m_engine->rootObjects().isEmpty())
        return false;

    m_appDispatcher->dispatch(QStringLiteral("startApp"));

    return true;
}
