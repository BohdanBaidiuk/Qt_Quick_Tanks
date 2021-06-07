#include "dynamicobject.h"

DynamicObject::DynamicObject(QObject *parent) : BaseObject(parent)
{

}

int DynamicObject::angle() const
{
    return m_angle;
}

void DynamicObject::setAngle(int newAngle)
{
    m_angle = newAngle;
}

int DynamicObject::scrore() const
{
    return m_scrore;
}

void DynamicObject::setScrore(int newScrore)
{
    m_scrore = newScrore;
}
