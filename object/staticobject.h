#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "baseobject.h"

class StaticObject : public BaseObject
{
public:
    explicit StaticObject(QObject *parent = nullptr);
    bool getIsDectroed() const;
    void setIsDectroed(bool newIsDectroed);

private:
    bool isDectroed{};
};

#endif // STATICOBJECT_H
