#include "SvgImage.hpp"

#include <QSGGeometry>
#include <QSGVertexColorMaterial>
#include <QSGGeometryNode>
#include <qsgflatcolormaterial.h>

SvgImage::SvgImage(QQuickItem *parent)
    : QQuickItem{parent}
{
    setFlag(ItemHasContents);
}

SvgImage::~SvgImage() = default;

QString SvgImage::source() const
{
    return m_source;
}

QColor SvgImage::fillColor() const
{
    return m_fillColor;
}

void SvgImage::setSource(const QString &source)
{
    if (m_source == source)
        return;

    m_source = source;
    emit sourceChanged(m_source);
}

void SvgImage::setFillColor(const QColor &fillColor)
{
    if (m_fillColor == fillColor)
        return;

    m_fillColor = fillColor;
    emit fillColorChanged(m_fillColor);
}


QSGNode *SvgImage::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    if (width() <= 0 || height() <= 0) {
        delete oldNode;
        return nullptr;
    }
    auto node = static_cast<QSGGeometryNode*>(oldNode);
    if (!node) {
        node = new QSGGeometryNode;
        node->setFlag(QSGNode::OwnsMaterial);
        node->setFlag(QSGNode::OwnsGeometry);
    }

    const auto rect = boundingRect();
    auto geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 3);
    auto points = geometry->vertexDataAsPoint2D();
    points[0].x = rect.left();
    points[0].y = rect.top();
    points[1].x = rect.left() + rect.width() / 2.0;
    points[1].y = rect.bottom();
    points[2].x = rect.right();
    points[2].y = rect.top();

    node->setGeometry(geometry);
    auto material = new QSGFlatColorMaterial;
    material->setColor(m_fillColor);
    node->setMaterial(material);
    return node;
}

