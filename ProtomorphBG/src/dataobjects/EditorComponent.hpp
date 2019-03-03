#ifndef COMPONENTOBJECT_HPP
#define COMPONENTOBJECT_HPP

#include "src/constants/Enums.hpp"
#include "src/dataobjects/Background.hpp"
#include "src/dataobjects/Borders.hpp"
#include "src/dataobjects/ComponentDecoration.hpp"

#include <QSizeF>

#include <memory>
#include <vector>

namespace Dataobject {
struct EditorComponent
{
    using Decorations = std::vector<std::unique_ptr<ComponentDecoration>>;

    Decorations componentDecorations;
    Backround background;
    Borders borders;
    QSizeF size;
    Enums::ComponentType type;
};
}
#endif // COMPONENTOBJECT_HPP
