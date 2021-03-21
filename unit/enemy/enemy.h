#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>

class Enemy: public QGraphicsPixmapItem
{
public:
    //Enemy();
public slots:
    virtual void move() = 0;

};

#endif // ENEMY_H
