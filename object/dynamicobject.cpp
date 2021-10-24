#include "dynamicobject.h"

DynamicObject::DynamicObject(QObject *parent) : BaseObject(parent)
{

}

int DynamicObject::scrore() const
{
    return m_scrore;
}

void DynamicObject::setScrore(int newScrore)
{
    m_scrore = newScrore;
}

int DynamicObject::weight() const
{
    return m_weight;
}

void DynamicObject::setWeight(int newWeight)
{
    m_weight = newWeight;
}
