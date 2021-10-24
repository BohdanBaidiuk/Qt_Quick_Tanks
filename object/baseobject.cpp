#include "baseobject.h"

BaseObject::BaseObject(QObject *parent) : QObject(parent)
{

}

const QRectF &BaseObject::body() const
{
    return m_body;
}

void BaseObject::setBody(const QRectF &newBody)
{
    m_body = newBody;
}

short BaseObject::health() const
{
    return m_health;
}

void BaseObject::setHealth(short newHealth)
{
    if (m_health == newHealth)
        return;
    m_health = newHealth;
}

void BaseObject::setX(qreal x)
{
    if(m_body.x() == x){
        return;
    }
    m_body.setX(x);
}

void BaseObject::setY(qreal y)
{
    if(m_body.y() == y){
        return;
    }
    m_body.setY(y);
}

qreal BaseObject::angle() const
{
    return m_angle;
}

void BaseObject::setAngle(qreal newAngle)
{
    if(m_angle == newAngle){
        return ;
    }

    if(newAngle == 360){
        m_angle = 0;
        return ;
    }
    if(newAngle == -1){
        m_angle = 359;
        return ;
    }
    m_angle = newAngle;
}

