#include "recentprojectsmodel.h"

#include <QDebug>
#include <QIcon>

RecentProjectsModel::RecentProjectsModel(const ProgramSettings &settings, QObject *parent)
    :mSettings{settings}
{

}

int RecentProjectsModel::rowCount(const QModelIndex &parent) const
{
    return mSettings.recentProjects().size();
}

int RecentProjectsModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant RecentProjectsModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    qDebug() << QString("row %1, col%2, role %3")
               .arg(row).arg(col).arg(role);

    switch (role)
    {
        case Qt::DisplayRole:
            return mSettings.recentProjects().at(row).name();
        case Qt::DecorationRole:
            QIcon icon(":/projectviewer/images/projecticon");
            return icon;
    }

    return QVariant();
}
