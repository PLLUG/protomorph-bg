#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "src/constants/Enums.hpp"
#include "src/dataobjects/IVariantSerializable.hpp"

#include <QBrush>
#include <QVariantMap>

struct Backround : public IVariantSerializable
{
    Enums::BackgroundType type{Enums::BackgroundType::BACKGROUND_NONE};
    QColor color;
    QString imagePath;
    QGradient::Preset gradientPreset;

    virtual void fromVariant(const QVariant &value) override
    {
        auto backgroundQmlProp = value.toMap();
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
            color = QColor{Qt::transparent};
            gradientPreset = static_cast<QGradient::Preset>(-1);
            imagePath = QString{};
            break;
        }
    }

    virtual QVariant toVariant() const override
    {
        switch(type)
        {
        case Enums::BackgroundType::BACKGROUND_COLOR:
            return color;
        case Enums::BackgroundType::BACKGROUND_GRADIENT:
            return static_cast<int>(gradientPreset);
        case Enums::BackgroundType::BACKGROUND_IMAGE:
            return imagePath;
        case Enums::BackgroundType::BACKGROUND_NONE:
            return QColor{Qt::transparent};
        }

        return QColor{Qt::transparent};
    }
};

#endif // BACKGROUND_HPP
