#ifndef SCENE_H
#define SCENE_H

#include <QQuickItem>
#include <itemobject.h>

class Scene : public QQuickItem
{
    Q_OBJECT
public:
    explicit Scene(QQuickItem *parent = nullptr);

signals:


private:
    QList<ItemObject*> m_gameObj;
    QList<ItemObject*> m_obstaclesObj;
    ushort m_objectCount = 5;
    ushort m_obstaclesCount = 10;
    // QQuickItem interface
protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *);
    void focusInEvent(QFocusEvent *);


};

#endif // SCENE_H
