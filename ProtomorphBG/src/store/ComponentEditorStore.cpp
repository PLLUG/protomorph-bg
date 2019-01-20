#include "src/store/ComponentEditorStore.hpp"

ComponentEditorStore::ComponentEditorStore(QObject *parent)
    : QFStore{parent}
    , m_backgroundColor{}
    , m_width{}
    , m_height{}
{
}

double ComponentEditorStore::width() const
{
    return m_width;
}

double ComponentEditorStore::height() const
{
    return m_height;
}

QColor ComponentEditorStore::backgroundColor() const
{
    return m_backgroundColor;
}

void ComponentEditorStore::setWidth(double width)
{
    if (qFuzzyCompare(m_width, width))
        return;

    m_width = width;
    emit widthChanged(m_width);
}

void ComponentEditorStore::setHeight(double height)
{
    if (qFuzzyCompare(m_height, height))
        return;

    m_height = height;
    emit heightChanged(m_height);
}

void ComponentEditorStore::setBackgroundColor(const QColor &backgroundColor)
{
    if (m_backgroundColor == backgroundColor)
        return;

    m_backgroundColor = backgroundColor;
    emit backgroundColorChanged(m_backgroundColor);
}
