#include "src/store/DecorationStore.hpp"

DecorationStore::DecorationStore(QObject *parent)
    : QFStore{parent}
{
    m_metadata.isVisible = true;
}

DecorationStore::~DecorationStore() = default;
