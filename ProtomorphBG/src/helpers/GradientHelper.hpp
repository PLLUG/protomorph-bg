#ifndef GRADIENTHELPER_HPP
#define GRADIENTHELPER_HPP

#include <QGradient>
#include <QString>


namespace Helper {
QGradient::Preset getPresetGradient(const QString &pesetName);
QString getPresetGradientString(QGradient::Preset pesetEnum);
QStringList getPresetGradientsList();
}

#endif // GRADIENTHELPER_HPP
