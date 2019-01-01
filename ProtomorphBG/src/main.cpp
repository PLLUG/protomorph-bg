#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QFontDatabase>
#include <QIcon>

#include <QuickFlux>

#include "src/helpers/QmlHelper.hpp"
#include "src/models/SizesListModel.hpp"
#include "src/store/ComponentEditorStore.hpp"

int main(int argc, char *argv[])
{
    qputenv("QML_DISABLE_DISK_CACHE", "true");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationName(QLatin1String("Protomorph BG"));

    QGuiApplication app(argc, argv);

    //Set application style to material
    QQuickStyle::setStyle(QLatin1String("Material"));

    //Load and set application font
    if (const auto id = QFontDatabase::addApplicationFont(QLatin1String(":/Roboto-Regular.ttf")); id != -1)
    {
        auto familiesList = QFontDatabase::applicationFontFamilies(id);
        Q_ASSERT(!familiesList.empty());
        app.setFont(QFont(familiesList.at(0)));
    }

    app.setWindowIcon(QIcon{QLatin1String{":/icons/protomorph-bg.ico"}});

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

    QQmlApplicationEngine engine;
    engine.addImportPath(QLatin1String("qrc:///")); //Add "qrc://" to QML import path
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    auto dispatcher = QFAppDispatcher::instance(&engine);
    dispatcher->dispatch(QLatin1String("startApp"));

    return app.exec();
}
