#include "src/helpers/MeasurementConverters.hpp"

#include <QApplication>
#include <QDesktopWidget>

#include <cmath>

static QDesktopWidget *s_desctop{};
static double s_pixelsInMM{0.0};

double Helper::roundToNDecimalPlaces(double value, int nofDecimalPlaces)
{
    const auto coeff =  std::pow(10.0, nofDecimalPlaces);
    return std::round(value * coeff) / coeff;
}

double Helper::fromMMToPixelsOnScreen(double value)
{
    if (!s_desctop)
    {
        s_desctop = QApplication::desktop();
        s_pixelsInMM = std::ceil(s_desctop->width() / s_desctop->widthMM());
    }

    return roundToNDecimalPlaces(value * s_pixelsInMM);
}

double Helper::fromPixelsOnScreenToMM(double value)
{
    if (!s_desctop)
    {
        s_desctop = QApplication::desktop();
        s_pixelsInMM = std::ceil(s_desctop->width() / s_desctop->widthMM());
    }

    return roundToNDecimalPlaces(value / s_pixelsInMM);
}
