#include "src/qmlitems/SvgCanvas.hpp"

#include <QPainter>

SvgPainter::SvgPainter(QQuickItem *parent)
    : QQuickPaintedItem{parent}
      , m_renderer{new QSvgRenderer(this)}
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
    m_renderer->load(dataWithBackgroundColor.toLatin1());
    painter->setRenderHints(QPainter::Antialiasing, true);
    //Fix aspect ratio issue
    auto defSize = m_renderer->defaultSize();
    auto rect = boundingRect();
    auto mySize = rect.size();
    qreal widthRatio = mySize.width() / defSize.width();
    qreal heightRatio = mySize.height() / defSize.height();
    if(widthRatio > heightRatio) {
        mySize.rwidth() = defSize.width() * heightRatio;
    }
    else if(widthRatio < heightRatio) {
        mySize.rheight() = defSize.height() * widthRatio;
    }
    auto newTopLeft = rect.topLeft();
    newTopLeft.rx() += (rect.size().width() - mySize.width()) / 2.0;
    newTopLeft.ry() += (rect.size().height() - mySize.height()) / 2.0;
    QRectF boundingBox(newTopLeft, mySize);
    setImplicitWidth(mySize.width());
    setImplicitHeight(mySize.height());

    painter->setBrush(Qt::transparent);
    painter->setPen(Qt::red);

    m_renderer->render(painter, boundingBox);
}
