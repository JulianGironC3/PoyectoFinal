#ifndef METEORO_H
#define METEORO_H
#include <QObject>
#include <QGraphicsRectItem>

#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <QDebug>

class meteoro: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    meteoro(int o,QGraphicsItem* carr = 0);

    float getX() const;
    void setX(float newX);

    float getY() const;
    void setY(float newY);

    void posicion(float x_, float y_);

private slots:
    void move();

private:
    float x;
    float y;
};

#endif // METEORO_H
