#include "arbol.h"

arbol::arbol(QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/image/png-clipart-animation-cartoon-cartoon-tree-template-child.png"));

}

void arbol::posicion(int x, int y)
{
    setPos(x,y);
}
