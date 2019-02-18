#ifndef COMPONENTDECORATI_HPP
#define COMPONENTDECORATI_HPP

#include "src/constants/Enums.hpp"

#include <QColor>
#include <QRectF>
#include <QString>
#include <QVariant>

namespace Dataobject {
struct ComponentDecoration
{
    QRectF boundingRect;
    QColor backgroundColor;
    QColor foregroundColor;
    Enums::DecorationType type;
};

struct GameIconDecoration: public ComponentDecoration
{
    QString iconName;
    QString iconData;
};
}

#endif // COMPONENTDECORATI_HPP
