#ifndef SVGIMAGE_HPP
#define SVGIMAGE_HPP

#include <QQuickItem>

class SvgImage: public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QColor fillColor READ fillColor WRITE setFillColor NOTIFY fillColorChanged)

public:
    explicit SvgImage(QQuickItem *parent = nullptr);
    virtual ~SvgImage() override;

    // QQuickItem interface
    QString source() const;

    QColor fillColor() const;

public slots:
    void setSource(const QString &source);
    void setFillColor(const QColor &fillColor);

signals:
    void sourceChanged(QString source);
    void fillColorChanged(QColor fillColor);

protected:
    virtual QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) override;

private:
    QString m_source;
    QColor m_fillColor;
};

#endif // SVGIMAGE_HPP
