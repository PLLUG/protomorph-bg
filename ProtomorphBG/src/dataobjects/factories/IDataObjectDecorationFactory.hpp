#ifndef IDATAOBJECTFACTORY_HPP
#define IDATAOBJECTFACTORY_HPP

#include "src/dataobjects/ComponentDecoration.hpp"

#include <QVariantMap>

namespace Dataobject {
class IDataObjectDecorationFactory
{
public:
    virtual ~IDataObjectDecorationFactory() = default;

    virtual ComponentDecoration *createDecoration(const QVariantMap &decorationData) const = 0;
};
}

#endif // IDATAOBJECTFACTORY_HPP
