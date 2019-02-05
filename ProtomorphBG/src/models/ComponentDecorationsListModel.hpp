#ifndef COMPONENTDECORATIONSLISTMODEL_HPP
#define COMPONENTDECORATIONSLISTMODEL_HPP

#include <QAbstractListModel>

#include <vector>

namespace Dataobject {
class ComponentDecoration;
}


class ComponentDecorationsListModel : public QAbstractListModel
{
    Q_OBJECT
    enum ComponentDecorationRole {
        TypeRole = Qt::UserRole + 1,
        BoundingRectRole,
        BackgroundRole,
        ForegroundRole,
        DecorationDataRole
    };
public:
    explicit ComponentDecorationsListModel(QObject *parent = nullptr);

private:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    std::vector<Dataobject::ComponentDecoration *> m_componentDecorations;
};

#endif // COMPONENTDECORATIONSLISTMODEL_HPP
