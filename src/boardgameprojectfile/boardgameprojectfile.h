#ifndef BOARDGAMEPROJECTFILE_H
#define BOARDGAMEPROJECTFILE_H

#include "flatbuffers/bgame_generated.h"

class QString;

class BoardGameProjectFile
{
public:
    BoardGameProjectFile();

    static std::unique_ptr<BoardGame> load(const QString &path);
    static void save(const QString &path);
};

#endif // BOARDGAMEPROJECTFILE_H
