#include "src/store/ComponentEditorStore.hpp"

ComponentEditorStore::ComponentEditorStore(QObject *parent)
    : QFStore{parent}
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
