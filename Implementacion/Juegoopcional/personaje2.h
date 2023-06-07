#ifndef PERSONAJE2_H
#define PERSONAJE2_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>

class personaje2 : public QObject, public QGraphicsItem
{
    Q_OBJECT //110x110
public:
    explicit personaje2(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas; //matriz imagen
    float ancho, alto; //personaje



signals:

public slots:
    void actualizacion();

};

#endif // PERSONAJE2_H
