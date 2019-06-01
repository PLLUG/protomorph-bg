#include "src/store/DecorationStore.hpp"

DecorationStore::DecorationStore(QObject *parent)
    : QFStore{parent}
    , m_actionsMap{{QStringLiteral("changeDecorationBackground"), DecorationAction::CHANGE_DECORATION_BACKGROUND},
                   {QStringLiteral("changeDecorationForeground"), DecorationAction::CHANGE_DECORATION_FOREGROUND},
                   {QStringLiteral("changeDecorationPosition"), DecorationAction::CHANGE_DECORATION_POSITION},
                   {QStringLiteral("changeDecorationSize"), DecorationAction::CHANGE_DECORATION_SIZE}}
{
    m_metadata.isVisible = true;
    connect(this, &DecorationStore::dispatched, this, &DecorationStore::onDispatched, Qt::DirectConnection);
}

DecorationStore::~DecorationStore() = default;

void DecorationStore::onDispatched(const QString &type, const QJSValue &message)
{
    auto supportedAction = m_actionsMap.value(type);
    auto messageMap = message.toVariant().toMap();

    switch (supportedAction)
    {
    case DecorationAction::CHANGE_DECORATION_BACKGROUND:
        break;
    case DecorationAction::CHANGE_DECORATION_FOREGROUND:
        break;
    case DecorationAction::CHANGE_DECORATION_POSITION: {
        auto newPosition = messageMap.value(QStringLiteral("position")).toPointF();
        setDecorationPosition(newPosition);
        break;
    }
    case DecorationAction::CHANGE_DECORATION_SIZE: {
        auto newSize = messageMap.value(QStringLiteral("size")).toSizeF();
        setDecorationSize(newSize);
        break;
    }
    }
}

