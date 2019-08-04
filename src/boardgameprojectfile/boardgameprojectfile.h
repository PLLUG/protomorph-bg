#ifndef BOARDGAMEPROJECTFILE_H
#define BOARDGAMEPROJECTFILE_H

#include <memory>

class QString;
class BoardGame;

class BoardGameProjectFile
{
public:
    BoardGameProjectFile();

    static std::unique_ptr<BoardGame> load(const QString &path);
    static void save(const QString &path);
};

#endif // BOARDGAMEPROJECTFILE_H
