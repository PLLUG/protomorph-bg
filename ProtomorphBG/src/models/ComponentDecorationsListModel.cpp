#include "ComponentDecorationsListModel.hpp"

#include "src/store/DecorationStore.hpp"

ComponentDecorationsListModel::ComponentDecorationsListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

int ComponentDecorationsListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return static_cast<int>(m_componentDecorations.size());
}

QVariant ComponentDecorationsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto indexRow = index.row();
    const auto &decoration = m_componentDecorations.at(static_cast<size_t>(indexRow));

    switch (role) {
    case TypeRole:
        return static_cast<int>(decoration->decorationType());
    case DecorationStoreRole:
        return QVariant::fromValue(decoration.get());
    case SelectedRole:
        return decoration->isSelected();
    case ZOrderRole:
        return indexRow;
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> ComponentDecorationsListModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {TypeRole, QByteArrayLiteral("type")},
        {DecorationStoreRole, QByteArrayLiteral("decorationStore")},
        {SelectedRole, QByteArrayLiteral("selected")},
        {ZOrderRole, QByteArrayLiteral("zOrder")},
    };
    return roles;
}
