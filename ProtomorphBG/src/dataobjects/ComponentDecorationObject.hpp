#ifndef COMPONENTDECORATIONOBJECT_HPP
#define COMPONENTDECORATIONOBJECT_HPP

#include "src/constants/Enums.hpp"

#include <QRectF>


struct ComponentDecorationObject
{
    QRectF boundingRect;
    Enums::ComponentDecorationType decorationType;
};

#endif // COMPONENTDECORATIONOBJECT_HPP
