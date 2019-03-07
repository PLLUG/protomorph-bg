#ifndef GAMEICONSFILTERMODEL_HPP
#define GAMEICONSFILTERMODEL_HPP

#include <QSortFilterProxyModel>

class GameIconsFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString searchPattern READ searchPattern WRITE setSearchPattern)
public:
    static GameIconsFilterModel *instance();
    QString searchPattern() const;

public slots:
    void setSearchPattern(QString searchPattern);

private:
    explicit GameIconsFilterModel(QObject *parent = nullptr);
    virtual ~GameIconsFilterModel() override;

    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

    QString m_searchPattern;
};

#endif // GAMEICONSFILTERMODEL_HPP
