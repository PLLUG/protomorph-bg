#ifndef COMPONENTDECORATIONSLISTMODEL_HPP
#define COMPONENTDECORATIONSLISTMODEL_HPP

#include <QAbstractListModel>

#include <vector>

class DecorationStore;

class ComponentDecorationsListModel : public QAbstractListModel
{
    Q_OBJECT
    enum ComponentDecorationRole {
        TypeRole = Qt::UserRole + 1,
        DecorationStoreRole,
        SelectedRole,
        ZOrderRole
    };
public:
    explicit ComponentDecorationsListModel(QObject *parent = nullptr);

private:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    std::vector<std::unique_ptr<DecorationStore>> m_componentDecorations;
};

#endif // COMPONENTDECORATIONSLISTMODEL_HPP
