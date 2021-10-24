#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "baseobject.h"

class DynamicObject : public BaseObject
{
public:
    explicit DynamicObject(QObject *parent = nullptr);
    int scrore() const;
    void setScrore(int newScrore);

    int weight() const;
    void setWeight(int newWeight);

private:
    int m_scrore{};
    int m_weight{};
};

#endif // DYNAMICOBJECT_H
