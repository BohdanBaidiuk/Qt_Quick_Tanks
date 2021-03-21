#include "scene.h"

Scene::Scene(QObject *parent): QGraphicsScene()
{
    Q_UNUSED(parent);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalTargetCoordinate(event->scenePos());
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalShot(true);
       Q_UNUSED(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalShot(false);
       Q_UNUSED(event);
}
