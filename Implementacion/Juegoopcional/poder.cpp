#include "poder.h"

poder::poder(QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/image/5542.png_860.png"));

    QTimer *timermp =new QTimer();
    connect (timermp, SIGNAL(timeout()),this,SLOT(move()));
    timermp ->start(40);

    qDebug() << "relogp";

}

void poder::posicion(int x_, int y_)
{
    xx=x_;
    yy=y_;
    setPos(x_,y_);
}

void poder::move()
{
    setPos(x()+1.5,y()+5);
}

int poder::getY() const
{
    return yy;
}

void poder::setY(int newY)
{
    yy = newY;
}

int poder::getX() const
{
    return xx;
}

void poder::setX(int newX)
{
    xx = newX;
}
