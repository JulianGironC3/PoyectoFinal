#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include "movimientos.h"
#include <time.h>       /* time */

#include <QDebug>

#define g 10
#define dt 0.2
class personaje :public QGraphicsItem
{
public:
    personaje();
    ~personaje();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void setEscala(float s);
    void actualizar(float v_lim);
    movimientos *getEsf();

private:

    movimientos* esf;
    float escala;


};

#endif // PERSONAJE_H
