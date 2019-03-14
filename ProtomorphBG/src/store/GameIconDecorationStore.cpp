#include "src/store/GameIconDecorationStore.hpp"

#include "src/dataobjects/DecorationComponent.hpp"

GameIconDecorationStore::GameIconDecorationStore(GameIconDecoration &gameIconDecoration, QObject *parent)
    : DecorationStore{parent}
    , m_gameIconDecoration{gameIconDecoration}
{
}

GameIconDecorationStore::~GameIconDecorationStore() = default;

Enums::DecorationType GameIconDecorationStore::decorationType() const
{
    return Enums::DecorationType::DECORATION_GAME_ICON;
}

QColor GameIconDecorationStore::backgroundColor() const
{
    return m_gameIconDecoration.backgroundColor;
}

QColor GameIconDecorationStore::foregroundColor() const
{
    return m_gameIconDecoration.foregroundColor;
}

QPointF GameIconDecorationStore::decorationPosition() const
{
    return m_gameIconDecoration.boundingRect.topLeft();
}

QSizeF GameIconDecorationStore::decorationSize() const
{
    return m_gameIconDecoration.boundingRect.size();
}

QByteArray GameIconDecorationStore::iconData() const
{
    return  m_gameIconDecoration.iconData;
}

QString GameIconDecorationStore::iconName() const
{
    return  m_gameIconDecoration.iconName;
}
