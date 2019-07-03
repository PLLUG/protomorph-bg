#include <QApplication>

#include "recentproject.h"
#include "programsettings.h"
#include "projectviewerwindow.h"
#include "recentprojectsmodel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RecentProject pr1("/home/game1");
    RecentProject pr2("/home/igor/bla/blabla/game2");
    RecentProject pr3("/home/igor/Documents/game3");

    QVector<RecentProject> projects{pr1,pr2,pr3};

    ProgramSettings settings{projects};

    RecentProjectsModel model(settings);

    ProjectViewerWindow *pvw = new ProjectViewerWindow;
    pvw->setModel(&model);
    pvw->show();
    return a.exec();
}
