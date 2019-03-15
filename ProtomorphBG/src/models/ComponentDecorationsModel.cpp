#include "ComponentDecorationsModel.hpp"

#include "src/store/DecorationStore.hpp"
#include <src/store/GameIconDecorationStore.hpp>

#include <QItemSelectionModel>

ComponentDecorationsModel::ComponentDecorationsModel(QObject *parent)
    : QAbstractListModel{parent}
      , m_selectionModel{std::make_unique<QItemSelectionModel>(this)}
{
}

ComponentDecorationsModel::~ComponentDecorationsModel() = default;

void ComponentDecorationsModel::addDecorationStore(DecorationStorePtr &&newDecorationStore)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    m_componentDecorations.emplace_back(std::move(newDecorationStore));

    endInsertRows();
}

void ComponentDecorationsModel::removeDecorationStore(int indexRow)
{
    beginRemoveRows(QModelIndex(), indexRow, indexRow);

    auto itToRemove = std::begin(m_componentDecorations) + indexRow;

    m_componentDecorations.erase(itToRemove);

    endRemoveRows();
}

void ComponentDecorationsModel::clearDecorationSelectionAndNotify()
{
    auto selectedIndexes = m_selectionModel->selectedIndexes();
    m_selectionModel->clearSelection();

    for (const auto &selectedIndex : selectedIndexes)
        emit dataChanged(selectedIndex, selectedIndex, {static_cast<int>(SelectedRole)});
}

void ComponentDecorationsModel::setDecorationSelection(int indexRow)
{
    auto modelIndex = index(indexRow);
    if (m_selectionModel->isSelected(modelIndex))
        return;

    clearDecorationSelectionAndNotify();

    m_selectionModel->select(modelIndex, QItemSelectionModel::Select);
    emit dataChanged(modelIndex, modelIndex, {static_cast<int>(SelectedRole)});
}

void ComponentDecorationsModel::clearDecorationSelection()
{
    if(m_selectionModel->hasSelection())
        clearDecorationSelectionAndNotify();
}

int ComponentDecorationsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return static_cast<int>(m_componentDecorations.size());
}

QVariant ComponentDecorationsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto indexRow = index.row();
    const auto &decoration = m_componentDecorations.at(static_cast<size_t>(indexRow));

    switch (role) {
    case TypeRole:
        return static_cast<int>(decoration->decorationType());
    case DecorationStoreRole:
        return getTypedDecorationStore(decoration);
    case SelectedRole:
        return m_selectionModel->isSelected(index);
    case ZOrderRole:
        return indexRow;
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> ComponentDecorationsModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {TypeRole, QByteArrayLiteral("typeRole")},
        {DecorationStoreRole, QByteArrayLiteral("decorationStoreRole")},
        {SelectedRole, QByteArrayLiteral("selectedRole")},
        {ZOrderRole, QByteArrayLiteral("zOrderRole")},
    };
    return roles;
}

QVariant ComponentDecorationsModel::getTypedDecorationStore(const DecorationStorePtr &decorationStore) const
{
    switch (decorationStore->decorationType())
    {
    case Enums::DecorationType::DECORATION_GAME_ICON: {
        auto gameIconStore = qobject_cast<GameIconDecorationStore *>(decorationStore.get());
        return QVariant::fromValue(gameIconStore);
    }
    default:
        return QVariant::fromValue(decorationStore.get());
    }
}
