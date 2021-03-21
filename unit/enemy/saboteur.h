#ifndef SABOTEUR_H
#define SABOTEUR_H
#include "enemy.h"

class Saboteur:public QObject,public Enemy
{
    Q_OBJECT
public:
    Saboteur();
public slots:
    virtual void move()override;
};

#endif // SABOTEUR_H
