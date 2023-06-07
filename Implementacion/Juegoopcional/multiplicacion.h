#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H
#include <QObject>
#include <QGraphicsRectItem>


class multiplicacion: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    multiplicacion(QGraphicsItem* carr = 0);
    void posicion(int x, int y);

private:
        QGraphicsRectItem *rect;
};

#endif // MULTIPLICACION_H
