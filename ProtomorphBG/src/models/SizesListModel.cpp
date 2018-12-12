#include "SizesListModel.hpp"

#include "CardSizesConstants.hpp"

#include <QGuiApplication>
#include <QScreen>
#include <QSizeF>

SizesListModel::SizesListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int SizesListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return static_cast<int>(sizes.size());
}

QVariant SizesListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto cardSize = sizes.at(static_cast<size_t>(index.row()));

    if (role == SizeAsTextRole)
        return QString("%1 x %2").arg(cardSize.width).arg(cardSize.height);


    return QVariant();
}

QHash<int, QByteArray> SizesListModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {SizeAsTextRole, "sizeAsString"}
    };
    return roles;
}

QVariant SizesListModel::sizeByIndex(int index)
{
    auto desctop = qGuiApp->screens().at(0);
    auto cardSize = sizes.at(static_cast<size_t>(index));
    auto logDotsPerInc = std::ceil(desctop->logicalDotsPerInch()  / 25.4);
    return QVariant::fromValue(QSizeF(std::round(logDotsPerInc * cardSize.width),
                                      std::round(logDotsPerInc * cardSize.height)));
}
