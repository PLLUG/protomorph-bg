#ifndef PROTOTYPEPROJECTSMODEL_HPP
#define PROTOTYPEPROJECTSMODEL_HPP

#include <dataobjects/Project.hpp>

#include <QAbstractListModel>

#include <vector>

class PrototypeProjectsModel : public QAbstractListModel
{
    Q_OBJECT

    enum ProjectRoles {
        NameRole = Qt::UserRole + 1,
        DescriptionRole,
        CoverRole,
        DateCreatedRole,
        DateUpdatedRole
    };

public:
    explicit PrototypeProjectsModel(QObject *parent = nullptr);
    ~PrototypeProjectsModel() override;

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void addProject(QVariantMap projectObject);
    void deleteProject(int projectIndex);

private:
    std::vector<Project> m_projects;
};

#endif // PROTOTYPEPROJECTSMODEL_HPP
