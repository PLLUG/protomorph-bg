#ifndef IDECORATIONSTOREFACTORY_HPP
#define IDECORATIONSTOREFACTORY_HPP

#include <src/dataobjects/ComponentDecoration.hpp>
#include "src/store/DecorationStore.hpp"

#include <memory>


class IDecorationStoreFactory
{
public:
    virtual ~IDecorationStoreFactory() = default;

    virtual std::unique_ptr<DecorationStore> createDecorationStore(Dataobject::ComponentDecoration &componentDecoraton) = 0;
};

#endif // IDECORATIONSTOREFACTORY_HPP
