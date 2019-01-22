#include "src/helpers/MeasurementConverters.hpp"

#include <QApplication>
#include <QScreen>

constexpr double MM_IN_INCHES{25.4};

static QScreen *s_desctop{};
static double s_logDotsPerInch{0.0};

double Helper::roundToNDecimalPlaces(double value, int nofDecimalPlaces)
{
    const auto coeff =  std::pow(10.0, nofDecimalPlaces);
    return std::round(value * coeff) / coeff;
}

double Helper::fromMMToPixelsOnScreen(double value)
{
    if (!s_desctop)
    {
        s_desctop = QApplication::screens().at(0);
        s_logDotsPerInch = std::ceil(s_desctop->logicalDotsPerInch() / MM_IN_INCHES);
    }

    return roundToNDecimalPlaces(s_logDotsPerInch * value);
}

double Helper::fromPixelsOnScreenToMM(double value)
{
    if (!s_desctop)
    {
        s_desctop = QApplication::screens().at(0);
        s_logDotsPerInch = std::ceil(s_desctop->logicalDotsPerInch() / MM_IN_INCHES);
    }

    return roundToNDecimalPlaces(value / s_logDotsPerInch);
}
