#ifndef COMPONENTDECORATI_HPP
#define COMPONENTDECORATI_HPP

#include "src/constants/Enums.hpp"

#include <QRectF>

namespace Dataobject {
struct ComponentDecoration
{
    Enums::DecorationType type;
    QRectF boundingRect;
};
}

#endif // COMPONENTDECORATI_HPP
