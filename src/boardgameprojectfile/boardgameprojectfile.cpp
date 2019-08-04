#include "boardgameprojectfile.h"
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>

#include "flatbuffers/bgame_generated.h"


std::unique_ptr<BoardGame> BoardGameProjectFile::load(const QString &path)
{
    //this method is intentionally empty and will be implemented later on
}

void BoardGameProjectFile::save(const QString &path)
{
    // Build up a serialized buffer algorithmically:
    flatbuffers::FlatBufferBuilder builder;

    // First, lets serialize some description.
    auto descriptionOne = builder.CreateString("Orest");

    // Use the `CreateBoardGame` shortcut to create BoardGame with all fields set.
    auto orest = CreateBoardGame(builder, descriptionOne);

    builder.Finish(orest); // Serialize the root of the object.

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
