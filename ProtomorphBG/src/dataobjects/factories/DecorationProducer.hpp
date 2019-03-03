#ifndef DECORATIONPRODUCER_HPP
#define DECORATIONPRODUCER_HPP

#include "src/constants/Enums.hpp"
#include "src/store/DecorationStore.hpp"

#include <memory>
#include <unordered_map>

namespace Dataobject {
struct ComponentDecoration;
class IDataObjectDecorationFactory;
}

class IDecorationStoreFactory;

class DecorationProducer
{
public:
    DecorationProducer();
    ~DecorationProducer();

    std::unique_ptr<Dataobject::ComponentDecoration> createDecoration(Enums::DecorationType decorationType, const QVariantMap &decorationData) const;
    std::unique_ptr<DecorationStore> createDecorationStore(Enums::DecorationType decorationType, Dataobject::ComponentDecoration &componentDecoration) const;

private:
    void initDecorationFactories();

    std::unordered_map<Enums::DecorationType, std::unique_ptr<Dataobject::IDataObjectDecorationFactory>> m_decorationFactories;
    std::unordered_map<Enums::DecorationType, std::unique_ptr<IDecorationStoreFactory>> m_decorationStoreFactories;
};

#endif // DECORATIONPRODUCER_HPP
