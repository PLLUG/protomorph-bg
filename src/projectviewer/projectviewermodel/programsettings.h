#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H

#include <QVector>

class RecentProject;

class ProgramSettings
{
public:
    ProgramSettings(const QVector<RecentProject> & recentProjects);

    const QVector<RecentProject> &recentProjects() const;

private:
    QVector<RecentProject> mRecentProjects;
};

#endif // PROGRAMSETTINGS_H
