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

    ///
    ///   Project Viewer Window
    ///

    RecentProject pr1("/home/game1");
    RecentProject pr2("/home/igor/bla/blabla/game2");
    RecentProject pr3("/home/igor/Documents/game3");

    QVector<RecentProject> projects{pr1,pr2,pr3};

    ProgramSettings settings{projects};

    RecentProjectsModel recentProjectsModel(settings);

    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    pvw->setModel(&recentProjectsModel);
    pvw->show();



    QStandardItemModel componentsModel;

    componentsModel.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item1"));
    componentsModel.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item2"));
    componentsModel.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item3"));

    PrototypeComponentsNavigatorWindow componentsNavigatorWindow;

    componentsNavigatorWindow.setModel(&componentsModel);


    QObject::connect(pvw, &ProjectViewerWindow::newProjectRequested,
                     pvw, &ProjectViewerWindow::close);

    QObject::connect(pvw, &ProjectViewerWindow::newProjectRequested,
                     &componentsNavigatorWindow, &PrototypeComponentsNavigatorWindow::show);

    return a.exec();
}
