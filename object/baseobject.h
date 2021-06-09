#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QObject>
#include <QPointF>

class BaseObject : public QObject
{
    Q_OBJECT
public:
    explicit BaseObject(QObject *parent = nullptr);

    QPointF point() const;
    void setPoint(QPointF newPoint);

    int health() const;
    void setHealth(int newHealth);

    int height() const;
    void setHeight(int newHeight);

    int width() const;
    void setWidth(int newWidth);

signals:

private:
    QPointF m_point{};
    int m_health{};
    int m_width{};
    int m_height{};
};

#endif // BASEOBJECT_H
