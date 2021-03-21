#ifndef HEAVYSOLDIER_H
#define HEAVYSOLDIER_H
#include "enemy.h"

class HeavySoldier:public QObject,public Enemy
{
    Q_OBJECT
public:
    HeavySoldier();
public slots:
    virtual void move()override;

};

#endif // HEAVYSOLDIER_H
