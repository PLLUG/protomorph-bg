#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <QObject>

class Enums
{
    Q_GADGET

public:
    enum class BackgroundType
    {
        BACKGROUND_COLOR,
        BACKGROUND_GRADIENT,
        BACKGROUND_IMAGE,
        BACKGROUND_NONE
    };
    Q_ENUM(BackgroundType)

    enum class ComponentType
    {
        COMPONENT_BOARD,
        COMPONENT_BOX,
        COMPONENT_CARD,
        COMPONENT_TILE,
        COMPONENT_TEMPLATE
    };
    Q_ENUM(ComponentType)

    enum class DecorationType
    {
        DECORATION_GAME_ICON,
        DECORATION_IMAGE,
        DECORATION_SHAPE,
        DECORATION_TEXT,
        DECORATION_GAME_ICON_TEMPLATE,
        DECORATION_IMAGE_TEMPLATE,
        DECORATION_SHAPE_TEMPLATE,
        DECORATION_TEXT_TEMPLATE,
        DECORATION_NONE
    };
    Q_ENUM(DecorationType)
};

Q_DECLARE_METATYPE(Enums::BackgroundType)
Q_DECLARE_METATYPE(Enums::ComponentType)
Q_DECLARE_METATYPE(Enums::DecorationType)


#endif // ENUMS_HPP
