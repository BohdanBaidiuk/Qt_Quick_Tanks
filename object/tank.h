#ifndef TANK_H
#define TANK_H

#include <QImage>
#include <QObject>
#include <QSGSimpleTextureNode>
#include <QSGTransformNode>
#include <utility>

struct PhysicalParameters
{
  int power = 0;
  int speed = 0;
};


class Tank : QObject
{

public:
    explicit Tank();
    QImage image;
    QSGTransformNode * transformNode = nullptr;
    QSGSimpleTextureNode * textureNode = nullptr;
    const std::pair<int, int> &coordinate() const;
    void setCoordinate(const std::pair<int, int> &newCoordinate);

    int getAngle() const;
    void setAngle(int newAngle);

private:
    std::pair<int,int> m_coordinate;
    int angle = 0;
    PhysicalParameters m_params;
};

#endif // TANK_H
