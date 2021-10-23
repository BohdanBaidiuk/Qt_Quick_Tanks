#ifndef TANK_H
#define TANK_H

#include "dynamicobject.h"

class Tank : public DynamicObject
{
public:
    explicit Tank(QObject *parent = nullptr);
};

#endif // TANK_H
