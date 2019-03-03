#ifndef IDECORATIONSTOREFACTORY_HPP
#define IDECORATIONSTOREFACTORY_HPP

#include <memory>

#include "src/store/DecorationStore.hpp"

namespace Dataobject {
struct ComponentDecoration;
}

class IDecorationStoreFactory
{
public:
    virtual ~IDecorationStoreFactory() = default;

    virtual std::unique_ptr<DecorationStore> createDecorationStore(Dataobject::ComponentDecoration &componentDecoraton) = 0;
};

#endif // IDECORATIONSTOREFACTORY_HPP
