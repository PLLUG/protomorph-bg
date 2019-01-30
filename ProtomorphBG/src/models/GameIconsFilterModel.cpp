#include "src/models/GameIconsFilterModel.hpp"
#include "src/models/GameIconsListModel.hpp"

GameIconsFilterModel::GameIconsFilterModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    connect(this, &GameIconsFilterModel::searchPatternChanged,
            this, &GameIconsFilterModel::invalidate, Qt::UniqueConnection);
}

GameIconsFilterModel::~GameIconsFilterModel() = default;

GameIconsFilterModel *GameIconsFilterModel::instance()
{
    static GameIconsFilterModel gameIconsFilterModelInstance;
    return &gameIconsFilterModelInstance;
}

QString GameIconsFilterModel::searchPattern() const
{
    return m_searchPattern;
}

void GameIconsFilterModel::setSearchPattern(QString searchPattern)
{
    if (m_searchPattern == searchPattern)
        return;

    m_searchPattern = searchPattern;
    emit searchPatternChanged(m_searchPattern);
}

bool GameIconsFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    auto originalModel = sourceModel();
    if (!originalModel && !source_parent.isValid())
        return false;

    auto originalModelIndex = originalModel->index(source_row, 0, source_parent);

    if(!originalModelIndex.isValid())
        return false;

    auto iconName = originalModel->data(originalModelIndex, GameIconsListModel::IconNameRole).toString();
    return m_searchPattern.isEmpty() ? true : iconName.contains(m_searchPattern, Qt::CaseInsensitive);
}
