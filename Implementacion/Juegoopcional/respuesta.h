#ifndef RESPUESTA_H
#define RESPUESTA_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <QDebug>


class respuesta: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    respuesta( QGraphicsItem* carr = 0);
    void posicion(int x_, int y_);
    QTimer *timermp;


    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

private slots:
    void move();

private:
    QGraphicsRectItem *rect;
    int x;
    int y;
};

#endif // RESPUESTA_H
