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

int DynamicObject::scrore() const
{
    return m_scrore;
}

void DynamicObject::setScrore(int newScrore)
{
    m_scrore = newScrore;
}
