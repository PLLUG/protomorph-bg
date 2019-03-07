#include "src/store/DecorationStore.hpp"

DecorationStore::DecorationStore(QObject *parent) : QFStore{parent}{}

DecorationStore::~DecorationStore() = default;

bool DecorationStore::isSelected() const
{
    return m_isSelected;
}

void DecorationStore::setSelected(bool isSelected)
{
    if (m_isSelected == isSelected)
        return;

    m_isSelected = isSelected;
    emit selectionChanged(m_isSelected);
}
