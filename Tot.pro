QT+= core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    health.cpp \
    main.cpp \
    scene.cpp \
    score.cpp \
    unit/enemy/enemy.cpp \
    unit/enemy/heavysoldier.cpp \
    unit/enemy/saboteur.cpp \
    unit/enemy/solder.cpp \
    unit/item.cpp \
    weapon/bullet/bullet.cpp \
    weapon/bullet/grenade.cpp \
    weapon/bullet/gun.cpp \
    weapon/bullet/knife.cpp \
    weapon/bullet/weapon.cpp \
    weapon/bullet/weaponmachine.cpp

HEADERS += \
    game.h \
    health.h \
    scene.h \
    score.h \
    unit/enemy/enemy.h \
    unit/enemy/heavysoldier.h \
    unit/enemy/saboteur.h \
    unit/enemy/solder.h \
    unit/item.h \
    weapon/bullet/bullet.h \
    weapon/bullet/grenade.h \
    weapon/bullet/gun.h \
    weapon/bullet/knife.h \
    weapon/bullet/weapon.h \
    weapon/bullet/weaponmachine.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
