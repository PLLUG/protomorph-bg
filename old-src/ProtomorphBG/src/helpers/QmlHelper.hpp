#ifndef QMLHELPER_HPP
#define QMLHELPER_HPP

#include <QGradient>
#include <QObject>
#include <QSizeF>
#include <QUrl>

class QQuickItem ;

namespace Helper {
class QmlHelper final: public QObject
{
    Q_OBJECT
public:
    static QmlHelper *instance();

public slots:
    double fromMMToPixelsOnScreen(double value);
    double fromPixelsOnScreenToMM(double value);
    double roundToCorrectDoubleMM(double value);
    double roundToNDecimalPlaces(double value, int nofDecimalPlaces = 1);
    QString urlToDisplayString(const QUrl &url);
    QStringList getPreseteGradientsList();
    QGradient::Preset getPresetGradient(const QString &pesetName);

private:
    explicit QmlHelper(QObject *parent = nullptr);
    ~QmlHelper() = default;

    QmlHelper(const QmlHelper &copy) = delete;
    QmlHelper& operator=(const QmlHelper &copy) = delete;
};
}

#endif // QMLHELPER_HPP
