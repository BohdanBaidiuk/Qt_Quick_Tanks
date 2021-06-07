#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "baseobject.h"

class StaticObject : public BaseObject
{
public:
    explicit StaticObject(QObject *parent = nullptr);
};

#endif // STATICOBJECT_H
