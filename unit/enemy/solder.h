#ifndef SOLDER_H
#define SOLDER_H
#include "enemy.h"


class Solder:public QObject,public Enemy
{
    Q_OBJECT
public:
    Solder();

public slots:
    virtual void move()override;
};

#endif // SOLDER_H
