#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>

class Bullet:public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(qreal angle,QObject *parent = nullptr);
public slots:
    void move();

private:
    double setX;
    double setY;
};

#endif // BULLET_H
