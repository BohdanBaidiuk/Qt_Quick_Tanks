#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QObject>
#include <QPointF>
#include <QRectF>
#include <QSizeF>

class BaseObject : public QObject
{
    Q_OBJECT
public:
    explicit BaseObject(QObject *parent = nullptr);

    const QRectF &body() const;
    void setBody(const QRectF &newBody);

    short health() const;
    void setHealth(short newHealth);

    void setX(qreal x);
    void setY(qreal y);

    qreal angle() const;
    void setAngle(qreal newAngle);

private:
    QRectF m_body{};
    short m_health{};
    qreal m_angle{};

};

#endif // BASEOBJECT_H
