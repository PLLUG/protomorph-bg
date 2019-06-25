#ifndef IVARIANTSERIALIZABLE_HPP
#define IVARIANTSERIALIZABLE_HPP

#include <QVariant>

class IVariantSerializable
{
public:
    virtual ~IVariantSerializable() = default;

    virtual void fromVariant(const QVariant &value) = 0;
    virtual QVariant toVariant() const = 0;
};

#endif // IVARIANTSERIALIZABLE_HPP
