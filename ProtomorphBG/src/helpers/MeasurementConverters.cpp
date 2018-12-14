#include "src/helpers/MeasurementConverters.hpp"

#include <QGuiApplication>
#include <QScreen>

constexpr double MM_IN_INCHES{25.4};

static QScreen *s_desctop{};
static double s_logDotsPerInch{0.0};

double Helper::fromMMToPixelsOnScreen(double value)
{
    if (!s_desctop)
    {
        s_desctop = qGuiApp->screens().at(0);
        s_logDotsPerInch = std::ceil(s_desctop->logicalDotsPerInch() / MM_IN_INCHES);
    }

    return std::round(s_logDotsPerInch * value);
}

double Helper::fromPixelsOnScreenToMM(double value)
{
    if (!s_desctop)
    {
        s_desctop = qGuiApp->screens().at(0);
        s_logDotsPerInch = std::ceil(s_desctop->logicalDotsPerInch() / MM_IN_INCHES);
    }

    return std::round(value / s_logDotsPerInch);
}
