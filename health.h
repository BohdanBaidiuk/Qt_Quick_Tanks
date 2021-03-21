#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>


class Health:public QGraphicsTextItem
{
public:
    Health(QGraphicsItem *parent = nullptr);
    void decrease();
    int getHearth() const;

private:
    int health = 3;
};

#endif // HEALTH_H
