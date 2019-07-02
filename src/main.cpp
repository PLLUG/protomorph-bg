#include <QtDebug>
#include <QApplication>
#include <QStringListModel>
#include <QStandardItemModel>

#include "recentproject.h"
#include "programsettings.h"
#include "projectviewerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RecentProject pr1("/home/game1");
    RecentProject pr2("/home/igor/bla/blabla/game2");
    RecentProject pr3("/home/igor/Documents/game3");

    qDebug()<<pr1.name();
    qDebug()<<pr2.name();
    qDebug()<<pr3.name();

    QVector<RecentProject> projects{pr1,pr2};

    ProgramSettings settings{projects};

    foreach(const auto &project, settings.recentProjects())
    {
        qDebug()<<project.name();
    }

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
