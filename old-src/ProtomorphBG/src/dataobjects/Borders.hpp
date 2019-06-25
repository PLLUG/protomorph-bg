#ifndef BORDERS_HPP
#define BORDERS_HPP

#include "IVariantSerializable.hpp"

#include <QColor>

const auto BORDER_COLOR_NAME = QStringLiteral("borderColor");
const auto BORDER_WIDTH_NAME = QStringLiteral("borderWidthInPixels");

struct Borders : public IVariantSerializable
{
    QColor color;
    double width;

    virtual void fromVariant(const QVariant &value) override
    {
        auto borderProp = value.toMap();
        auto newColor = borderProp.value(BORDER_COLOR_NAME).value<QColor>();
        if (newColor != color)
            color = newColor;

        auto newWidth = borderProp.value(BORDER_WIDTH_NAME).value<double>();
        if(!qFuzzyCompare(newWidth, width))
            width = newWidth;
    }

    virtual QVariant toVariant() const override
    {
        QVariantMap borderVariant {
            {BORDER_COLOR_NAME, color},
            {BORDER_WIDTH_NAME, width}
        };

        return borderVariant;
    }
};

#endif // BORDERS_HPP
