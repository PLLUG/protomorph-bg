#include "GameIconDecorationFactory.hpp"

using namespace Dataobject;

GameIconDecorationFactory::GameIconDecorationFactory() = default;
GameIconDecorationFactory::~GameIconDecorationFactory() = default;

ComponentDecoration *GameIconDecorationFactory::createDecoration(const QVariantMap &decorationData) const
{
    Q_UNUSED(decorationData)
    return new GameIconDecoration{};
}
