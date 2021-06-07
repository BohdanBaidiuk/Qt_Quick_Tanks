QT += core
QT += gui
QT += quick
QT += qml


CONFIG += c++17


SOURCES += \
    appcore.cpp \
    main.cpp \
    object/baseobject.cpp \
    object/bullet.cpp \
    object/dynamicobject.cpp \
    object/map.cpp \
    object/staticobject.cpp \
    scene.cpp

HEADERS += \
    appcore.h \
    object/baseobject.h \
    object/bullet.h \
    object/dynamicobject.h \
    object/map.h \
    object/staticobject.h \
    scene.h

FORMS +=


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    qml.qrc
