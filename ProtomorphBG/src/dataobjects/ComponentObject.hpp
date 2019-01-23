#ifndef COMPONENTOBJECT_HPP
#define COMPONENTOBJECT_HPP

#include "src/constants/Enums.hpp"
#include "src/dataobjects/ComponentDecorationObject.hpp"

#include <QBrush>
#include <QSizeF>

#include <vector>

struct ComponentObject
{
    QBrush backgroundBrush;
    QString backgroundImagePath;
    QSizeF sizeInMM;
    QSizeF sizeInPixels;
    Enums::ComponentType componentType;
    std::vector<ComponentDecorationObject *> componentDecorations;
};

#endif // COMPONENTOBJECT_HPP
