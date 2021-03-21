#ifndef GAME_H
#define GAME_H
#include <unit/item.h>
#include "score.h"
#include "health.h"
#include "scene.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

class Game: public QGraphicsView
{

public:
    Game(QWidget *parent = nullptr);
    Scene *scene;

    Player * player;
    Score * score;
    Health * health;

private slots:
    void slotBullet(QPointF start, QPointF end);

};

#endif // GAME_H
