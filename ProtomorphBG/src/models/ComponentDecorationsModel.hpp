#ifndef COMPONENTDECORATIONSLISTMODEL_HPP
#define COMPONENTDECORATIONSLISTMODEL_HPP

#include <QAbstractListModel>

#include <memory>
#include <vector>

class DecorationStore;
class QItemSelection;
class QItemSelectionModel;

class ComponentDecorationsModel : public QAbstractListModel
{
    Q_OBJECT

    enum ComponentDecorationRole {
        TypeRole = Qt::UserRole + 1,
        DecorationStoreRole,
        SelectedRole,
        ZOrderRole,
        VisibleRole,
        NameRole
    };

    using DecorationStorePtr = std::unique_ptr<DecorationStore>;

public:
    explicit ComponentDecorationsModel(QObject *parent = nullptr);
    ~ComponentDecorationsModel() override;

    void addDecorationStore(DecorationStorePtr &&newDecorationStore);

signals:
    void decorationSelectionChanged(int indexRow);

public slots:
    void removeDecoration(int indexRow);
    void clearDecorationSelection();
    QVariant getByIndexAndRole(int indexRow, const QString &role) const;
    void setByIndexAndRole(int indexRow, const QVariant &value, const QString &role);

private slots:
    void onDecorationSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    /*! From  QAbstractListModel */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex &modelIndex, const QVariant &value, int role) override;
    virtual QHash<int, QByteArray> roleNames() const override;

    /*! Own Methods */
    QVariant getTypedDecorationStore(const DecorationStorePtr &decorationStore) const;
    void setDecorationSelection(const QModelIndex &selectionModelIndex, bool shouldBeSelected);
    void moveDecoration(const QModelIndex &sourceIndex, const QModelIndex &destinationIndex);

    std::unique_ptr<QItemSelectionModel> m_selectionModel;
    std::vector<DecorationStorePtr> m_componentDecorations;
};

#endif // COMPONENTDECORATIONSLISTMODEL_HPP
