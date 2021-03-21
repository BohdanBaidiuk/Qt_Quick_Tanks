#ifndef SCENE_H
#define SCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit  Scene(QObject *parent = 0);
signals:
    void signalTargetCoordinate(QPointF point);
    void signalShot(bool shot);
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SCENE_H
