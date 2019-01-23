#ifndef COMPONENTEDITORSTORE_HPP
#define COMPONENTEDITORSTORE_HPP

#include "src/dataobjects/ComponentObject.hpp"

#include <qfstore.h>

#include <QColor>
#include <QImage>

class ComponentEditorStore: public QFStore
{
    Q_OBJECT
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QString backgroundImagePath READ backgroundImagePath WRITE setBackgroundImagePath NOTIFY backgroundImagePathChanged)
    Q_PROPERTY(Enums::ComponentType componentType READ componentType WRITE setComponentType NOTIFY componentTypeChanged)

public:
    explicit ComponentEditorStore(QObject *parent = nullptr);
    ~ComponentEditorStore() = default;

    double width() const;
    double height() const;

    QColor backgroundColor() const;
    QString backgroundImagePath() const;

    Enums::ComponentType componentType() const;

signals:
    void widthChanged(double width);
    void heightChanged(double height);

    void backgroundColorChanged(const QColor &backgroundColor);
    void backgroundImagePathChanged(const QString &backgroundImagePath);

    void componentTypeChanged(Enums::ComponentType componentType);

public slots:
    void setWidth(double width);
    void setHeight(double height);

    void setBackgroundColor(const QColor &backgroundColor);
    void setBackgroundImagePath(const QString &backgroundImagePath);

    void setComponentType(Enums::ComponentType componentType);

private:
    ComponentObject m_component;
};

#endif // COMPONENTEDITORSTORE_HPP
