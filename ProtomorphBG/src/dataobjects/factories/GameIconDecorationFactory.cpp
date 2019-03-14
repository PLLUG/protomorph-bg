#include "src/dataobjects/factories/GameIconDecorationFactory.hpp"

#include "src/store/GameIconDecorationStore.hpp"

GameIconDecorationFactory::GameIconDecorationFactory() = default;
GameIconDecorationFactory::~GameIconDecorationFactory() = default;

std::unique_ptr<DecorationComponent> GameIconDecorationFactory::createDecoration(const QVariantMap &decorationData) const
{
    auto gameIconDecoration = std::make_unique<GameIconDecoration>();
    gameIconDecoration->iconData = decorationData.value(QStringLiteral("iconData")).toByteArray();
    gameIconDecoration->iconName = decorationData.value(QStringLiteral("iconName")).toString();
    gameIconDecoration->foregroundColor = decorationData.value(QStringLiteral("foregroundColor")).value<QColor>();
    return std::move(gameIconDecoration);
}

std::unique_ptr<DecorationStore> GameIconDecorationFactory::createDecorationStore(DecorationComponent &componentDecoraton)
{
    auto &gameIconDecoration = static_cast<GameIconDecoration &>(componentDecoraton);
    return std::make_unique<GameIconDecorationStore>(gameIconDecoration);
}
