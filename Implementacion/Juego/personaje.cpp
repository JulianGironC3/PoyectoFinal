#include "personaje.h"

personaje::personaje(QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/imagenes/asset-generation-edefd626-2631-4eb9-9d5e-bae60f6dc727-3-small.jpg"));
}

float personaje::getPx() const
{
    return px;
}

void personaje::setPx(float newPx)
{
    px = newPx;
}

float personaje::getPy() const
{
    return py;
}

void personaje::setPy(float newPy)
{
    py = newPy;
}

float personaje::getVx() const
{
    return vx;
}

void personaje::setVx(float newVx)
{
    vx = newVx;
}

float personaje::getVy() const
{
    return vy;
}

void personaje::setVy(float newVy)
{
    vy = newVy;
}

float personaje::getAx() const
{
    return ax;
}

void personaje::setAx(float newAx)
{
    ax = newAx;
}

float personaje::getAy() const
{
    return ay;
}

void personaje::setAy(float newAy)
{
    ay = newAy;
}

void personaje::posicion()
{
    setPos(px,py);
}

void personaje::posicion(int newX, int newY)
{
    px=newX;
    py=newY;
    setPos(px,py);
}

void personaje::set_vel(float velx, float vely, float px_, float py_)
{

}

void personaje::actualizar()
{


}
