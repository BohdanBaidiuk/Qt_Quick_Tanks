#ifndef ITEMOBJECT_H
#define ITEMOBJECT_H
#include <object/tank.h>
#include <math.h>
#include <QSGFlatColorMaterial>
#include <QSGTransformNode>
#include <QSGGeometryNode>
#include <QKeyEvent>
#include <QTransform>

const auto m_pi = 3.1415926f;

struct C_QSGNode{

    C_QSGNode(QSGTransformNode * transformNode,QSGGeometryNode * geometryNode,QSGFlatColorMaterial *material)
        :m_transformNode(transformNode),m_geometryNode(geometryNode),m_material(material)
    {
    };
    C_QSGNode(QSGTransformNode * transformNode,QSGTexture * texture)
        :m_transformNode(transformNode),m_texture(texture)
    {
    };

    void drawRectangle(QRectF rect){

        m_geometryNode->geometry()->vertexDataAsPoint2D()[0].set(rect.y(), rect.x());
        m_geometryNode->geometry()->vertexDataAsPoint2D()[1].set(rect.y() + rect.width(), rect.x());
        m_geometryNode->geometry()->vertexDataAsPoint2D()[2].set(rect.y() + rect.height(), rect.x() + rect.width());
        m_geometryNode->geometry()->vertexDataAsPoint2D()[3].set(rect.y(), rect.x() + rect.width());
        m_geometryNode->markDirty(QSGNode::DirtyMaterial | QSGNode::DirtyGeometry);
    };


    void moveRectangle(qreal x,qreal y){


        QTransform transform = QTransform::fromTranslate(x, y);
        qDebug()<<transform.dx()<<" - "<<transform.dy();
        //transform.scale(x,y);
        //transform.translate(y,x);
        m_transformNode->setMatrix(transform);
        m_transformNode->markDirty(QSGNode::DirtyMatrix);
    };

    void rotateRectangle(QPointF point, qreal angle){

        QTransform transform = QTransform::fromTranslate(point.x(), point.y()).rotate(angle);

        m_transformNode->setMatrix(transform);
        m_transformNode->markDirty(QSGNode::DirtyMatrix);
    };

    QSGTransformNode * m_transformNode{};
    QSGGeometryNode * m_geometryNode{};
    QSGFlatColorMaterial * m_material{};
    QSGTexture * m_texture{};
};

class ItemObject
{
public:
    ItemObject(C_QSGNode * node,Tank * tank);

    C_QSGNode * getQSGnode();


    Tank *getObject() const;
    void setObject(Tank *newObject);

    void setX(qreal x);
    void setY(qreal y);
    qreal x();
    qreal y();
    void setAngle(int angle);

    void setWidth(int width);
    void setHeight(int height);
    qreal width();
    qreal height();
    void moveObject(QKeyEvent *event);
    QPointF mapToParent();
    QPointF mapToParent(QPointF newP);
    void moveObject();
    void rotateObject();


private:
    Tank * object = nullptr;
    C_QSGNode * m_node = nullptr;

    float xR_(int aAngle)
    {
        return xR[aAngle];
    }
    float yR_(int aAngle)
    {
        return yR[aAngle];
    }

    qreal xx = 0;
    qreal yy = 0;
    float xR[361] = {0.f};
    float yR[361] = {0.f};
    void pre_calculate(){
        for(int i = 0; i <= 360; ++i)
        {
            qreal rads = i * M_PI / 180;
            xR[i] = 100 + (100 * std::cos(rads));
            yR[i] = 100 + (100 * std::sin(rads));
        }
    };

};

#endif // ITEMOBJECT_H
