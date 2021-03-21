#include "bullet.h"
#include <unit/enemy/solder.h>
#include <game.h>
#include <math.h>
#include <QGraphicsScene>
#include <QList>
#include <QPointF>
#include <QTimer>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

extern Game * game;

Bullet::Bullet(qreal angle, QObject *parent): QObject(parent){
    setRotation(angle);

    float angle_rad = angle * 3.1415927f / 180.0f;
    float cos = std::cos(angle_rad);
    float sin = std::sin(angle_rad);

//    QLineF lineToTarget(start, end);
//        qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
//        if (lineToTarget.dy() < 0)
//            angleToTarget = TwoPi - angleToTarget;
//        angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

//        /* Разворачиваем пули по траектории
//         * */
//        if (angleToTarget >= 0 && angleToTarget < Pi) {
//            /// Rotate left
//            setRotation(rotation() - angleToTarget * 180 /Pi);
//        } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
//            /// Rotate right
//            setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
//        }
//        // Инициализируем полётный таймер


    QPixmap pixmap(":image/image/knives.png");
    setPixmap(pixmap);
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    setTransformOriginPoint(pixmap.rect().center());
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); ++i){
        auto enemy = dynamic_cast<Enemy*>(colliding_items[i]);
        if(enemy != nullptr){
            //continue;
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return ;
        }
    }
    //setPos(x(),y()-10);
    setPos(mapToParent(0,-50));
    //setRotation(50 + rotation());

    if(pos().y() < 0 ){
        scene()->removeItem(this);
        delete this;
    }



}
