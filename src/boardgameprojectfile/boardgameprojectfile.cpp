#include "boardgameprojectfile.h"
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QMessageBox>

#include "bgame_generated.h"

BoardGameProjectFile::BoardGameProjectFile(QWidget *parent)
    : QWidget(parent)
{

}

std::unique_ptr<BoardGame> BoardGameProjectFile::load(const QString &path)
{
    //this method is intentionally empty and will be implemented later on
}

void BoardGameProjectFile::save(const QString &path)
{
    // Build up a serialized buffer algorithmically:
    flatbuffers::FlatBufferBuilder builder;

    // First, lets serialize some description.
    auto description = builder.CreateString("Orest");

    // Use the `CreateBoardGame` shortcut to create BoardGame with all fields set.
    auto orest = CreateBoardGame(builder, description);

    builder.Finish(orest); // Serialize the root of the object.

    QFile lFile(path);
    if(lFile.open(QIODevice::WriteOnly))
    {
        // Створюємо тимчасовий QByteArray для запису даних
        QByteArray lData;
        auto data = reinterpret_cast<const char*>(builder.GetBufferPointer());
        auto size = static_cast<int>(builder.GetSize());
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
