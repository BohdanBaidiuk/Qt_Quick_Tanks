#include "scene.h"

#include "itemobject.h"
#include <QSGSimpleTextureNode>
#include <QSGTransformNode>
#include <QSGNode>
#include <QMatrix4x4>
#include <QSGSimpleRectNode>
#include <QSGFlatColorMaterial>
#include <QSGRectangleNode>



Scene::Scene(QQuickItem *parent):QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
}

QSGNode *Scene::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    if(oldNode == nullptr){
        oldNode = new QSGNode;
        for(int i = 0; i < 5; ++i){
            QSGSimpleRectNode *rectNode = new QSGSimpleRectNode;

            QRectF r2(QPointF(100.0 + 10 * i, 200.1 + 50 * i), QSizeF(11.2, 16.3));
            rectNode->setRect(r2);

            rectNode->setColor(QColor(255,0,0));
            oldNode->appendChildNode(rectNode);
        }
    }
    return oldNode;
}

void Scene::focusInEvent(QFocusEvent *)
{
    forceActiveFocus();
}
