#ifndef DECORATIONPRODUCER_HPP
#define DECORATIONPRODUCER_HPP

#include "src/constants/Enums.hpp"

#include <memory>
#include <unordered_map>

namespace Dataobject {
struct ComponentDecoration;
class IDataObjectDecorationFactory;
}

class DecorationProducer
{
public:
    DecorationProducer();
    ~DecorationProducer();

    std::unique_ptr<Dataobject::ComponentDecoration> createDecoration(Enums::DecorationType decorationType, const QVariantMap &decorationData) const;

private:
    void initDecorationFactories();

    std::unordered_map<Enums::DecorationType, std::unique_ptr<Dataobject::IDataObjectDecorationFactory>> m_decorationFactories;
};

#endif // DECORATIONPRODUCER_HPP
