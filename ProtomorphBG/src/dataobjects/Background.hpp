#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "src/constants/Enums.hpp"

#include <QBrush>
#include <QVariantMap>

namespace Dataobject {
struct Backround
{
    Enums::BackgroundType type{Enums::BackgroundType::BACKGROUND_NONE};
    QColor color;
    QString imagePath;
    QGradient::Preset gradientPreset;

    void fillFromQmlType(const QVariantMap &backgroundQmlProp)
    {
        type = backgroundQmlProp.value(QStringLiteral("type")).value<Enums::BackgroundType>();
        switch(type) {
        case Enums::BackgroundType::BACKGROUND_COLOR:
            color = backgroundQmlProp.value(QStringLiteral("value")).value<QColor>();
            break;
        case Enums::BackgroundType::BACKGROUND_GRADIENT:
            gradientPreset = backgroundQmlProp.value(QStringLiteral("value")).value<QGradient::Preset>();
            break;
        case Enums::BackgroundType::BACKGROUND_IMAGE:
            imagePath = backgroundQmlProp.value(QStringLiteral("value")).value<QString>();
            break;
        case Enums::BackgroundType::BACKGROUND_NONE:
        default:
            color = QColor{};
            gradientPreset = static_cast<QGradient::Preset>(-1);
            imagePath = QString{};
            break;
        }
    }

    QVariantMap toQmlType() const
    {
        QVariantMap bacgroundProp;
        bacgroundProp.insert(QStringLiteral("type"), QVariant::fromValue(static_cast<int>(type)));

        switch(type) {
        case Enums::BackgroundType::BACKGROUND_COLOR:
            bacgroundProp.insert(QStringLiteral("value"), QVariant::fromValue(color));
            break;
        case Enums::BackgroundType::BACKGROUND_GRADIENT:
            bacgroundProp.insert(QStringLiteral("value"), QVariant::fromValue(static_cast<int>(gradientPreset)));
            break;
        case Enums::BackgroundType::BACKGROUND_IMAGE:
            bacgroundProp.insert(QStringLiteral("value"), QVariant::fromValue(imagePath));
            break;
        case Enums::BackgroundType::BACKGROUND_NONE:
        default:
            break;
        }

        return bacgroundProp;
    }
};
}
#endif // BACKGROUND_HPP
