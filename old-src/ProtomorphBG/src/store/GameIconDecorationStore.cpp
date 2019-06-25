#include "src/store/GameIconDecorationStore.hpp"

#include "src/dataobjects/DecorationComponent.hpp"

GameIconDecorationStore::GameIconDecorationStore(GameIconDecoration &gameIconDecoration, QObject *parent)
    : DecorationStore{parent}
    , m_gameIconDecoration{gameIconDecoration}
{
    setDecorationName(m_gameIconDecoration.iconName);
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

void GameIconDecorationStore::setDecorationPosition(QPointF decorationPosition)
{
    if (decorationPosition == m_gameIconDecoration.boundingRect.topLeft())
        return;

    m_gameIconDecoration.boundingRect.moveTopLeft(decorationPosition);
    emit decorationPositionChanged(m_gameIconDecoration.boundingRect.topLeft());
}

void GameIconDecorationStore::setDecorationSize(QSizeF decorationSize)
{
    if (decorationSize == m_gameIconDecoration.boundingRect.size())
        return;

    m_gameIconDecoration.boundingRect.setSize(decorationSize);
    emit decorationSizeChanged(m_gameIconDecoration.boundingRect.size());
}

void GameIconDecorationStore::setBackgroundColor(QColor backgroundColor)
{
    if (backgroundColor == m_gameIconDecoration.backgroundColor)
        return;

    m_gameIconDecoration.backgroundColor = backgroundColor;
    emit backgroundColorChanged(m_gameIconDecoration.backgroundColor);
}

void GameIconDecorationStore::setForegroundColor(QColor foregroundColor)
{
    if (foregroundColor == m_gameIconDecoration.foregroundColor)
        return;

    m_gameIconDecoration.foregroundColor = foregroundColor;
    emit foregroundColorChanged(m_gameIconDecoration.foregroundColor);
}
