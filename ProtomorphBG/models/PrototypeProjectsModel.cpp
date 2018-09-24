#include "PrototypeProjectsModel.hpp"

PrototypeProjectsModel::PrototypeProjectsModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

PrototypeProjectsModel::~PrototypeProjectsModel() = default;

int PrototypeProjectsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return static_cast<int>(m_projects.size());
}

QVariant PrototypeProjectsModel::data(const QModelIndex &index, int role) const
{
    auto resultData = QVariant();
    if (!index.isValid())
        return resultData;

    auto rowIndex = static_cast<size_t>(index.row());

    switch (role)
    {
    case NameRole:
        resultData = QString::fromStdString(m_projects[rowIndex].name);
        break;
    case DescriptionRole:
        resultData = QString::fromStdString(m_projects[rowIndex].description);
        break;
    case CoverRole:
        resultData = QString::fromStdString(m_projects[rowIndex].coverImage);
        break;
    case DateCreatedRole:
        resultData = m_projects[rowIndex].created;
        break;
    case DateUpdatedRole:
        resultData = m_projects[rowIndex].updated;
        break;
    }

    return resultData;
}

QHash<int, QByteArray> PrototypeProjectsModel::roleNames() const
{
    static QHash<int, QByteArray> roles{
        {NameRole, "name"},
        {DescriptionRole, "description"},
        {CoverRole, "cover"},
        {DateCreatedRole, "dateCreated"},
        {DateUpdatedRole, "dateUpdated"}
    };

    return roles;
}

void PrototypeProjectsModel::addProject(QVariantMap projectObject)
{
    Q_UNUSED(projectObject)
    auto newProjectIndex = static_cast<int>(m_projects.size());
    beginInsertRows(index(newProjectIndex).parent(), newProjectIndex, newProjectIndex);

    m_projects.emplace_back(Project{});

    endInsertRows();
}

void PrototypeProjectsModel::deleteProject(int projectIndex)
{
    auto modelIndex = index(projectIndex);
    if (!modelIndex.isValid())
        return;

    beginRemoveRows(modelIndex.parent(), projectIndex, projectIndex);

    auto itemToRemove = std::begin(m_projects) + projectIndex;
    m_projects.erase(itemToRemove);

    endRemoveRows();
}
