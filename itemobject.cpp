#include "itemobject.h"
#include <cmath>

ItemObject::ItemObject(C_QSGNode *node,Tank * tank):m_node(node),object(tank)
{
    pre_calculate();
}

C_QSGNode *ItemObject::getQSGnode()
{
    return m_node;
}

Tank *ItemObject::getObject() const
{
    return object;
}

void ItemObject::setObject(Tank *newObject)
{
    object = newObject;
}

void ItemObject::setX(qreal x)
{
    object->setX(x) ;
}

void ItemObject::setY(qreal y)
{
    object->setY(y);
}

qreal ItemObject::x()
{
    return object->body().x();
}

qreal ItemObject::y()
{
    return object->body().y();
}

void ItemObject::setAngle(int angle)
{
    if(angle == object->angle()){
        return ;
    }
    object->setAngle(angle);
}

void ItemObject::setWidth(int width)
{

}

void ItemObject::setHeight(int height)
{

}

qreal ItemObject::width()
{
    return object->body().width();
}

qreal ItemObject::height()
{
    return object->body().height();
}

void ItemObject::moveObject(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){

        object->setX(static_cast<qreal>(x()));
        object->setY(static_cast<qreal>(y()-1));

    }
    if(event->key() == Qt::Key_Left){
        setAngle(object->angle() -1);
    }
    if(event->key() == Qt::Key_Right){
        setAngle(object->angle() +1);
    }
    if(event->key() == Qt::Key_Down){
        object->setX(static_cast<qreal>(x()));
        object->setY(static_cast<qreal>(y()+1));
    }
}

QPointF ItemObject::mapToParent(QPointF newP)
{
    const QPointF p0{};
    QPointF pp{{static_cast<int>(object->body().width() / 2),static_cast<int>(object->body().height() / 2)}};
    //QPointF _pos{object->body().x(),object->body().y()};
    QPointF _pos{newP.x(),newP.y()};
    qreal a = object->angle() * M_PI / 180;
    QPointF p = p0 - pp;
    QPointF r(p.x() * std::cos(-a) + p.y() * std::sin(-a), - p.x() * std::sin(-a) + p.y() * std::cos(-a));
    return _pos + r + pp;
}

QPointF ItemObject::mapToParent()
{
    const QPointF p0{};
    QPointF pp{(object->body().width() / 2),(object->body().height() / 2)};
    QPointF _pos{object->body().x(),object->body().y()};

    qreal a = object->angle() * M_PI / 180;
    QPointF p = p0 - pp;
    QPointF r(p.x() * std::cos(-a) + p.y() * std::sin(-a), - p.x() * std::sin(-a) + p.y() * std::cos(-a));
    return _pos + r + pp;
}

void ItemObject::moveObject()
{

    // auto point = mapToParent(QPointF(0,0));

    //qDebug()<<xx<<" - "<<yy<<" angle "<<object->angle();
    //setAngle(object->angle() + 1);
    //qDebug()<<xR_(object->angle());
    //qDebug()<<yR_(object->angle());
   // setX(xR_(object->angle()));
    //setY(yR_(object->angle()));
    m_node->moveRectangle(x(),y());
    //m_node->rotateRectangle(object->angle(),x(),y(),width(),height());
    // m_node->rotateRectangle(object->angle(),xR_(object->angle()),yR_(object->angle()),width(),height());
}

void ItemObject::rotateObject()
{
    qDebug()<<"step";

    setAngle(object->angle() + 1);

    qDebug()<<object->body().x()<<object->body().y();

    m_node->rotateRectangle(mapToParent(),object->angle());

    //m_node->rotateRectangle(mapToParent(QPointF{xx,yy}),object->angle());
}
