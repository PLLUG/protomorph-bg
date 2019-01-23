#ifndef MEASUREMENTCONVERTERS_HPP
#define MEASUREMENTCONVERTERS_HPP

#include <QSizeF>

namespace Helper {
double roundToNDecimalPlaces(double value, int nofDecimalPlaces = 1);
double roundToCorrectDoubleMM(double value);
double fromMMToPixelsOnScreen(double value);
double fromPixelsOnScreenToMM(double value);
}

#endif // MEASUREMENTCONVERTERS_HPP
