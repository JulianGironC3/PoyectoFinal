#ifndef PERDER_H
#define PERDER_H
#include <QObject>
#include <QGraphicsRectItem>


class perder: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    perder(QGraphicsItem* carr = 0);

private:
    QGraphicsRectItem *rect;
};

#endif // PERDER_H
