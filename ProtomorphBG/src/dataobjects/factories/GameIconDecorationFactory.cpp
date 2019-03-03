#include "src/dataobjects/factories/GameIconDecorationFactory.hpp"

#include "src/store/GameIconDecorationStore.hpp"

using namespace Dataobject;

GameIconDecorationFactory::GameIconDecorationFactory() = default;
GameIconDecorationFactory::~GameIconDecorationFactory() = default;

std::unique_ptr<ComponentDecoration> GameIconDecorationFactory::createDecoration(const QVariantMap &decorationData) const
{
    auto gameIconDecoration = std::make_unique<GameIconDecoration>();
    gameIconDecoration->iconData = decorationData.value(QStringLiteral("iconData")).toString();
    gameIconDecoration->iconName = decorationData.value(QStringLiteral("iconName")).toString();
    return std::move(gameIconDecoration);
}

std::unique_ptr<DecorationStore> GameIconDecorationFactory::createDecorationStore(ComponentDecoration &componentDecoraton)
{
    auto gameIconDecoration = static_cast<GameIconDecoration &>(componentDecoraton);
    return std::make_unique<GameIconDecorationStore>(gameIconDecoration);
}
