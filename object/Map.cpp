#include "Map.h"
#include <QQuickWindow>
#include <QImage>
#include <QSGSimpleTextureNode>
#include <QSGTransformNode>
#include <QSGNode>
#include <QMatrix4x4>
#include <QTransform>

Map::Map(QQuickItem *parent) : QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents,true);
}

QSGNode *Map::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    if (!oldNode) {
        oldNode = new QSGNode();
        oldNode->setFlag(QSGNode::OwnedByParent);
        QVector<QString> path{":/image/Bullet.png",":/image/Track_64_64.png"};

        for(int i = 0; i < path.count(); ++i){
            Tank * tank = new Tank();
            tank->image.load(path[i]);
            QSGTransformNode *trn = new QSGTransformNode();
            trn->setFlag(QSGNode::OwnedByParent);
            tank->transformNode = trn;
            oldNode->appendChildNode(trn);

            auto texture = window()->createTextureFromImage(tank->image,QQuickWindow::TextureHasAlphaChannel);
            QSGSimpleTextureNode *strokeNode = new QSGSimpleTextureNode();
            strokeNode->setRect(100, 100, tank->image.width(), tank->image.height());
            strokeNode->setTexture(texture);
            strokeNode->setFlag(QSGNode::OwnedByParent);
            trn->appendChildNode(strokeNode);
            tank->textureNode = strokeNode;
            //_transformNodes.push_back(trn);

            tanks.push_back(tank);
        }

    }
    static int num = 1;


    for(auto &tank:tanks){

        //QTransform transform = QTransform::fromTranslate(0+num, 0).rotate(num);
        //tank->transformNode->setMatrix(QMatrix4x4(transform));
        tank->textureNode->setRect(0 + num,0 + num,tank->image.width(),tank->image.height());
        num++;
    }


    return oldNode;
}

void Map::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        qDebug()<<"up";
    }
    if(event->key() == Qt::Key_Left){
        qDebug()<<"left";
    }
    if(event->key() == Qt::Key_Right){
        qDebug()<<"right";
    }
    if(event->key() == Qt::Key_Down){
        qDebug()<<"down";
    }
}

int Map::width() const
{
    return m_width;
}

void Map::setWidth(int newWidth)
{
    if (m_width == newWidth)
        return;
    m_width = newWidth;
    emit widthChanged();
}

int Map::height() const
{
    return m_height;
}

void Map::setHeight(int newHeight)
{
    if (m_height == newHeight)
        return;
    m_height = newHeight;
    emit heightChanged();
}
