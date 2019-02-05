#include "src/store/ComponentEditorStore.hpp"

#include <unordered_map>

using namespace Dataobject;

const static QMap<QString, ComponentEditorStore::SupportedAction> s_supportedActionsMap
    {
        {QStringLiteral("addDecoration"), ComponentEditorStore::SupportedAction::ADD_DECORATION},
        {QStringLiteral("changeComponentBackground"), ComponentEditorStore::SupportedAction::CHANGE_COMPONENT_BACKGROUND},
        {QStringLiteral("changeComponentBorders"), ComponentEditorStore::SupportedAction::CHANGE_COMPONENT_BORDERS},
        {QStringLiteral("changeComponentSize"), ComponentEditorStore::SupportedAction::CHANGE_COMPONENT_SIZE}
    };

ComponentEditorStore::ComponentEditorStore(QObject *parent)
    : QFStore{parent}
{
    connect(this, &ComponentEditorStore::dispatched, this, &ComponentEditorStore::onDispatched, Qt::DirectConnection);
}

ComponentEditorStore::~ComponentEditorStore() = default;

double ComponentEditorStore::width() const
{
    return m_component.size.width();
}

double ComponentEditorStore::height() const
{
    return m_component.size.height();
}

Enums::ComponentType ComponentEditorStore::componentType() const
{
    return m_component.type;
}

Enums::BackgroundType ComponentEditorStore::backgroundType() const
{
    return m_component.background.type;
}

QVariant ComponentEditorStore::backgroundValue() const
{
    return m_component.background.colorValueToVariant();
}

double ComponentEditorStore::borderWidth() const
{
    return m_component.borders.width;
}

QColor ComponentEditorStore::borderColor() const
{
    return m_component.borders.color;
}

void ComponentEditorStore::setComponentType(Enums::ComponentType componentType)
{
    if (m_component.type == componentType)
        return;

    m_component.type = componentType;
    emit componentTypeChanged(m_component.type);
}

void ComponentEditorStore::setComponentSize(QSizeF componentSize)
{
    if (m_component.size == componentSize)
        return;

    auto oldSize = m_component.size;

    m_component.size = componentSize;

    if (!qFuzzyCompare(oldSize.width(), m_component.size.width()))
        emit widthChanged(m_component.size.width());

    if (!qFuzzyCompare(oldSize.height(), m_component.size.height()))
        emit heightChanged(m_component.size.height());
}

void ComponentEditorStore::setBackground(const QVariantMap &backgroundProp)
{
    auto oldBackground = m_component.background;
    m_component.background.fillFromQmlType(backgroundProp);

    if (oldBackground.type != m_component.background.type)
        emit backgroundTypeChanged(m_component.background.type);

    switch(m_component.background.type)
    {
    case Enums::BackgroundType::BACKGROUND_COLOR:
        if (oldBackground.color != m_component.background.color)
            emit backgroundValueChanged(m_component.background.colorValueToVariant());
        break;
    case Enums::BackgroundType::BACKGROUND_GRADIENT:
        if (oldBackground.gradientPreset  != m_component.background.gradientPreset)
            emit backgroundValueChanged(m_component.background.colorValueToVariant());
        break;
    case Enums::BackgroundType::BACKGROUND_IMAGE:
        if (oldBackground.imagePath != m_component.background.imagePath)
            emit backgroundValueChanged(m_component.background.colorValueToVariant());
        break;
    case Enums::BackgroundType::BACKGROUND_NONE:
        break;
    }
}

void ComponentEditorStore::setBorders(const QVariantMap &bordersProp)
{
    auto oldBorders = m_component.borders;
    m_component.borders.fillFromQmlType(bordersProp);

    if(!qFuzzyCompare(oldBorders.width, m_component.borders.width))
        emit borderWidthChanged(m_component.borders.width);

    if(oldBorders.color != m_component.borders.color)
        emit borderColorChanged(m_component.borders.color);
}

void ComponentEditorStore::onDispatched(const QString &type, const QJSValue &message)
{
    auto supportedAction = s_supportedActionsMap.value(type);
    auto messageMap = message.toVariant().toMap();

    switch (supportedAction)
    {
    case SupportedAction::ADD_DECORATION:
        break;
    case SupportedAction::CHANGE_COMPONENT_BACKGROUND: {
        auto newBackgroundProperties = messageMap.value(QStringLiteral("propertiesObj")).toMap();
        setBackground(newBackgroundProperties);
        break;
    }
    case SupportedAction::CHANGE_COMPONENT_BORDERS: {
        auto newBordersProperties = messageMap.value(QStringLiteral("propertiesObj")).toMap();
        setBorders(newBordersProperties);
        break;
    }
    case SupportedAction::CHANGE_COMPONENT_SIZE: {
        auto newSize = messageMap.value(QStringLiteral("size")).toSizeF();
        setComponentSize(newSize);
        break;
    }
    }
}
