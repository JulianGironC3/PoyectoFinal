#include "hongo.h"

hongo::hongo(QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/imagenes/destroyableBlock.png"));

}
/*
QRectF hongo::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void hongo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap qpixmap(":/imagenes/asset-generation-edefd626-2631-4eb9-9d5e-bae60f6dc727-3-small.jpg");
    painter->drawPixmap(0,0,50,50,qpixmap);
}*/

void hongo::posiciono(float x, float y)
{
    setPos(x,y);
}
