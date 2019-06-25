#ifndef COMPONENTDECORATI_HPP
#define COMPONENTDECORATI_HPP

#include "src/dataobjects/BasicComponent.hpp"
#include "src/constants/Enums.hpp"

#include <QColor>
#include <QRectF>
#include <QString>
#include <QVariant>

struct DecorationComponent: public BasicComponent
{
    QColor backgroundColor;
    QColor foregroundColor;
    Enums::DecorationType type;
};

struct GameIconDecoration: public DecorationComponent
{
    QString iconName;
    QByteArray iconData;
};

#endif // COMPONENTDECORATI_HPP
