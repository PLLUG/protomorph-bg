#include "src/store/ComponentEditorStore.hpp"

ComponentEditorStore::ComponentEditorStore(QObject *parent)
    : QFStore{parent}
{
}

double ComponentEditorStore::width() const
{
    return m_component.sizeInPixels.width();
}

double ComponentEditorStore::height() const
{
    return m_component.sizeInPixels.height();
}

QColor ComponentEditorStore::backgroundColor() const
{
    return m_component.backgroundBrush.color();
}

QString ComponentEditorStore::backgroundImagePath() const
{
    return m_component.backgroundImagePath;
}

Enums::ComponentType ComponentEditorStore::componentType() const
{
    return m_component.componentType;
}

void ComponentEditorStore::setWidth(double width)
{
    if (qFuzzyCompare(m_component.sizeInPixels.width(), width))
        return;

    m_component.sizeInPixels.setWidth(width);
    emit widthChanged(m_component.sizeInPixels.width());
}

void ComponentEditorStore::setHeight(double height)
{
    if (qFuzzyCompare(m_component.sizeInPixels.height(), height))
        return;

    m_component.sizeInPixels.setHeight(height);
    emit heightChanged(m_component.sizeInPixels.height());
}

void ComponentEditorStore::setBackgroundColor(const QColor &backgroundColor)
{
    if (m_component.backgroundBrush.color() == backgroundColor)
        return;

    m_component.backgroundBrush.setColor(backgroundColor);
    emit backgroundColorChanged(m_component.backgroundBrush.color());
}

void ComponentEditorStore::setBackgroundImagePath(const QString &backgroundImage)
{
    if (m_component.backgroundImagePath == backgroundImage)
        return;

    m_component.backgroundImagePath = backgroundImage;
    emit backgroundImagePathChanged(m_component.backgroundImagePath);
}

void ComponentEditorStore::setComponentType(Enums::ComponentType componentType)
{
    if (m_component.componentType == componentType)
        return;

    m_component.componentType = componentType;
    emit componentTypeChanged(m_component.componentType);
}
