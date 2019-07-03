#include "recentproject.h"
#include <QFileInfo>

RecentProject::RecentProject(const QString &path)
    : mPath{path}
{
}

QString RecentProject::name() const
{
    QFileInfo fi(mPath);
    return fi.completeBaseName();
}

QString RecentProject::path() const
{
    return mPath;
}
