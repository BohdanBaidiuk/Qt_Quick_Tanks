#ifndef ITEMOBJECT_H
#define ITEMOBJECT_H
#include <object/tank.h>

class ItemObject
{
public:
    ItemObject();


    BaseObject *getObject() const;
    void setObject(BaseObject *newObject);

private:
    BaseObject * object = nullptr;

};

#endif // ITEMOBJECT_H
