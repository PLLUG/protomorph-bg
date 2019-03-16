#ifndef DECORATIONSTORE_HPP
#define DECORATIONSTORE_HPP

#include <QColor>
#include <QPointF>
#include <QSizeF>

#include <qfstore.h>

#include "src/constants/Enums.hpp"
#include "src/dataobjects/DecorationMetaData.hpp"

class DecorationStore : public QFStore
{
    Q_OBJECT
    Q_PROPERTY(Enums::DecorationType decorationType READ decorationType)
    Q_PROPERTY(QPointF decorationPosition READ decorationPosition NOTIFY decorationPositionChanged)
    Q_PROPERTY(QSizeF decorationSize READ decorationSize NOTIFY decorationSizeChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor foregroundColor READ foregroundColor NOTIFY foregroundColorChanged)


public:
    explicit DecorationStore(QObject *parent = nullptr);
    virtual ~DecorationStore();

    virtual Enums::DecorationType decorationType() const = 0;

    virtual QColor backgroundColor() const = 0;
    virtual QColor foregroundColor() const = 0;
    virtual QPointF decorationPosition() const = 0;
    virtual QSizeF decorationSize() const = 0;

    //Decoration METADATA
    virtual QString decorationName() { return m_metadata.name; }
    virtual void setDecorationName(const QString &newName) { if(newName != m_metadata.name) m_metadata.name = newName; }

    bool isDecorationVisible() { return m_metadata.isVisible; }
    void setDecorationVisible(bool isVisble) { m_metadata.isVisible = isVisble; }
    //METADATA End

signals:
    void backgroundColorChanged(const QColor &backgroundColor);
    void foregroundColorChanged(const QColor &foregroundColor);
    void decorationPositionChanged(const QPointF &decorationPosition);
    void decorationSizeChanged(const QSizeF &decorationSize);

private:
    DecorationMetaData m_metadata;
};

#endif // DECORATIONSTORE_HPP
