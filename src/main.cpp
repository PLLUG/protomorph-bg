#include <QApplication>
#include <QStringListModel>
#include <QStandardItemModel>
#include "projectviewerwindow.h"

int main(int argc, char *argv[])
{

    QStandardItemModel *model = new QStandardItemModel;
    QApplication a(argc, argv);
    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    model->appendRow(new QStandardItem(QIcon("/home/igor/icon"), "path1"));
    model->appendRow(new QStandardItem(QIcon("/home/igor/icon"), "path2"));
    model->appendRow(new QStandardItem(QIcon("/home/igor/icon"), "path3"));

    pvw->setModel(model);
    pvw->show();
    return a.exec();
}
