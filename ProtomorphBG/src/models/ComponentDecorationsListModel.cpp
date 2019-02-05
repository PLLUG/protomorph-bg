#include "ComponentDecorationsListModel.hpp"

#include "src/dataobjects/ComponentDecoration.hpp"

ComponentDecorationsListModel::ComponentDecorationsListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

int ComponentDecorationsListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return static_cast<int>(m_componentDecorations.size());
}

QVariant ComponentDecorationsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto decoration = m_componentDecorations.at(static_cast<size_t>(index.row()));

    switch (role) {
    case TypeRole:
        return static_cast<int>(decoration->type);
    case BoundingRectRole:
        return  decoration->boundingRect;
    case BackgroundRole:
        return decoration->backgroundColor;
    case ForegroundRole:
        return decoration->foregroundColor;
    case DecorationDataRole:
        return decoration->decorationData;
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> ComponentDecorationsListModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {TypeRole, QByteArrayLiteral("type")},
        {BoundingRectRole, QByteArrayLiteral("boundingRect")},
        {BackgroundRole, QByteArrayLiteral("background")},
        {ForegroundRole, QByteArrayLiteral("foreground")},
        {DecorationDataRole, QByteArrayLiteral("decorationData")},
    };
    return roles;
}
