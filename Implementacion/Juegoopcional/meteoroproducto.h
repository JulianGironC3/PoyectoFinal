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
    meteoroproducto(QGraphicsItem* carr = 0);
    void posicion(int x, int y);


private slots:
    void move();

private:
    QGraphicsRectItem *rect;
};

#endif // METEOROPRODUCTO_H
