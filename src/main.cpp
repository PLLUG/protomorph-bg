#include <QApplication>
#include <QStandardItemModel>
#include "prototypecomponentsnavigatorwindow.h"

#include "recentproject.h"
#include "programsettings.h"
#include "projectviewerwindow.h"
#include "recentprojectsmodel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

<<<<<<< HEAD
//    QStandardItemModel model;

//    model.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item1"));
//    model.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item2"));
//    model.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item3"));

//    PrototypeComponentsNavigatorWindow window;

//    window.setModel(&model);
//    window.show();
=======
    RecentProject pr1("/home/game1");
    RecentProject pr2("/home/igor/bla/blabla/game2");
    RecentProject pr3("/home/igor/Documents/game3");

    QVector<RecentProject> projects{pr1,pr2,pr3};

    ProgramSettings settings{projects};

    RecentProjectsModel model(settings);

    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    pvw->setModel(&model);
    pvw->show();
>>>>>>> development
    return a.exec();
}
