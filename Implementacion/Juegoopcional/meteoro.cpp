#include "meteoro.h"

meteoro::meteoro(int o,QGraphicsItem *carr)
{
    //setPixmap(QPixmap(":/image/meteoro.png"));

    switch (o){
    case 0:  setPixmap(QPixmap(":/image/0.png"));
        break;
    case 1:  setPixmap(QPixmap(":/image/1.png"));
        break;
    case 2:  setPixmap(QPixmap(":/image/2.png"));
        break;
    case 3:  setPixmap(QPixmap(":/image/3.png"));
        break;
    // 4:  setPixmap(QPixmap(":/image/4.png"));
       // break;
    case 5:  setPixmap(QPixmap(":/image/5.png"));
        break;
    case 6:  setPixmap(QPixmap(":/image/6.png"));
        break;
    case 7:  setPixmap(QPixmap(":/image/7.png"));
        break;
    case 8:  setPixmap(QPixmap(":/image/8.png"));
        break;
    case 9:  setPixmap(QPixmap(":/image/9.png"));
        break;
    }


    //Conexion
    timerm =new QTimer();
    connect (timerm, SIGNAL(timeout()),this,SLOT(move()));
    qDebug() << "relog";
    timerm->start(40);
}

void meteoro::move()
{   x+=1.5;
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
