#include <QApplication>
#include "prototypecomponentsnavigatorwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
PrototypeComponentsNavigatorWindow window;
window.show();
    return a.exec();
}
