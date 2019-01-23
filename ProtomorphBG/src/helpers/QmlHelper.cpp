#include "src/helpers/QmlHelper.hpp"

#include "src/helpers/MeasurementConverters.hpp"

#include <QDir>

using namespace Helper;

QmlHelper::QmlHelper(QObject *parent)
    : QObject{parent}
{
}

QmlHelper *QmlHelper::instance()
{
    static QmlHelper inst;
    return &inst;
}

double QmlHelper::fromMMToPixelsOnScreen(double value)
{
    return Helper::fromMMToPixelsOnScreen(value);
}

double QmlHelper::fromPixelsOnScreenToMM(double value)
{
    return Helper::fromPixelsOnScreenToMM(value);
}

double QmlHelper::roundToCorrectDoubleMM(double value)
{
    return Helper::roundToCorrectDoubleMM(value);
}

double QmlHelper::roundToNDecimalPlaces(double value, int nofDecimalPlaces)
{
    return Helper::roundToNDecimalPlaces(value, nofDecimalPlaces);
}

QString QmlHelper::urlToDisplayString(const QUrl &url)
{
    return QDir::toNativeSeparators(url.toLocalFile());
}
