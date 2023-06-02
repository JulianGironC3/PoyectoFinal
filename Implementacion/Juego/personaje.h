#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#define g 10
#define dt 1
class personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje(QGraphicsItem* carr = 0);

    float getPx() const;
    void setPx(float newPx);

    float getPy() const;
    void setPy(float newPy);

    float getVx() const;
    void setVx(float newVx);

    float getVy() const;
    void setVy(float newVy);

    float getAx() const;
    void setAx(float newAx);

    float getAy() const;
    void setAy(float newAy);

    void posicion();
    void posicion(int newX, int newY);

    void set_vel(float velx, float vely, float px_, float py_);
    void actualizar();

private:
    float px=0;
    float py=0;
    float vx=0;
    float vy=0;
    float ax=0;
    float ay=0;
};

#endif // PERSONAJE_H
