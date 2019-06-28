#include <QApplication>
#include <QStringListModel>
#include <QStandardItemModel>
#include "projectviewerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel *model = new QStandardItemModel;
    model->appendRow(new QStandardItem(QIcon("/home/igor/icon"), "path1"));
    model->appendRow(new QStandardItem(QIcon("/home/igor/icon"), "path2"));
    model->appendRow(new QStandardItem(QIcon("/home/igor/icon"), "path3"));

    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    pvw->setModel(model);
    pvw->show();
    return a.exec();
}
