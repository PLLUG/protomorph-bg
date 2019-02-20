#include "src/dataobjects/factories/GameIconDecorationFactory.hpp"

#include "src/store/GameIconDecorationStore.hpp"

using namespace Dataobject;

GameIconDecorationFactory::GameIconDecorationFactory() = default;
GameIconDecorationFactory::~GameIconDecorationFactory() = default;

std::unique_ptr<ComponentDecoration> GameIconDecorationFactory::createDecoration(const QVariantMap &decorationData) const
{
    Q_UNUSED(decorationData)
    return std::make_unique<GameIconDecoration>();
}

std::unique_ptr<DecorationStore> GameIconDecorationFactory::createDecorationStore(ComponentDecoration &componentDecoraton)
{
    auto gameIconDecoration = static_cast<GameIconDecoration &>(componentDecoraton);
    return std::make_unique<GameIconDecorationStore>(gameIconDecoration);
}
