#include "src/models/GameIconsListModel.hpp"

#include <QDirIterator>
#include <QDebug>

const auto ICONS_DIR_PATH = QStringLiteral(":/gameicons");

GameIconsListModel::GameIconsListModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_gameIcons.reserve(QDir{ICONS_DIR_PATH}.count());
    QDirIterator sourceDirIterator(ICONS_DIR_PATH);

    QFile file;
    auto fileInfo = QFileInfo{};
    while (sourceDirIterator.hasNext())
    {
        file.setFileName(sourceDirIterator.next());

        if(file.open(QFile::ReadOnly))
        {
            fileInfo.setFile(file);
            auto svgData = file.readAll();
            auto svgName = fileInfo.baseName().replace('-', ' ');
            auto svgPath = fileInfo.filePath();
            auto svgQmlPath = QStringLiteral("qrc%1").arg(svgPath);
            m_gameIcons.emplace_back(std::make_unique<GameIconsListModel::GameIconProperties>(GameIconsListModel::GameIconProperties{svgData, svgName, svgPath, svgQmlPath}));
            file.close();
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
    case IconUrlRole:
        return iconProperties->url;
    case IconQmlUrlRole:
        return iconProperties->qmlUrl;
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> GameIconsListModel::roleNames() const
{
    static const auto roles = QHash<int, QByteArray>{
        {IconUrlRole, QByteArrayLiteral("iconUrlRole")},
        {IconQmlUrlRole, QByteArrayLiteral("iconQmlUrlRole")},
        {IconNameRole, QByteArrayLiteral("iconNameRole")},
        {IconDataRole, QByteArrayLiteral("iconDataRole")},
    };
    return roles;
}
