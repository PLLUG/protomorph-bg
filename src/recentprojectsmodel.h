#ifndef RECENTPROJECTSMODEL_H
#define RECENTPROJECTSMODEL_H

#include <QAbstractListModel>

#include "programsettings.h"
#include "recentproject.h"

class RecentProjectsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    RecentProjectsModel(const ProgramSettings &settings,QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    ProgramSettings mSettings;
};

#endif // RECENTPROJECTSMODEL_H
