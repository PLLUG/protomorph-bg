#ifndef COMPONENTEDITORSTORE_HPP
#define COMPONENTEDITORSTORE_HPP

#include <qfstore.h>

class ComponentEditorStore: public QFStore
{
    Q_OBJECT
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged)

public:
    explicit ComponentEditorStore(QObject *parent = nullptr);
    ~ComponentEditorStore() = default;

    double width() const;
    double height() const;

signals:
    void widthChanged(double width);
    void heightChanged(double height);

public slots:
    void setWidth(double width);
    void setHeight(double height);

private:
    double m_width;
    double m_height;
};

#endif // COMPONENTEDITORSTORE_HPP
