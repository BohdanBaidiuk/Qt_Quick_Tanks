#include "staticobject.h"

StaticObject::StaticObject(QObject *parent) : BaseObject(parent)
{

}

bool StaticObject::getIsDectroed() const
{
    return isDectroed;
}

void StaticObject::setIsDectroed(bool newIsDectroed)
{
    isDectroed = newIsDectroed;
}
