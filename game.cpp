#include "game.h"
#include "scene.h"
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QTimer>
#include <QBrush>
#include <weapon/bullet/bullet.h>

Game::Game(QWidget *parent)
{
    scene = new Scene();

    player = new Player();
    scene->addItem(player);

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    setBackgroundBrush(QPixmap(":/image/image/erth.png"));


    player->setPos(view->width()/2,view->height() - 100);
    QTimer *keyEventTimer = new QTimer();
    QObject::connect(keyEventTimer, SIGNAL(timeout()), player,SLOT(slotGameTimer()));
    keyEventTimer->start(1000 / 50);


    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QCursor cursor = QCursor(QPixmap(":/image/image/cursor.png"));

    view->setCursor(cursor);

    view->setMouseTracking(true);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+30);
    scene->addItem(health);

    QMediaPlayer * mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/sounds/fom_music.mp3"));
    mediaPlayer->play();
    QObject::connect(scene, SIGNAL(signalShot()), player, SLOT(slotShot()));
    QObject::connect(player, SIGNAL(signalBullet()), this, SLOT(slotBullet()));
    QObject::connect(scene, &Scene::signalTargetCoordinate, player, &Player::slotTarget);
    view->show();
}

void Game::slotBullet(QPointF start, QPointF end)
{
   // scene->addItem(new Bullet(start, end));
}
