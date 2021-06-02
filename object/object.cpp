#include "object.h"
#include <QQuickWindow>
#include <QImage>
#include <QSGSimpleTextureNode>

Object::Object(QQuickItem *parent) : QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents,true);
}

QSGNode *Object::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
     QImage img = QImage(":/image/Track_64_64.png");

     setWidth(img.width());
     setHeight(img.height());

     qDebug()<<m_width<<" == "<<m_height;



     QSGSimpleTextureNode *node = static_cast<QSGSimpleTextureNode *>(oldNode);
     if (!node) {
         node = new QSGSimpleTextureNode();
         auto texture = window()->createTextureFromImage(img,QQuickWindow::TextureHasAlphaChannel);
         node->setTexture(texture);
     }
     node->setRect(boundingRect());
     return node;
}

int Object::width() const
{
    return m_width;
}

void Object::setWidth(int newWidth)
{
    if (m_width == newWidth)
        return;
    m_width = newWidth;
    emit widthChanged();
}

int Object::height() const
{
    return m_height;
}

void Object::setHeight(int newHeight)
{
    if (m_height == newHeight)
        return;
    m_height = newHeight;
    emit heightChanged();
}
