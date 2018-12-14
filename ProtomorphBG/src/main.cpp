#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "src/models/SizesListModel.hpp"
#include "src/helpers/QmlHelper.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //Register models
    qmlRegisterType<SizesListModel>("protomorph.sizelistmodel", 1, 0, "SizesListModel");

    //Register singletons
    qmlRegisterSingletonType<Helper::QmlHelper>("protomorph.qmlhelper", 1, 0, "QmlHelper", [](auto qmlEngine, auto jsEngine) -> QObject* {
        Q_UNUSED(jsEngine)
        qmlEngine->setObjectOwnership(Helper::QmlHelper::instance(), QQmlEngine::CppOwnership);
        return Helper::QmlHelper::instance();
    });

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
