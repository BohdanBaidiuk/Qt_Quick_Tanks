#ifndef ITEM_H
#define ITEM_H
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <windows.h>

class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
   // void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void slotGameTimer();
    void slotTarget(QPointF point);
    void slotShot(bool shot);
    void slotBulletTimer();
signals:
    void signalBullet(QPointF start, QPointF end);
private:
    QMediaPlayer * bulletShot;
    qreal angle;
    QTimer *gameTimer;
    QPointF target;
    bool shot;

    void setNormilezeAngle();
};

#endif // ITEM_H
