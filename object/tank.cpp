#include "tank.h"

Tank::Tank()
{

}

const std::pair<int, int> &Tank::coordinate() const
{
    return m_coordinate;
}

void Tank::setCoordinate(const std::pair<int, int> &newCoordinate)
{
    m_coordinate = newCoordinate;
}

int Tank::getAngle() const
{
    return angle;
}

void Tank::setAngle(int newAngle)
{
    angle = newAngle;
}
