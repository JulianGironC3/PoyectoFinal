#include "obstaculo.h"

obstaculo::obstaculo(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/Images/unDestroyableBlock.png"));
}

void obstaculo::posiciono(int x, int y)
{
    setPos(x,y);
}
