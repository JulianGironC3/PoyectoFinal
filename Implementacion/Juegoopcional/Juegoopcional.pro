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
    multiplicacion.cpp \
    obstaculo.cpp \
    perder.cpp \
    personaje.cpp \
    personaje2.cpp \
    poder.cpp \
    respuesta.cpp

HEADERS += \
    arbol.h \
    hongo.h \
    mainwindow.h \
    meteoro.h \
    meteoroproducto.h \
    movimientos.h \
    multiplicacion.h \
    obstaculo.h \
    perder.h \
    personaje.h \
    personaje2.h \
    poder.h \
    respuesta.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imge.qrc \
    imge.qrc

DISTFILES += \
    .gitignore \
    image/0.png \
    image/1.png \
    image/2.png \
    image/3.png \
    image/4.png \
    image/5.png \
    image/5542.png_860.png \
    image/6.png \
    image/7.png \
    image/8.png \
    image/9.png \
    image/Producto.png \
    image/asset-generation-5ab129bf-d3fa-4b03-ad18-d6201f48ae00-3-small.jpg \
    image/asset-generation-edefd626-2631-4eb9-9d5e-bae60f6dc727-3-small.jpg \
    image/destroyableBlock.png \
    image/fondo-plano-naturaleza.jpg \
    image/fondo2.jpg \
    image/fondobosque.jpg \
    image/meteoro.png \
    image/personaje.png \
    image/personajeC.png \
    image/personajeizq.png \
    image/png-clipart-animation-cartoon-cartoon-tree-template-child.png \
    image/pngtree-cute-cartoon-mushroom-png-image_4270983.png \
    image/pngtree-cute-meteor-clip-art-png-image_2736145.jpg
