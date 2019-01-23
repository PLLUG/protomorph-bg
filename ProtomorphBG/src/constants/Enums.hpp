#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <QObject>

class Enums
{
    Q_GADGET

public:
    enum class ComponentType
    {
        BOARD,
        BOX,
        CARD,
        TILE
    };
    Q_ENUM(ComponentType)

    enum class ComponentDecorationType
    {
        ICON,
        IMAGE,
        SHAPE,
        TEXT
    };
    Q_ENUM(ComponentDecorationType)
};

Q_DECLARE_METATYPE(Enums::ComponentType)
Q_DECLARE_METATYPE(Enums::ComponentDecorationType)


#endif // ENUMS_HPP
