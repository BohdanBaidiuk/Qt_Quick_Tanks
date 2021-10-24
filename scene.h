#ifndef SCENE_H
#define SCENE_H

#include <QQuickItem>
#include <itemobject.h>

struct ObjectInfo{
    QPointF positions{};
    QString image_path{};

};

class Scene : public QQuickItem
{
    Q_OBJECT
public:
    explicit Scene(QQuickItem *parent = nullptr);

signals:


private:
    QList<ItemObject*> m_gameObj;
    QList<ObjectInfo> m_coordinate;
    QList<ItemObject*> m_obstaclesObj;
    ushort m_objectCount = 5;
    ushort m_obstaclesCount = 10;
    QTimer* m_timer = nullptr;
    // QQuickItem interface
protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *);
    void focusInEvent(QFocusEvent *);

    // QQuickItem interface
protected:
    void keyPressEvent(QKeyEvent *event);
    ItemObject * m_obj = nullptr;
};

#endif // SCENE_H
