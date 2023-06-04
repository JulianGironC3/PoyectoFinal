#ifndef HONGO_H
#define HONGO_H

#include <QObject>
#include <QGraphicsRectItem>


class hongo: public QObject, public QGraphicsPixmapItem
{
        Q_OBJECT
public:
    hongo(QGraphicsItem* carr = 0);
    void posicion(int x, int y);

private:
    QGraphicsRectItem *rect;
};

#endif // HONGO_H
