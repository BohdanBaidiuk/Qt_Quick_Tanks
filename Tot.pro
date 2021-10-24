QT += core
QT += gui
QT += quick
QT += qml


CONFIG += c++17


SOURCES += \
    appcore.cpp \
    itemobject.cpp \
    main.cpp \
    object/baseobject.cpp \
    object/bullet.cpp \
    object/dynamicobject.cpp \
    object/map.cpp \
    object/staticobject.cpp \
    object/tank.cpp \
    object/weapon.cpp \
    scene.cpp

HEADERS += \
    appcore.h \
    itemobject.h \
    object/baseobject.h \
    object/bullet.h \
    object/dynamicobject.h \
    object/map.h \
    object/staticobject.h \
    object/tank.h \
    object/weapon.h \
    scene.h

FORMS +=


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    object_json.qrc \
    qml.qrc
