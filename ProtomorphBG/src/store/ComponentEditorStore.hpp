#ifndef COMPONENTEDITORSTORE_HPP
#define COMPONENTEDITORSTORE_HPP

#include "src/dataobjects/Component.hpp"

#include <qfstore.h>

class ComponentEditorStore: public QFStore
{
    Q_OBJECT
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(QVariantMap background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(QVariantMap borders READ borders WRITE setBorders NOTIFY bordersChanged)
    Q_PROPERTY(Enums::ComponentType componentType READ componentType WRITE setComponentType NOTIFY componentTypeChanged)

public:
    explicit ComponentEditorStore(QObject *parent = nullptr);
    virtual ~ComponentEditorStore() override;

    double width() const;
    double height() const;
    QVariantMap background() const;
    QVariantMap borders() const;
    Enums::ComponentType componentType() const;

signals:
    void widthChanged(double width);
    void heightChanged(double height);
    void backgroundChanged(QVariantMap background);
    void componentTypeChanged(Enums::ComponentType componentType);


    void bordersChanged(QVariantMap borders);

public slots:
    void setWidth(double width);
    void setHeight(double height);
    void setBackground(const QVariantMap &backgroundProp);
    void setBorders(QVariantMap bordersProp);
    void setComponentType(Enums::ComponentType componentType);

private:
    Dataobject::Component m_component;
};

#endif // COMPONENTEDITORSTORE_HPP
