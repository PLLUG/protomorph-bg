#ifndef DECORATIONPRODUCER_HPP
#define DECORATIONPRODUCER_HPP

#include "src/constants/Enums.hpp"
#include "src/store/DecorationStore.hpp"

#include <memory>
#include <unordered_map>

struct DecorationComponent;
class IDataObjectDecorationFactory;

class IDecorationStoreFactory;

class DecorationProducer
{
public:
    DecorationProducer();
    ~DecorationProducer();

    std::unique_ptr<DecorationComponent> createDecoration(Enums::DecorationType decorationType, const QVariantMap &decorationData) const;
    std::unique_ptr<DecorationStore> createDecorationStore(Enums::DecorationType decorationType, DecorationComponent &componentDecoration) const;

private:
    void initDecorationFactories();

    std::unordered_map<Enums::DecorationType, std::shared_ptr<IDataObjectDecorationFactory>> m_decorationFactories;
    std::unordered_map<Enums::DecorationType, std::shared_ptr<IDecorationStoreFactory>> m_decorationStoreFactories;
};

#endif // DECORATIONPRODUCER_HPP
