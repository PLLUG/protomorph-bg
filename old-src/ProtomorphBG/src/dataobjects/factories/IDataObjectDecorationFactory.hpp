#ifndef IDATAOBJECTFACTORY_HPP
#define IDATAOBJECTFACTORY_HPP

#include "src/dataobjects/DecorationComponent.hpp"

#include <QVariantMap>

#include <memory>

class IDataObjectDecorationFactory
{
public:
    virtual ~IDataObjectDecorationFactory() = default;

    virtual std::unique_ptr<DecorationComponent> createDecoration(const QVariantMap &decorationData) const = 0;
};

#endif // IDATAOBJECTFACTORY_HPP
