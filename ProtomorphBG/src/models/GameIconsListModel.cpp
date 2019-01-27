#include "GameIconsListModel.hpp"

#include <QDirIterator>

 QStringList GameIconsListModel::m_gameIcons;

GameIconsListModel::GameIconsListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    if (m_gameIcons.isEmpty())
    {
        QDirIterator sourceDirIterator(QStringLiteral(":/gameicons"));

        QFileInfo sourceFileInfo;
        while (sourceDirIterator.hasNext()) {
            sourceFileInfo.setFile(sourceDirIterator.next());
            m_gameIcons.push_back(QStringLiteral("qrc%1").arg(sourceFileInfo.filePath()));
        }
    }
}

int GameIconsListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_gameIcons.size();
}

QVariant GameIconsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto iconUrlIndex = index.row();

    if (role == IconUrlRole)
        return m_gameIcons.at(iconUrlIndex);


    return QVariant();
}

QHash<int, QByteArray> GameIconsListModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {IconUrlRole, "iconUrlRole"}
    };
    return roles;
}
