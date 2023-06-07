#include "arbol.h"

arbol::arbol(QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/image/Arbol.png"));

}

void arbol::posicion(int x, int y)
{
    setPos(x,y);
}
