#include <QApplication>
#include <QStandardItemModel>
#include "prototypecomponentsnavigatorwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel model;

    model.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item1"));
    model.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item2"));
    model.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item3"));

    PrototypeComponentsNavigatorWindow window;

    window.setModel(&model);
    window.show();
    return a.exec();
}
