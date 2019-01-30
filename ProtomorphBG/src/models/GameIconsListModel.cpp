#include "src/models/GameIconsListModel.hpp"
#include "src/helpers/GameIconsSvgColorsHelper.hpp"

#include <QDirIterator>
#include <QDebug>

 const auto ICONS_DIR_PATH = QStringLiteral(":/gameicons");
 GameIconsListModel::GameIconsPropertiesVector GameIconsListModel::m_gameIcons;

GameIconsListModel::GameIconsListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    if (m_gameIcons.empty())
    {
        m_gameIcons.reserve(QDir{ICONS_DIR_PATH}.count());
        QDirIterator sourceDirIterator(ICONS_DIR_PATH);

        QFile file;
        while (sourceDirIterator.hasNext()) {
            file.setFileName(sourceDirIterator.next());
            if(file.open(QFile::ReadOnly))
            {
            auto svgData = Helper::modifyGameIconSvgColors(QString(file.readAll()));
            m_gameIcons.emplace_back(std::make_unique<GameIconsListModel::GameIconProperties>(GameIconsListModel::GameIconProperties{QFileInfo(file).baseName().replace('-', ' '), svgData}));
            file.close();
            }
        }
    }
}

GameIconsListModel::~GameIconsListModel() = default;

GameIconsListModel *GameIconsListModel::instance()
{
    static GameIconsListModel gameIconsListModelInstance;
    return &gameIconsListModelInstance;
}

int GameIconsListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    static auto rowCount = static_cast<int>(m_gameIcons.size());
    return rowCount;
}

QVariant GameIconsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto &iconProperties = m_gameIcons.at(static_cast<size_t>(index.row()));

    switch(role)
    {
    case IconNameRole:
        return iconProperties->name.toUpper();
    case IconDataRole:
        return iconProperties->data;
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> GameIconsListModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {IconUrlRole, "iconUrlRole"},
        {IconQmlUrlRole, "iconQmlUrlRole"},
        {IconNameRole, "iconNameRole"},
        {IconDataRole, "iconDataRole"},
    };
    return roles;
}
