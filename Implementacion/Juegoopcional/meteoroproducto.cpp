#include "meteoroproducto.h"

meteoroproducto::meteoroproducto(int o, QGraphicsItem *carr)
{
    if(j==1) setPixmap(QPixmap(":/image/4Azul.png"));
    else{

        switch (o){
        /*case 0:  setPixmap(QPixmap(":/image/2.png"));
            break;
        case 1:  setPixmap(QPixmap(":/image/1.png"));
            break;
        case 2:  setPixmap(QPixmap(":/image/2.png"));
            break;
        case 3:  setPixmap(QPixmap(":/image/3.png"));
            break;*/
        case 4: setPixmap(QPixmap(":/image/4.png"));
            break;
        }
    }

    timermp =new QTimer();
    connect (timermp, SIGNAL(timeout()),this,SLOT(move()));
    timermp ->start(40);

    qDebug() << "relogp";
}

void meteoroproducto::posicion(int x, int y)
{
        setPos(x,y);
}

void meteoroproducto::move()
{
        x+=1.5;
        y+=5;
        setPos(x,y);
}

int meteoroproducto::getY() const
{
        return y;
}

void meteoroproducto::setY(int newY)
{
        y = newY;
}

int meteoroproducto::getX() const
{
        return x;
}

void meteoroproducto::setX(int newX)
{
        x = newX;
}
