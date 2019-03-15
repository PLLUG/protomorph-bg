#ifndef COMPONENTDECORATIONSLISTMODEL_HPP
#define COMPONENTDECORATIONSLISTMODEL_HPP

#include <QAbstractListModel>

#include <memory>
#include <vector>

class DecorationStore;
class QItemSelectionModel;

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

public slots:
    void removeDecorationStore(int indexRow);

    void setDecorationSelection(int indexRow);
    void clearDecorationSelection();

private:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    QVariant getTypedDecorationStore(const DecorationStorePtr &decorationStore) const;

    std::unique_ptr<QItemSelectionModel> m_selectionModel;
    std::vector<DecorationStorePtr> m_componentDecorations;
    void clearDecorationSelectionAndNotify();
};

#endif // COMPONENTDECORATIONSLISTMODEL_HPP
