#ifndef BULLET_H
#define BULLET_H

#include "dynamicobject.h"

class Bullet : public DynamicObject
{
public:
    explicit Bullet(QObject *parent = nullptr);
};

#endif // BULLET_H
