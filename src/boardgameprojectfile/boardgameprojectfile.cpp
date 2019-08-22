#include "boardgameprojectfile.h"
#include <QFile>
#include <QString>
#include <QMessageBox>

#include "bgame_generated.h"

BoardGameProjectFile::BoardGameProjectFile(QWidget *parent)
    : QWidget(parent)
{

}

void BoardGameProjectFile::save(const QString &path)
{
    // Build up a serialized buffer algorithmically:
    flatbuffers::FlatBufferBuilder builder;

    // First, lets serialize some description.
    auto description = builder.CreateString("Orest");

    // Use the `CreateBoardGame` shortcut to create BoardGame with all fields set.
    auto boardGame = CreateBoardGame(builder, description);

    builder.Finish(boardGame); // Serialize the root of the object.

    QFile lFile(path);
    if(lFile.open(QIODevice::WriteOnly))
    {
        // Createing temporary QByteArray for saving data
        QByteArray lData;
        auto data = reinterpret_cast<const char*>(builder.GetBufferPointer());
        auto size = reinterpret_cast<const char*>(builder.GetSize());
        lData.append(data);
        lData.append(size);
        lFile.write(lData);
        lFile.close();
    }
    else
    {
        QMessageBox::warning(NULL, tr("Error"), QString(tr("Could not open file %1 for writing")).arg(lFile.fileName()), QMessageBox::Ok);
    }
}
