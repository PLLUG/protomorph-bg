#ifndef GAMEICONSLISTMODEL_HPP
#define GAMEICONSLISTMODEL_HPP

#include <QAbstractListModel>

class GameIconsListModel : public QAbstractListModel
{
    Q_OBJECT

    enum GameIconsRole {
        IconUrlRole = Qt::UserRole + 1,
    };

public:
    explicit GameIconsListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    static QStringList m_gameIcons;
};

#endif // GAMEICONSLISTMODEL_HPP
