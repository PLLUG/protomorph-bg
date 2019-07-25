#include <QApplication>
#include <QStandardItemModel>

#include "prototypecomponentsnavigatorwindow.h"
#include "recentproject.h"
#include "programsettings.h"
#include "projectviewerwindow.h"
#include "recentprojectsmodel.h"
#include "bgame_generated.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Build up a serialized buffer algorithmically:
    flatbuffers::FlatBufferBuilder builder;

    // First, lets serialize some description.
    auto descriptionOne = builder.CreateString("Orest");
    auto descriptionTwo = builder.CreateString("Man");

    // Use the `CreateBoardGame` shortcut to create BoardGame with all fields set.
    auto orest = CreateBoardGame(builder, descriptionOne);
    auto man = CreateBoardGame(builder, descriptionTwo);

    // Create a FlatBuffer's `vector` from the `std::vector`.
    std::vector<flatbuffers::Offset<BoardGame>> boardGame_vector;
    boardGame_vector.push_back(orest);
    boardGame_vector.push_back(man);
    auto boardGame = builder.CreateVector(boardGame_vector);

     // Shortcut for creating BoardGame with all fields set:

    auto game = CreateBoardGame(builder, boardGame);

    builder.Finish(game); // Serialize the root of the object.
    builder.GetBufferPointer();
    builder.GetSize();

//    ///
//    ///   Project Viewer Window
//    ///

//    RecentProject pr1("/home/game1");
//    RecentProject pr2("/home/igor/bla/blabla/game2");
//    RecentProject pr3("/home/igor/Documents/game3");

//    QVector<RecentProject> projects{pr1,pr2,pr3};

//    ProgramSettings settings{projects};

//    RecentProjectsModel recentProjectsModel(settings);

//    ProjectViewerWindow *pvw = new ProjectViewerWindow;
//    pvw->setModel(&recentProjectsModel);
//    pvw->show();



//    QStandardItemModel componentsModel;

//    componentsModel.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item1"));
//    componentsModel.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item2"));
//    componentsModel.appendRow(new QStandardItem(QIcon(":/new/preview/images/project"), "item3"));

//    PrototypeComponentsNavigatorWindow componentsNavigatorWindow;

//    componentsNavigatorWindow.setModel(&componentsModel);


//    QObject::connect(pvw, &ProjectViewerWindow::newProjectRequested,
//                     pvw, &ProjectViewerWindow::close);

//    QObject::connect(pvw, &ProjectViewerWindow::newProjectRequested,
//                     &componentsNavigatorWindow, &PrototypeComponentsNavigatorWindow::show);

    return a.exec();
}
