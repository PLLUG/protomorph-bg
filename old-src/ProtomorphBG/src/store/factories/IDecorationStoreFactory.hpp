#ifndef IDECORATIONSTOREFACTORY_HPP
#define IDECORATIONSTOREFACTORY_HPP

#include <memory>

#include "src/store/DecorationStore.hpp"

struct DecorationComponent;

class IDecorationStoreFactory
{
public:
    virtual ~IDecorationStoreFactory() = default;

    virtual std::unique_ptr<DecorationStore> createDecorationStore(DecorationComponent &componentDecoraton) = 0;
};

#endif // IDECORATIONSTOREFACTORY_HPP
