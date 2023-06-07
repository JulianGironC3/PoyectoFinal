#include "respuesta.h"

respuesta::respuesta(QGraphicsItem *carr)
{

    setPixmap(QPixmap(":/image/4Azul.png"));

    timermp =new QTimer();
    connect (timermp, SIGNAL(timeout()),this,SLOT(move()));
    timermp ->start(40);

    qDebug() << "relogp";
}

void respuesta::posicion(int x_, int y_)
{
    setPos(x_,y_);
}

int respuesta::getX() const
{
    return x;
}

void respuesta::setX(int newX)
{
    x = newX;
}

int respuesta::getY() const
{
    return y;
}

void respuesta::setY(int newY)
{
    y = newY;
}

void respuesta::move()
{
    x+=1.5;
    y+=5;
    setPos(x,y);
}
