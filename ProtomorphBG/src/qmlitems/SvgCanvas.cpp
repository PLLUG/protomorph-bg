#include "src/qmlitems/SvgCanvas.hpp"

#include <QPainter>

SvgPainter::SvgPainter(QQuickItem *parent)
    : QQuickPaintedItem{parent}
{
    auto repaint = [this](){ update(); };
    QObject::connect(this, &SvgPainter::contentChanged, this, repaint, Qt::UniqueConnection);
    QObject::connect(this, &SvgPainter::imageColorChanged, this, repaint, Qt::UniqueConnection);
}

SvgPainter::~SvgPainter() = default;

QString SvgPainter::content() const
{
    return m_content;
}

void SvgPainter::setContent(const QString& content)
{
    if(content == m_content)
        return;

    m_content = content;
    emit contentChanged(m_content);
}


QColor SvgPainter::imageColor() const
{
    return m_imageColor;
}

void SvgPainter::setImageColor(const QColor& imageColor)
{
    if (m_imageColor == imageColor)
        return;

    m_imageColor = imageColor;
    emit imageColorChanged(m_imageColor);
}

void SvgPainter::paint(QPainter *painter)
{
    auto dataWithBackgroundColor = m_content.arg(m_imageColor.name());
    static QSvgRenderer renderer(this);
    renderer.load(dataWithBackgroundColor.toUtf8());
    renderer.render(painter, boundingRect());
}
