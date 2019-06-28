#include <QApplication>
#include <QStringListModel>
#include "projectviewerwindow.h"

int main(int argc, char *argv[])
{
    QStringListModel * slm = new QStringListModel;
    QStringList list;
    list << "path1" << "another/path" << "path/3";

    slm->setStringList(list);

    QApplication a(argc, argv);
    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    pvw->setModel(slm);
    pvw->show();
    return a.exec();
}
