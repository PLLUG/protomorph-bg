#ifndef PROTOMORPHBGAPPLICATION_HPP
#define PROTOMORPHBGAPPLICATION_HPP

#include <QApplication>

namespace Dataobject {
struct EditorComponent;
}

class ComponentEditorStore;
class QFAppDispatcher;
class QQmlApplicationEngine;
class QSplashScreen;

class ProtomorphBGApplication final: public QApplication
{
public:
    ProtomorphBGApplication(int argc, char *argv[]);
    ~ProtomorphBGApplication();

    bool runQmlEngine();

private:
    void initSplashScreen();
    void configureApplicationStyle();
    void registerQmlComponents();

    QQmlApplicationEngine *m_engine{};
    QFAppDispatcher *m_appDispatcher{};
    QSplashScreen *m_splashScreen{};

    //TODO: Component member is temporary here, while data serializator and objects pool will not introduced
    std::shared_ptr<Dataobject::EditorComponent> m_component;
};

#endif // PROTOMORPHBGAPPLICATION_HPP
