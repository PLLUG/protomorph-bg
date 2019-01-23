#ifndef MEASUREMENTCONVERTERS_HPP
#define MEASUREMENTCONVERTERS_HPP

#include <QSizeF>

namespace Helper {
double roundToCorrectDoubleMM(double value, int nofDecimalPlaces = 1);
double fromMMToPixelsOnScreen(double value);
double fromPixelsOnScreenToMM(double value);
}

#endif // MEASUREMENTCONVERTERS_HPP
