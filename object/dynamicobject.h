#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "baseobject.h"

class DynamicObject : public BaseObject
{
public:
    explicit DynamicObject(QObject *parent = nullptr);
    int angle() const;
    void setAngle(int newAngle);

    int scrore() const;
    void setScrore(int newScrore);


private:
    int m_angle{};
    int m_scrore{};


};

#endif // DYNAMICOBJECT_H
