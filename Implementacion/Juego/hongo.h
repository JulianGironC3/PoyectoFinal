#ifndef HONGO_H
#define HONGO_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class hongo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    hongo(QGraphicsItem* carr = 0);
/*
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
*/
    void posiciono(float x_,float y_);

private:
    QGraphicsRectItem *rect;

};

#endif // HONGO_H
