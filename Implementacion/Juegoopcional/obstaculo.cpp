#include "obstaculo.h"

obstaculo::obstaculo(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/image/destroyableBlock.png"));
}

void obstaculo::posiciono(int x, int y)
{
    setPos(x,y);
}
