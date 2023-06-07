#include "multiplicacion.h"

multiplicacion::multiplicacion(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/image/unnamed.png"));
}

void multiplicacion::posicion(int x, int y)
{
    setPos(x,y);
}
