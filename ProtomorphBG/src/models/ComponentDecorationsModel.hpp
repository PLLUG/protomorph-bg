#ifndef COMPONENTDECORATIONSLISTMODEL_HPP
#define COMPONENTDECORATIONSLISTMODEL_HPP

#include <QAbstractListModel>

#include <vector>

class DecorationStore;

class ComponentDecorationsModel : public QAbstractListModel
{
    Q_OBJECT

    enum ComponentDecorationRole {
        TypeRole = Qt::UserRole + 1,
        DecorationStoreRole,
        SelectedRole,
        ZOrderRole
    };

    using DecorationStorePtr = std::unique_ptr<DecorationStore>;

public:
    explicit ComponentDecorationsModel(QObject *parent = nullptr);
    ~ComponentDecorationsModel() override;

    void addDecorationStore(DecorationStorePtr &&newDecorationStore);
    void removeDecorationStore(int index);

private:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    QVariant getTypedDecorationStore(const DecorationStorePtr &decorationStore) const;

    std::vector<DecorationStorePtr> m_componentDecorations;
};

#endif // COMPONENTDECORATIONSLISTMODEL_HPP
