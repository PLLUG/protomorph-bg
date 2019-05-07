#include "src/store/ComponentEditorStore.hpp"

#include "src/dataobjects/EditorComponent.hpp"
#include "src/dataobjects/factories/DecorationProducer.hpp"
#include "src/models/ComponentDecorationsModel.hpp"

const auto PROPERTY_OBJECT_NAME = QStringLiteral("propertiesObj");

ComponentEditorStore::ComponentEditorStore(QObject *parent)
    : QFStore{parent}
    , m_supportedActionsMap{{QStringLiteral("addDecoration"), SupportedAction::ADD_DECORATION},
{QStringLiteral("changeComponentBackground"), SupportedAction::CHANGE_COMPONENT_BACKGROUND},
{QStringLiteral("changeComponentBorders"), SupportedAction::CHANGE_COMPONENT_BORDERS},
{QStringLiteral("changeComponentSize"), SupportedAction::CHANGE_COMPONENT_SIZE}}
    , m_componentDecorationModel{std::make_unique<ComponentDecorationsModel>()}
    , m_decorationProducer{std::make_unique<DecorationProducer>()}

{
    connect(this, &ComponentEditorStore::dispatched, this, &ComponentEditorStore::onDispatched, Qt::DirectConnection);
}

ComponentEditorStore::~ComponentEditorStore() = default;

ComponentEditorStore &ComponentEditorStore::instance()
{
    static ComponentEditorStore instance;
    return instance;
}

void ComponentEditorStore::setComponent(std::shared_ptr<EditorComponent> &component)
{
    m_component = component;
}

double ComponentEditorStore::width() const
{
    return m_component->size.width();
}

double ComponentEditorStore::height() const
{
    return m_component->size.height();
}

Enums::ComponentType ComponentEditorStore::componentType() const
{
    return m_component->type;
}

ComponentDecorationsModel &ComponentEditorStore::componentDecorationsModel() const
{
    return *m_componentDecorationModel;
}

Enums::BackgroundType ComponentEditorStore::backgroundType() const
{
    return m_component->background.type;
}

QVariant ComponentEditorStore::backgroundValue() const
{
    return m_component->background.toVariant();
}

double ComponentEditorStore::borderWidth() const
{
    return m_component->borders.width;
}

QColor ComponentEditorStore::borderColor() const
{
    return m_component->borders.color;
}

void ComponentEditorStore::setComponentType(Enums::ComponentType componentType)
{
    if (m_component->type == componentType)
        return;

    m_component->type = componentType;
    emit componentTypeChanged(m_component->type);
}

void ComponentEditorStore::setComponentSize(QSizeF componentSize)
{
    if (m_component->size == componentSize)
        return;

    auto oldSize = m_component->size;

    m_component->size = componentSize;

    if (!qFuzzyCompare(oldSize.width(), m_component->size.width()))
        emit widthChanged(m_component->size.width());

    if (!qFuzzyCompare(oldSize.height(), m_component->size.height()))
        emit heightChanged(m_component->size.height());
}

void ComponentEditorStore::setBackground(const QVariant &backgroundProp)
{
    auto oldBackground = m_component->background;
    m_component->background.fromVariant(backgroundProp);

    if (oldBackground.type != m_component->background.type)
        emit backgroundTypeChanged(m_component->background.type);

    switch(m_component->background.type)
    {
    case Enums::BackgroundType::BACKGROUND_COLOR:
        if (oldBackground.color != m_component->background.color)
            emit backgroundValueChanged(m_component->background.toVariant());
        break;
    case Enums::BackgroundType::BACKGROUND_GRADIENT:
        if (oldBackground.gradientPreset  != m_component->background.gradientPreset)
            emit backgroundValueChanged(m_component->background.toVariant());
        break;
    case Enums::BackgroundType::BACKGROUND_IMAGE:
        if (oldBackground.imagePath != m_component->background.imagePath)
            emit backgroundValueChanged(m_component->background.toVariant());
        break;
    case Enums::BackgroundType::BACKGROUND_NONE:
        break;
    }
}

void ComponentEditorStore::setBorders(const QVariant &bordersProp)
{
    auto oldBorders = m_component->borders;
    m_component->borders.fromVariant(bordersProp);

    if(!qFuzzyCompare(oldBorders.width, m_component->borders.width))
        emit borderWidthChanged(m_component->borders.width);

    if(oldBorders.color != m_component->borders.color)
        emit borderColorChanged(m_component->borders.color);
}

void ComponentEditorStore::onDispatched(const QString &type, const QJSValue &message)
{
    auto supportedAction = m_supportedActionsMap.value(type);
    auto messageMap = message.toVariant().toMap();

    switch (supportedAction)
    {
    case SupportedAction::ADD_DECORATION: {
        auto newDecoration = messageMap.value(PROPERTY_OBJECT_NAME).toMap();
        if(auto decorationType = newDecoration.value(QStringLiteral("type")); decorationType.isValid())
        {
            auto decorationData = newDecoration.value(QStringLiteral("decorationData")).toMap();
            auto decorationTypeEnum = decorationType.value<Enums::DecorationType>();
            auto decoration = m_decorationProducer->createDecoration(decorationTypeEnum, decorationData);

            auto componentSize = m_component->size;
            auto decorationSideSize = componentSize.width() / 4.0;
            auto decorationTopLeft = QPointF{(componentSize.width() - decorationSideSize) / 2.0,
                    (componentSize.height() - decorationSideSize) / 2.0};
            decoration->boundingRect = QRectF{decorationTopLeft, QSizeF{decorationSideSize, decorationSideSize}};

            m_component->componentDecorations.emplace_back(std::move(decoration));
            auto &lastDecoration = *m_component->componentDecorations.back();
            auto decorationStore = m_decorationProducer->createDecorationStore(decorationTypeEnum, lastDecoration);
            m_componentDecorationModel->addDecorationStore(std::move(decorationStore));
        }
        break;
    }
    case SupportedAction::CHANGE_COMPONENT_BACKGROUND: {
        setBackground(messageMap.value(PROPERTY_OBJECT_NAME));
        break;
    }
    case SupportedAction::CHANGE_COMPONENT_BORDERS: {
        setBorders(messageMap.value(PROPERTY_OBJECT_NAME));
        break;
    }
    case SupportedAction::CHANGE_COMPONENT_SIZE: {
        auto newSize = messageMap.value(QStringLiteral("size")).toSizeF();
        setComponentSize(newSize);
        break;
    }
    }
}
