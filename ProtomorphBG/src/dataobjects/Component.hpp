#ifndef COMPONENTOBJECT_HPP
#define COMPONENTOBJECT_HPP

#include "src/constants/Enums.hpp"
#include "src/dataobjects/Background.hpp"
#include "src/dataobjects/ComponentDecoration.hpp"

#include <QSizeF>

#include <vector>

namespace Dataobject {
struct Component
{
    Enums::ComponentType type;
    std::vector<ComponentDecoration *> componentDecorations;
    Backround background;
    QSizeF sizeInMM;
    QSizeF sizeInPixels;
};
}
#endif // COMPONENTOBJECT_HPP
