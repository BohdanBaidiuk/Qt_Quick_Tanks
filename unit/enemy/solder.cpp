#include "solder.h"
#include "game.h"
#include <QTimer>
#include <QRandomGenerator>

extern Game * game;

Solder::Solder()
{
    int x = QRandomGenerator::global()->bounded(700);
    //int y = QRandomGenerator::global()->bounded(100);
    setPos(x,0);
    setPixmap(QPixmap(":image/image/enemy.png"));
    setTransformOriginPoint(50,50);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Solder::move()
{
    setPos(x(),y() + 5);
    if(pos().y() > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}
