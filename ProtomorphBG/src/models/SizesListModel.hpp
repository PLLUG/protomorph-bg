#ifndef SIZESLISTMODEL_HPP
#define SIZESLISTMODEL_HPP

#include <QAbstractListModel>

class SizesListModel: public QAbstractListModel
{
    Q_OBJECT

    enum SizesRole {
        SizeAsTextRole = Qt::UserRole + 1,
    };

public:
    explicit SizesListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    QVariant sizeByIndex(int index);
};

#endif // SIZESLISTMODEL_HPP
