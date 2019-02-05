#ifndef COMPONENTDECORATI_HPP
#define COMPONENTDECORATI_HPP

#include "src/constants/Enums.hpp"

#include <QColor>
#include <QRectF>
#include <QVariant>

namespace Dataobject {
struct ComponentDecoration
{
    QVariant decorationData;
    QRectF boundingRect;
    QColor backgroundColor;
    QColor foregroundColor;
    Enums::DecorationType type;
};
}

#endif // COMPONENTDECORATI_HPP
