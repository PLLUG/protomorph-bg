#ifndef BOARDGAMEPROJECTFILE_H
#define BOARDGAMEPROJECTFILE_H

#include <QWidget>

class QString;

class BoardGameProjectFile : public QWidget
{
    Q_OBJECT

public:
    BoardGameProjectFile(QWidget *parent = nullptr);

    static void save(const QString &path);
};

#endif // BOARDGAMEPROJECTFILE_H
