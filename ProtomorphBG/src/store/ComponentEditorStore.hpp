#ifndef COMPONENTEDITORSTORE_HPP
#define COMPONENTEDITORSTORE_HPP

#include <qfstore.h>
#include <QColor>

class ComponentEditorStore: public QFStore
{
    Q_OBJECT
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)

public:
    explicit ComponentEditorStore(QObject *parent = nullptr);
    ~ComponentEditorStore() = default;

    double width() const;
    double height() const;

    QColor backgroundColor() const;

signals:
    void widthChanged(double width);
    void heightChanged(double height);

    void backgroundColorChanged(const QColor &backgroundColor);

public slots:
    void setWidth(double width);
    void setHeight(double height);

    void setBackgroundColor(const QColor &backgroundColor);

private:
    QColor m_backgroundColor;
    double m_width;
    double m_height;
};

#endif // COMPONENTEDITORSTORE_HPP
