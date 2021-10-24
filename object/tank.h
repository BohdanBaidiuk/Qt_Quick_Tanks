#ifndef TANK_H
#define TANK_H

#include "dynamicobject.h"
#include "weapon.h"
#include <QVector>

class Tank : public DynamicObject
{
public:
    explicit Tank(QObject *parent = nullptr);

    int bulletCount() const;
    void setBulletCount(int newBulletCount);

private:
    int m_bulletCount{};
    QVector<Weapon> m_veapon{};
};

#endif // TANK_H
