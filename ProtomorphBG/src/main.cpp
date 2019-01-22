#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QFontDatabase>
#include <QIcon>

#include <QuickFlux>

#include "src/helpers/QmlHelper.hpp"
#include "src/helpers/UISizeAdapter.hpp"
#include "src/models/SizesListModel.hpp"
#include "src/store/ComponentEditorStore.hpp"

int main(int argc, char *argv[])
{
    qputenv("QML_DISABLE_DISK_CACHE", "true");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationName(QStringLiteral("Protomorph BG"));

    QApplication app(argc, argv);

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

    //Register models
    qmlRegisterType<SizesListModel>("protomorph.sizelistmodel", 1, 0, "SizesListModel");

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

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qrc:///")); //Add "qrc://" to QML import path
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    auto dispatcher = QFAppDispatcher::instance(&engine);
    dispatcher->dispatch(QStringLiteral("startApp"));

    return QApplication::exec();
}
