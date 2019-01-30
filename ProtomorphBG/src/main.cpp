#include "src/constants/Enums.hpp"
#include "src/helpers/QmlHelper.hpp"
#include "src/helpers/UISizeAdapter.hpp"
#include "src/models/GameIconsFilterModel.hpp"
#include "src/models/GameIconsListModel.hpp"
#include "src/models/SizesListModel.hpp"
#include "src/qmlitems/SvgCanvas.hpp"
#include "src/qmlitems/SvgImage.hpp"
#include "src/store/ComponentEditorStore.hpp"

#include <QuickFlux>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QFontDatabase>
#include <QIcon>
#include <QSplashScreen>
#include <QDesktopWidget>

#include <memory>

int main(int argc, char *argv[])
{
    qputenv("QML_DISABLE_DISK_CACHE", "true");

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setApplicationName(QStringLiteral("Protomorph BG"));

    QApplication app(argc, argv);

    //Show splashscreen
    auto splashScreenPixmap = QPixmap{QStringLiteral(":/splashscreen/splashScreen.png")};
    auto splashScreen = new QSplashScreen{splashScreenPixmap.scaled(splashScreenPixmap.size()), Qt::WindowStaysOnTopHint};
    splashScreen->show();
    QApplication::processEvents();

    //Set application style to material
    QQuickStyle::setStyle(QStringLiteral("Material"));

    //Load and set application font
    if (const auto id = QFontDatabase::addApplicationFont(QStringLiteral(":/Roboto-Regular.ttf")); id != -1)
    {
        auto familiesList = QFontDatabase::applicationFontFamilies(id);
        Q_ASSERT(!familiesList.empty());
        QApplication::setFont(QFont(familiesList.at(0)));
    }

    QApplication::setWindowIcon(QIcon{QStringLiteral(":/icons/protomorph-bg.ico")});

    //Register qml item
    qmlRegisterType<SvgImage>("protomorph.svgimage", 1, 0, "SvgImage");
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
    qmlRegisterType<ComponentEditorStore>("protomorph.componenteditorstoretemplate", 1, 0, "ComponentEditorStoreTemplate");

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


    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, [&splashScreen]{
        splashScreen->hide();
        splashScreen->close();
        splashScreen->deleteLater();
    });
    engine.addImportPath(QStringLiteral("qrc:///")); //Add "qrc://" to QML import path
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    auto dispatcher = QFAppDispatcher::instance(&engine);
    dispatcher->dispatch(QStringLiteral("startApp"));

    return QApplication::exec();
}
