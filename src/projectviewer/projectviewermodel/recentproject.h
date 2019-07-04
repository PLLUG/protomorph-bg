#ifndef RECENTPROJECT_H
#define RECENTPROJECT_H

#include <QString>

class RecentProject
{
public:
    RecentProject(const QString &path);

    QString name() const;
    QString path() const;
private:
    QString mPath;
};

#endif // RECENTPROJECT_H
