#include <QApplication>
#include "projectviewerwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    pvw->show();
    return a.exec();
}
