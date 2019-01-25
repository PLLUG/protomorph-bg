#include "src/store/ComponentEditorStore.hpp"

using namespace Dataobject;

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

Enums::ComponentType ComponentEditorStore::componentType() const
{
    return m_component.type;
}

QVariantMap ComponentEditorStore::background() const
{
    return m_component.background.toQmlType();
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

void ComponentEditorStore::setComponentType(Enums::ComponentType componentType)
{
    if (m_component.type == componentType)
        return;

    m_component.type = componentType;
    emit componentTypeChanged(m_component.type);
}

void ComponentEditorStore::setBackground(const QVariantMap &backgroundProp)
{
    m_component.background.fillFromQmlType(backgroundProp);
    emit backgroundChanged(m_component.background.toQmlType());
}
