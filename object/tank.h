#ifndef TANK_H
#define TANK_H

#include <QImage>
#include <QObject>
#include <QSGSimpleTextureNode>
#include <QSGTransformNode>

class Tank : QObject
{

public:
    explicit Tank();
    QImage image;
    QSGTransformNode * transformNode = nullptr;
    QSGSimpleTextureNode * textureNode = nullptr;
};

#endif // TANK_H
