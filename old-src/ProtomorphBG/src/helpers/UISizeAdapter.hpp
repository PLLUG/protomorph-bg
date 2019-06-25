#ifndef SCREENSIZEADAPTER_HPP
#define SCREENSIZEADAPTER_HPP

#include <QObject>
namespace Helper {
class UISizeAdapter final: public QObject
{
    Q_OBJECT
public:
    static UISizeAdapter *instance();

public slots:
    int calculateSize(const int value) const;

private:
    UISizeAdapter(QObject *parent = nullptr);
    ~UISizeAdapter() = default;

    double m_ratio;
};
}

#endif // SCREENSIZEADAPTER_HPP
