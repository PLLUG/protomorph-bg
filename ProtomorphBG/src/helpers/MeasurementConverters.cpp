#include "src/helpers/MeasurementConverters.hpp"

#include <QApplication>
#include <QScreen>

#include <cmath>

constexpr double EFECTIVE_DPI{96.0}; //1 effectivePixel = 1/96 inch
constexpr double MM_IN_INCH{25.4}; //1 inch = 25.4 milimetr
static QScreen *s_screen{};
static double s_logicalDPI{0.0};

double Helper::roundToCorrectDoubleMM(double value, int nofDecimalPlaces)
{
    const auto coeff =  std::pow(10.0, nofDecimalPlaces);
    auto calculatedValue = std::round(value * coeff) / coeff;
    auto modValue = std::fmod(calculatedValue, std::trunc(calculatedValue));

    return qFuzzyCompare(modValue, 0.5) ? calculatedValue : std::round(calculatedValue);
}

double Helper::fromMMToPixelsOnScreen(double value)
{
    if (!s_screen)
    {
        s_screen = QApplication::screens().at(0);
        Q_ASSERT(s_screen);
        s_logicalDPI = s_screen->logicalDotsPerInch();
    }

    auto sizeInInch = value / MM_IN_INCH;
    auto sizeInEffectivePixels = sizeInInch * EFECTIVE_DPI;
    auto sizeInPisicalPixels = std::ceil((s_logicalDPI / EFECTIVE_DPI) * sizeInEffectivePixels); //get extra pixel if needed

    return  sizeInPisicalPixels;
}

double Helper::fromPixelsOnScreenToMM(double value)
{
    if (!s_screen)
    {
        s_screen = QApplication::screens().at(0);
        Q_ASSERT(s_screen);
        s_logicalDPI = s_screen->logicalDotsPerInch();
    }

    auto sizeInEffectivePixels = value / (s_logicalDPI / EFECTIVE_DPI);
    auto sizeInInch = sizeInEffectivePixels / EFECTIVE_DPI;
    auto sizeInMM = sizeInInch * MM_IN_INCH;


    return  Helper::roundToCorrectDoubleMM(sizeInMM);
}
