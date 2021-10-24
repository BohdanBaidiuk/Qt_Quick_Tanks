#include "scene.h"

#include "itemobject.h"
#include <QSGSimpleTextureNode>
#include <QSGTransformNode>
#include <QSGNode>
#include <QMatrix4x4>
#include <QSGSimpleRectNode>
#include <QSGFlatColorMaterial>
#include <QSGRectangleNode>
#include <QTimer>
#include <QSGTexture>

#include <QQuickWindow>

#include <cmath>




Scene::Scene(QQuickItem *parent):QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);

    m_timer = new QTimer(this);
    m_timer->start(100);



    m_coordinate.push_back(ObjectInfo{{10,10},":/image/star.png"});
    m_coordinate.push_back(ObjectInfo{{10,400},":/image/star1.png"});
    m_coordinate.push_back(ObjectInfo{{400,10},":/image/star3.png"});
    m_coordinate.push_back(ObjectInfo{{200,200},":/image/star4.png"});


}

QSGNode *Scene::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{

    if (oldNode == nullptr){
        oldNode = new QSGNode();
        for(const auto &obj:qAsConst(m_coordinate)){

            QSGTransformNode * transformNode = new QSGTransformNode();
            transformNode->setFlag(QSGNode::OwnedByParent);
            //QSGFlatColorMaterial *material = nullptr;
            //QSGGeometryNode *geometryNode = new QSGGeometryNode();
            QImage im;
            im.load(obj.image_path);
            QSGTexture * texture = window()->createTextureFromImage(im,QQuickWindow::TextureHasAlphaChannel);


            QSGSimpleTextureNode *strokeNode = new QSGSimpleTextureNode();
            strokeNode->setRect(obj.positions.x(),obj.positions.y(), im.width(), im.height());

            strokeNode->setTexture(texture);
            strokeNode->setFlag(QSGNode::OwnedByParent);
            transformNode->appendChildNode(strokeNode);

            C_QSGNode * objNode = new C_QSGNode(transformNode,texture);
            Tank * baseObj = new Tank(this);
            auto item_obj = new ItemObject(objNode,baseObj);
            item_obj->setObject(baseObj);
            item_obj->setX(obj.positions.x());
            item_obj->setY(obj.positions.y());
            //QRectF rec;
            //rec.setWidth(100);
            //rec.setHeight(100);
            //rec.setX(obj.positions.x());
            //rec.setY(obj.positions.y());
            //baseObj->setBody(rec);
            //geometryNode->setGeometry(new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 4));
            //geometryNode->setMaterial(new QSGFlatColorMaterial());
            //geometryNode->geometry()->setDrawingMode(QSGGeometry::DrawTriangleFan);
            //geometryNode->setFlags(QSGNode::OwnsGeometry | QSGNode::OwnsMaterial);
            //m_obj->getQSGnode()->drawRectangle(rec);
            //transformNode->appendChildNode(geometryNode);
            //geometryNode = static_cast<QSGGeometryNode*>(transformNode->childAtIndex(0));
            //material = static_cast<QSGFlatColorMaterial*>(geometryNode->material());

            //material->setColor(QColor(255,5,0));

            //geometryNode->markDirty(QSGNode::DirtyMaterial | QSGNode::DirtyGeometry);
            m_gameObj.push_back(item_obj);
            oldNode->appendChildNode(transformNode);
        }

    }else{
        //m_obj->moveObject();
        for(auto &obb:m_gameObj){
            auto transformNode = obb->getQSGnode()->m_transformNode;
            auto point = obb->mapToParent();
            QTransform transform = QTransform::fromTranslate(point.x(), point.y()).rotate(obb->getObject()->angle());
            transformNode->setMatrix(transform);
            transformNode->markDirty(QSGNode::DirtyMatrix);
        }
        //m_obj->rotateObject();

    }

    return oldNode;
}

void Scene::focusInEvent(QFocusEvent *)
{
    forceActiveFocus();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    connect(m_timer,&QTimer::timeout,this,[=](){
        //m_obj->moveObject();
        update();
    });

    // update();
    // m_obj->moveObject(event);
}
