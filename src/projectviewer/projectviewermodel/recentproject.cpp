#include "recentproject.h"


RecentProject::RecentProject(const QString &path)
    : mPath{path}
{
}

QString RecentProject::name() const
{
    return mPath.mid(mPath.lastIndexOf('/') + 1);
}

QString RecentProject::path() const
{
    return mPath;
}
