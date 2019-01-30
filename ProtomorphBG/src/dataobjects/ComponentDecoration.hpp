#ifndef COMPONENTDECORATI_HPP
#define COMPONENTDECORATI_HPP

#include "src/constants/Enums.hpp"

#include <QColor>
#include <QRectF>

namespace Dataobject {
struct ComponentDecoration
{
    QRectF boundingRect;
    qreal rotationAngle;
    Enums::DecorationType type;
};

struct GameIconDecoration : public ComponentDecoration {
    QString gameIconData;
    QColor fillColor;
};
}

#endif // COMPONENTDECORATI_HPP
