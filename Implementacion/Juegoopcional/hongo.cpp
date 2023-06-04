#include "hongo.h"

hongo::hongo(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/image/pngtree-cute-cartoon-mushroom-png-image_4270983.png"));


}

void hongo::posicion(int x, int y)
{
    setPos(x,y);
}
