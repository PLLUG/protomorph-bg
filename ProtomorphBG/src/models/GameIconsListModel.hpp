#ifndef GAMEICONSLISTMODEL_HPP
#define GAMEICONSLISTMODEL_HPP

#include <QAbstractListModel>

#include <memory>
#include <vector>

class GameIconsListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum GameIconsRole {
        IconUrlRole = Qt::UserRole + 1,
        IconQmlUrlRole,
        IconNameRole,
        IconDataRole
    };

    struct GameIconProperties
    {
        QString name;
        QString data;
    };

    static GameIconsListModel *instance();

private:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    explicit GameIconsListModel(QObject *parent = nullptr);
    virtual ~GameIconsListModel() override;

    using GameIconsPropertiesVector = std::vector<std::unique_ptr<GameIconProperties>>;
    static GameIconsPropertiesVector m_gameIcons;
};

#endif // GAMEICONSLISTMODEL_HPP
