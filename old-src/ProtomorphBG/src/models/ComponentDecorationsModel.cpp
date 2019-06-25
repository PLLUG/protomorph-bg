#include "ComponentDecorationsModel.hpp"

#include "src/store/DecorationStore.hpp"
#include <src/store/GameIconDecorationStore.hpp>

#include <QDebug>
#include <QItemSelectionModel>

ComponentDecorationsModel::ComponentDecorationsModel(QObject *parent)
    : QAbstractListModel{parent}
      , m_selectionModel{std::make_unique<QItemSelectionModel>(this)}
{
    connect(m_selectionModel.get(), &QItemSelectionModel::selectionChanged,
            this, &ComponentDecorationsModel::onDecorationSelectionChanged, Qt::UniqueConnection);
}

ComponentDecorationsModel::~ComponentDecorationsModel() = default;

void ComponentDecorationsModel::addDecorationStore(DecorationStorePtr &&newDecorationStore)
{
    auto indexRow = rowCount();
    beginInsertRows(QModelIndex(), indexRow, indexRow);

    m_componentDecorations.emplace_back(std::move(newDecorationStore));

    endInsertRows();

    setDecorationSelection(index(indexRow), true);
}

void ComponentDecorationsModel::removeDecoration(int indexRow)
{
    beginRemoveRows(QModelIndex(), indexRow, indexRow);

    auto itToRemove = std::begin(m_componentDecorations) + indexRow;

    m_componentDecorations.erase(itToRemove);

    endRemoveRows();
}

void ComponentDecorationsModel::setDecorationSelection(const QModelIndex &selectionModelIndex, bool shouldBeSelected)
{
    if (shouldBeSelected)
    {
        if (m_selectionModel->isSelected(selectionModelIndex))
            return;

        clearDecorationSelection();

        m_selectionModel->select(selectionModelIndex, QItemSelectionModel::Select);

        emit dataChanged(selectionModelIndex, selectionModelIndex, {static_cast<int>(SelectedRole)});
    }
    else
    {
        if (!m_selectionModel->isSelected(selectionModelIndex))
            return;

        clearDecorationSelection();
    }
}

void ComponentDecorationsModel::clearDecorationSelection()
{
    if (!m_selectionModel->hasSelection())
        return;

    auto selectedIndexes = m_selectionModel->selectedIndexes();
    m_selectionModel->clearSelection();

    for (const auto &selectedIndex : selectedIndexes)
        emit dataChanged(selectedIndex, selectedIndex, {static_cast<int>(SelectedRole)});
}

QVariant ComponentDecorationsModel::getByIndexAndRole(int indexRow, const QString &role) const
{
    return data(index(indexRow), roleNames().key(role.toUtf8(), DecorationStoreRole));
}

void ComponentDecorationsModel::setByIndexAndRole(int indexRow, const QVariant &value, const QString &role)
{
    setData(index(indexRow), value, roleNames().key(role.toUtf8(), DecorationStoreRole));
}

void ComponentDecorationsModel::onDecorationSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    bool isDecorationSelected = !selected.indexes().empty() && deselected.indexes().empty();
    emit decorationSelectionChanged(isDecorationSelected ? selected.indexes().at(0).row() : -1);
}

int ComponentDecorationsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return static_cast<int>(m_componentDecorations.size());
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
    case VisibleRole:
        return decoration->isDecorationVisible();
    case NameRole:
        return  decoration->decorationName();
    default:
        break;
    }

    return QVariant();
}

void ComponentDecorationsModel::moveDecoration(const QModelIndex &sourceIndex, const QModelIndex &destinationIndex)
{
    auto sourceRow = sourceIndex.row();
    auto destinationRow = destinationIndex.row();
    auto modelDestinationRow = destinationRow;
    //In case we move to next index, we shouldcreate special Qt index, as this is model move specific
    if(destinationRow == sourceRow + 1)
        ++modelDestinationRow;

    beginMoveRows(sourceIndex.parent(), sourceRow, sourceRow, destinationIndex.parent(), modelDestinationRow);
    std::swap(m_componentDecorations.at(static_cast<size_t>(sourceRow)),
              m_componentDecorations.at(static_cast<size_t>(destinationRow)));
    endMoveRows();
}

bool ComponentDecorationsModel::setData(const QModelIndex &modelIndex, const QVariant &value, int role)
{
    if (!modelIndex.isValid() && value.isValid())
        return false;

    const auto &decoration = m_componentDecorations.at(static_cast<size_t>(modelIndex.row()));

    switch (role) {
    case SelectedRole:
        setDecorationSelection(modelIndex, value.toBool());
        return true;
    case ZOrderRole:
        moveDecoration(modelIndex, index(value.toInt()));
        return true;
    case VisibleRole:
        decoration->setDecorationVisible(value.toBool());
        emit dataChanged(modelIndex, modelIndex, {static_cast<int>(role)});
        return true;
    case NameRole:
        decoration->setDecorationName(value.toString());
        emit dataChanged(modelIndex, modelIndex, {static_cast<int>(role)});
        return true;
    default:
        qWarning() << QStringLiteral("Component decoration role is read only");
        return false;
    }
}

QHash<int, QByteArray> ComponentDecorationsModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {TypeRole, QByteArrayLiteral("typeRole")},
        {DecorationStoreRole, QByteArrayLiteral("decorationStoreRole")},
        {SelectedRole, QByteArrayLiteral("selectedRole")},
        {ZOrderRole, QByteArrayLiteral("zOrderRole")},
        {VisibleRole, QByteArrayLiteral("visibleRole")},
        {NameRole, QByteArrayLiteral("nameRole")},
    };
    return roles;
}
