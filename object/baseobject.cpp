#include "baseobject.h"

BaseObject::BaseObject(QObject *parent) : QObject(parent)
{

}

QPointF BaseObject::point() const
{
    return m_point;
}

void BaseObject::setPoint(QPointF newPoint)
{
    m_point = newPoint;
}

int BaseObject::health() const
{
    return m_health;
}

void BaseObject::setHealth(int newHealth)
{
    m_health = newHealth;
}

int BaseObject::height() const
{
    return m_height;
}

void BaseObject::setHeight(int newHeight)
{
    m_height = newHeight;
}

int BaseObject::width() const
{
    return m_width;
}

void BaseObject::setWidth(int newWidth)
{
    m_width = newWidth;
}
