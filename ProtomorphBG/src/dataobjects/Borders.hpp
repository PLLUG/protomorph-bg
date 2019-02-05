#ifndef BORDERS_HPP
#define BORDERS_HPP

#include <QColor>
#include <QVariantMap>

namespace Dataobject {
struct Borders {
    QColor color;
    double width;

    void fillFromQmlType(const QVariantMap &borderProp)
    {
        auto newColor = borderProp.value(QStringLiteral("borderColor")).value<QColor>();
        if (newColor != color)
            color = newColor;

        auto newWidth = borderProp.value(QStringLiteral("borderWidthInPixels")).value<double>();
        if(!qFuzzyCompare(newWidth, width))
            width = newWidth;
    }
};
}

#endif // BORDERS_HPP
