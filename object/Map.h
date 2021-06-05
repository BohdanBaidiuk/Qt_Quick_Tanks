#ifndef MAP_H
#define MAP_H

#include <QQuickItem>
#include <QSGTransformNode>
#include <utility>
#include "tank.h"

class Map : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)


public:
    explicit Map(QQuickItem *parent = nullptr);

    int width() const;
    void setWidth(int newWidth);

    int height() const;
    void setHeight(int newHeight);

signals:
    void widthChanged();

    void heightChanged();

private:
    std::pair<int,int> coordinate;
    QVector<Tank *> tanks;
    QVector<QSGTransformNode*> _transformNodes;
    int m_width;
    int m_height;

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAP_H
