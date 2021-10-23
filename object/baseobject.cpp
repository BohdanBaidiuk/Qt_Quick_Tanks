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

const QSizeF &BaseObject::size() const
{
    return m_size;
}

void BaseObject::setSize(const QSizeF &newSize)
{

    m_size = newSize;
}
