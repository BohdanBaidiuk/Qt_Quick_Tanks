#include "item.h"
#include <weapon/bullet/bullet.h>
#include <unit/enemy/solder.h>
#include <math.h>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>

#include <QGraphicsScene>

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


Player::Player()
{
    bulletShot = new QMediaPlayer();
    bulletShot->setMedia(QUrl("qrc:/sounds/sounds/shot.mp3"));
    QPixmap pixmap(":image/image/player.png");
    setPixmap(pixmap);
    setTransformOriginPoint(pixmap.rect().center());
    angle = 0;
    setRotation(angle);
    target = QPointF(0,0);
    gameTimer = new QTimer();
    QObject::connect(gameTimer, SIGNAL(timeout()), this, SLOT(slotGameTimer()));
    gameTimer->start(10);
}

//void Player::keyPressEvent(QKeyEvent *event)
//{
//    if(event->key() == Qt::Key_Left && pos().x() > 0){
//        setPos(x()-10, y());
//    }else if(event->key() == Qt::Key_Right && pos().x() < 800){
//        setPos(x()+10, y());
//    }else if(event->key() == Qt::Key_Up){
//        setPos(x(), y()-10);
//    }else if(event->key() == Qt::Key_Down){
//        setPos(x(), y()+10);
//    }else if(event->key() == Qt::Key_Space){
//        Bullet * bullet = new Bullet();
//        bullet->setPos(x(),y());
//        scene()->addItem(bullet);
//        if(bulletShot->state() == QMediaPlayer::PlayingState){
//            bulletShot->setPosition(0);
//        }else if(bulletShot->state() == QMediaPlayer::StoppedState){
//            bulletShot->play();
//        }
//    }

//}

void Player::spawn()
{
    Enemy * enemy = new Solder();
    scene()->addItem(enemy);

}

void Player::slotGameTimer()
{
    if(GetAsyncKeyState('A')){
        this->setX(this->x() - 2);
    }
    if(GetAsyncKeyState('D')){
        this->setX(this->x() + 2);
    }
    if(GetAsyncKeyState('W')){
        this->setY(this->y() - 2);
    }
    if(GetAsyncKeyState('S')){
        this->setY(this->y() + 2);
    }
    if(GetAsyncKeyState(VK_LEFT)){
        angle -= 1;
        setRotation(angle);
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle += 1;
        setRotation(angle);
    }
    if(GetAsyncKeyState(VK_SPACE)){
        Bullet * bullet = new Bullet(angle);
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        if(bulletShot->state() == QMediaPlayer::PlayingState){
            bulletShot->setPosition(0);
        }else if(bulletShot->state() == QMediaPlayer::StoppedState){
            bulletShot->play();
        }

    }
    setNormilezeAngle();
    qDebug()<<angle;

    //       if(this->x() - 30 < 0){
    //           this->setX(30);         // слева
    //       }
    //       if(this->x() + 30 > 500){
    //           this->setX(500 - 30);   // справа
    //       }

    //       if(this->y() - 30 < 0){
    //           this->setY(30);         // сверху
    //       }
    //       if(this->y() + 30 > 500){
    //           this->setY(500 - 30);   // снизу
    //       }

    //    QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
    //    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    //    if (lineToTarget.dy() < 0)
    //        angleToTarget = TwoPi - angleToTarget;
    //    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);


    //    if (angleToTarget >= 0 && angleToTarget < Pi) {
    //        // Rotate left
    //        setRotation(rotation() - angleToTarget * 180 /Pi);
    //    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
    //        // Rotate right
    //        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    //    }
}

void Player::slotTarget(QPointF point)
{
    //    target = point;
    //    QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));

    //    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    //    if (lineToTarget.dy() < 0)
    //        angleToTarget = TwoPi - angleToTarget;
    //    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);


    //    if (angleToTarget >= 0 && angleToTarget < Pi) {

    //        setRotation(rotation() - angleToTarget * 180 /Pi);
    //    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {

    //        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    //    }
}

void Player::slotShot(bool shot)
{
    this->shot = shot;
}

void Player::slotBulletTimer()
{
    if(shot) emit signalBullet(QPointF(this->x(),this->y()), target);
}

void Player::setNormilezeAngle()
{
    if(angle < 1){
        angle = 360 + angle;
    }
    if(angle > 360){
        angle = angle - 360;
    }
}


