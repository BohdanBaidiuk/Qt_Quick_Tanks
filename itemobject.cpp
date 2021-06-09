#include "itemobject.h"

ItemObject::ItemObject()
{

}

BaseObject *ItemObject::getObject() const
{
    return object;
}

void ItemObject::setObject(BaseObject *newObject)
{
    object = newObject;
}
