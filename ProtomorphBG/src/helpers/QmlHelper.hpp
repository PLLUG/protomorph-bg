#ifndef QMLHELPER_HPP
#define QMLHELPER_HPP

#include <QObject>
#include <QSizeF>

namespace Helper {
class QmlHelper final: public QObject
{
    Q_OBJECT
public:
    static QmlHelper *instance();

public slots:
    double fromMMToPixelsOnScreen(double value);
    double fromPixelsOnScreenToMM(double value);
    double roundToCorrectDoubleMM(double value, int nofDecimalPlaces = 1);

private:
    explicit QmlHelper(QObject *parent = nullptr);
    ~QmlHelper() = default;

    QmlHelper(const QmlHelper &copy) = delete;
    QmlHelper& operator=(const QmlHelper &copy) = delete;
};
}

#endif // QMLHELPER_HPP
