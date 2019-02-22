#include "src/ProtomorphBGApplication.hpp"

int main(int argc, char *argv[])
{
    qputenv("QML_DISABLE_DISK_CACHE", "true");

    ProtomorphBGApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    ProtomorphBGApplication app{argc, argv};

    if (!app.runQmlEngine())
        return -1;

    return app.exec();
}
