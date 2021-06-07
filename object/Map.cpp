#include "Map.h"
#include <QQuickWindow>
#include <QImage>
#include <QSGSimpleTextureNode>
#include <QSGTransformNode>
#include <QSGNode>
#include <QMatrix4x4>
#include <QTransform>
#include <QTimer>

Map::Map(QQuickItem *parent) : QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents,true);

    QTimer *time = new QTimer(this);
    connect(time, &QTimer::timeout, this,&Map::update);
    time->start(6);

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
            auto pair = std::pair<int,int>(100,100);
            tank->setCoordinate(pair);
            strokeNode->setRect(tank->coordinate().first,tank->coordinate().second, tank->image.width(), tank->image.height());
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

        //tank->transformNode->setMatrix(QMatrix4x4(transform));

        //auto c = std::pair<int,int>(tank->coordinate().first + num,tank->coordinate().second + num);
        //tank->setCoordinate(c);
        QPointF tt;

        QTransform transform = QTransform::fromScale(tank->coordinate().second, tank->coordinate().first).rotate(tank->getAngle());

        //QMatrix4x4 g;
        //g.rotate(tank->getAngle(),tank->coordinate().first,tank->coordinate().second);

        tank->transformNode->setMatrix(QMatrix4x4(transform));
        tank->textureNode->setRect(tank->coordinate().first,tank->coordinate().second,tank->image.width(),tank->image.height());
    }


    return oldNode;
}

void Map::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        auto tank = tanks[1];
        auto c = std::pair<int,int>(tank->coordinate().first,tank->coordinate().second - 1);
        tank->setCoordinate(c);

    }
    if(event->key() == Qt::Key_Left){
         auto tank = tanks[1];
         tank->setAngle(tank->getAngle() - 1);
    }
    if(event->key() == Qt::Key_Right){
        auto tank = tanks[1];
        tank->setAngle(tank->getAngle() + 1);
    }
    if(event->key() == Qt::Key_Down){
        auto tank = tanks[1];
        auto c = std::pair<int,int>(tank->coordinate().first,tank->coordinate().second+1);
        tank->setCoordinate(c);
    }
}

void Map::focusInEvent(QFocusEvent *)
{
    forceActiveFocus();
}

void Map::keyReleaseEvent(QKeyEvent *event)
{

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
