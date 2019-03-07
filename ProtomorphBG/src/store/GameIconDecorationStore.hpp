#ifndef GAMEICONDECORATIONSTORE_HPP
#define GAMEICONDECORATIONSTORE_HPP

#include "src/store/DecorationStore.hpp"

struct GameIconDecoration;

class GameIconDecorationStore final : public DecorationStore
{
    Q_OBJECT
    Q_PROPERTY(QString iconData READ iconData NOTIFY iconChanged)
    Q_PROPERTY(QString iconName READ iconName NOTIFY iconChanged)
public:
    explicit GameIconDecorationStore(GameIconDecoration &gameIconDecoration, QObject *parent = nullptr);
    virtual ~GameIconDecorationStore() override;

    // DecorationStore interface
    virtual Enums::DecorationType decorationType() const override;
    virtual QColor backgroundColor() const override;
    virtual QColor foregroundColor() const override;
    virtual QPointF decorationPosition() const override;
    virtual QSizeF decorationSize() const override;

    QString iconData() const;
    QString iconName() const;


signals:
    void iconChanged();

private:
    GameIconDecoration &m_gameIconDecoration;
};

#endif // GAMEICONDECORATIONSTORE_HPP
