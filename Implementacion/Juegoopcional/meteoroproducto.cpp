#include "meteoroproducto.h"

meteoroproducto::meteoroproducto(QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/image/Producto.png"));

    QTimer *timermp =new QTimer();
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
    setPos(x()+1.5,y()+5);
}
