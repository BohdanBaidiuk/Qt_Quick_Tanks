#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "baseobject.h"

class DynamicObject : public BaseObject
{
public:
    explicit DynamicObject(QObject *parent = nullptr);
};

#endif // DYNAMICOBJECT_H
