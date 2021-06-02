QT += core
QT += gui
QT += quick
QT += qml


CONFIG += c++17


SOURCES += \
    main.cpp \
    object/object.cpp \
    object/tank.cpp

HEADERS += \
    object/object.h \
    object/tank.h

FORMS +=


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    qml.qrc
