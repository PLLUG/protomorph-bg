#ifndef PROTOMORPHBGAPPLICATION_HPP
#define PROTOMORPHBGAPPLICATION_HPP

#include <QApplication>

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
};

#endif // PROTOMORPHBGAPPLICATION_HPP
