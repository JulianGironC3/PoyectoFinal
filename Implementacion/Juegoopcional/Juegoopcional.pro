QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arbol.cpp \
    hongo.cpp \
    main.cpp \
    mainwindow.cpp \
    meteoro.cpp \
    meteoroproducto.cpp \
    movimientos.cpp \
    obstaculo.cpp \
    personaje.cpp \
    poder.cpp

HEADERS += \
    arbol.h \
    hongo.h \
    mainwindow.h \
    meteoro.h \
    meteoroproducto.h \
    movimientos.h \
    obstaculo.h \
    personaje.h \
    poder.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imge.qrc

DISTFILES += \
    image/asset-generation-5ab129bf-d3fa-4b03-ad18-d6201f48ae00-3-small.jpg \
    image/asset-generation-edefd626-2631-4eb9-9d5e-bae60f6dc727-3-small.jpg \
    image/destroyableBlock.png \
    image/pngtree-cute-cartoon-mushroom-png-image_4270983.png
