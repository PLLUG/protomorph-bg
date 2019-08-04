#include "boardgameprojectfile.h"
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>

std::unique_ptr<BoardGame> BoardGameProjectFile::load(const QString &path)
{

}

void BoardGameProjectFile::save(const QString &path)
{
    // Build up a serialized buffer algorithmically:
    flatbuffers::FlatBufferBuilder builder;

    // First, lets serialize some description.
    auto descriptionOne = builder.CreateString("Orest");
    //    auto descriptionTwo = builder.CreateString("Man");

    // Use the `CreateBoardGame` shortcut to create BoardGame with all fields set.
    auto orest = CreateBoardGame(builder, descriptionOne);
    //    auto man = CreateBoardGame(builder, descriptionTwo);

    //    // Create a FlatBuffer's `vector` from the `std::vector`.
    //    std::vector<flatbuffers::Offset<BoardGame>> boardGame_vector;
    //    boardGame_vector.push_back(orest);
    //    boardGame_vector.push_back(man);
    //    auto boardGame = builder.CreateVector(boardGame_vector);

    //     // Shortcut for creating BoardGame with all fields set:

    //    auto game = CreateBoardGame(builder, boardGame);

    builder.Finish(orest); // Serialize the root of the object.
    //    builder.GetBufferPointer();
    //    builder.GetSize();

    QFile file("file.bgame");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&file);
        stream << builder.GetBufferPointer() << builder.GetSize();
        if(stream.status() != QDataStream::Ok)
        {
            qDebug() << "Error";
        }
    }
    file.close();
}
