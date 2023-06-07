#ifndef METEOROPRODUCTO_H
#define METEOROPRODUCTO_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <QDebug>


class meteoroproducto: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    meteoroproducto(int o, QGraphicsItem* carr = 0);
    void posicion(int x, int y);
    QTimer *timermp;


    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);
    int j=0;

private slots:
    void move();

private:
    QGraphicsRectItem *rect;
    int x;
    int y;
};

#endif // METEOROPRODUCTO_H
