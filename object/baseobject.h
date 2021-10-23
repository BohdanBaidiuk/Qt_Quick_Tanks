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

private:
    QRectF m_body{};
    bool m_crahsed{};
    int m_health{};

};

#endif // BASEOBJECT_H
