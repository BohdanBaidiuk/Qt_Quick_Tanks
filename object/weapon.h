#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QVector>


class Weapon:public QObject
{
    Q_OBJECT
public:
    Weapon(QObject *parent = nullptr);
private:
    int m_count_bullet{};
};

#endif // WEAPON_H
