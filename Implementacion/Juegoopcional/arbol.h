#ifndef ARBOL_H
#define ARBOL_H

#include <QObject>
#include <QGraphicsRectItem>

class arbol: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    arbol(QGraphicsItem* carr = 0);
    void posicion(int x, int y);

private:
    QGraphicsRectItem *rect;
};

#endif // ARBOL_H
