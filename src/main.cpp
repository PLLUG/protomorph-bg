#include <QApplication>
#include <QStringListModel>
#include <QStandardItemModel>
#include "projectviewerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel model;

    QStandardItem it1(QIcon(":/projectviewer/images/projecticon"), "path1");
    QStandardItem it2(QIcon(":/projectviewer/images/projecticon"), "looooooooong path");
    QStandardItem it3(QIcon(":/projectviewer/images/projecticon"), "path3");

    model.appendRow(&it1);
    model.appendRow(&it2);
    model.appendRow(&it3);

    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    pvw->setModel(&model);
    pvw->show();
    return a.exec();
}
