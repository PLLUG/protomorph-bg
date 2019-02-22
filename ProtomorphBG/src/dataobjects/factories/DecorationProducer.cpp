#include "src/dataobjects/factories/DecorationProducer.hpp"

#include "src/dataobjects/factories/GameIconDecorationFactory.hpp"

DecorationProducer::DecorationProducer()
{
    initDecorationFactories();
}

DecorationProducer::~DecorationProducer() = default;

void DecorationProducer::initDecorationFactories()
{
    m_decorationFactories[Enums::DecorationType::DECORATION_GAME_ICON] = std::make_unique<Dataobject::GameIconDecorationFactory>();
}

std::unique_ptr<Dataobject::ComponentDecoration> DecorationProducer::createDecoration(Enums::DecorationType decorationType, const QVariantMap &decorationData) const
{
    auto decorationFactoryIterator = m_decorationFactories.find(decorationType);
    if (decorationFactoryIterator == m_decorationFactories.end())
        return nullptr;

    auto &decorationFactory = decorationFactoryIterator->second;
    return decorationFactory->createDecoration(decorationData);
}
