#include "meteoro.h"

meteoro::meteoro(QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/image/meteoro.png"));

    //Conexion
    QTimer *timerm =new QTimer();
    connect (timerm, SIGNAL(timeout()),this,SLOT(move()));
    timerm ->start(50);

    qDebug() << "relog";
}

void meteoro::move()
{   x+=2;
    y+=5;
    posicion(x,y);
    qDebug() << "posicion";

    /*if(y>500){
        scene()->removeItem(this);
        delete this;}*/
}

float meteoro::getY() const
{
    return y;
}

void meteoro::setY(float newY)
{
    y = newY;
}

void meteoro::posicion(float x_, float y_)
{
    x=x_;
    y=y_;
    setPos(x,y);
}

float meteoro::getX() const
{
    return x;
}

void meteoro::setX(float newX)
{
    x = newX;
}
