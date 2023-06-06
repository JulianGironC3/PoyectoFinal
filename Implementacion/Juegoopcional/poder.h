#ifndef PODER_H
#define PODER_H

#include <QObject>
#include <QGraphicsRectItem>

#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <QDebug>

class poder: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    poder(QGraphicsItem* carr = 0);
    void posicion(int x_, int y_);


    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

private slots:
    void move();

private:
    QGraphicsRectItem *rect;
    int xx;
    int yy;
};

#endif // PODER_H
