#ifndef SVGCANVAS_H
#define SVGCANVAS_H

#include <QQuickPaintedItem>
#include <QSvgRenderer>

#include <memory>

class SvgPainter : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY(QColor imageColor READ imageColor WRITE setImageColor NOTIFY imageColorChanged)
public:
    SvgPainter(QQuickItem *parent = nullptr);
    virtual ~SvgPainter() override;

    QString content() const;
    QColor imageColor() const;

public slots:
    void setContent(const QString& content);
    void setImageColor(const QColor& imageColor);

signals:
    void contentChanged(const QString& content);
    void imageColorChanged(const QColor& imageColor);

private:
    virtual void paint(QPainter *painter) override;

    QColor m_imageColor;
    QString m_content;
};

#endif // SVGCANVAS_H

