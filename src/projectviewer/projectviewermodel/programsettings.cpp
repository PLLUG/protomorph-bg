#include "programsettings.h"
#include "recentproject.h"

ProgramSettings::ProgramSettings(const QVector<RecentProject> &recentProjects)
    : mRecentProjects{recentProjects}
{

}

const QVector<RecentProject> &ProgramSettings::recentProjects() const
{
    return mRecentProjects;
}
