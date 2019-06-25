#ifndef GRADIENTHELPER_HPP
#define GRADIENTHELPER_HPP

#include <QGradient>
#include <QString>


namespace Helper {
QGradient::Preset getPresetGradient(const QString &presetName);
QString getPresetGradientString(QGradient::Preset presetEnum);
QStringList getPresetGradientsList();
}

#endif // GRADIENTHELPER_HPP
