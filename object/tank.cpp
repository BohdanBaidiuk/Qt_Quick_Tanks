#include "tank.h"

Tank::Tank(QObject *parent) : DynamicObject(parent)
{

}

int Tank::bulletCount() const
{
    return m_bulletCount;
}

void Tank::setBulletCount(int newBulletCount)
{
    m_bulletCount = newBulletCount;
}
