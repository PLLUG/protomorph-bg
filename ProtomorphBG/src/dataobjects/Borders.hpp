#ifndef BORDERS_HPP
#define BORDERS_HPP

#include <QColor>
#include <QVariantMap>

namespace Dataobject {
struct Borders {
    QColor color;
    double widthInMM;
    double widthInPixels;

    void fillFromQmlType(const QVariantMap &borderProp)
    {
        color = borderProp.value(QStringLiteral("borderColor")).value<QColor>();
        widthInPixels = borderProp.value(QStringLiteral("borderWidthInPixels")).value<double>();
    }

    QVariantMap toQmlType() const
    {
        QVariantMap borderProp;
        borderProp.insert(QStringLiteral("borderColor"), QVariant::fromValue(color));
        borderProp.insert(QStringLiteral("borderWidthInPixels"), QVariant::fromValue(widthInPixels));
        return borderProp;
    }

};
}

#endif // BORDERS_HPP
