#include "personaje2.h"

personaje2::personaje2(QObject *parent): QObject{parent}
{
    timer = new QTimer();
    filas=0;
    columnas=0;

    pixmap = new QPixmap(":/image/personajeC.png");

}

void personaje2::actualizacion()
{

}
