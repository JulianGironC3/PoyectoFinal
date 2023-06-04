#include "personaje.h"


personaje::personaje()
{
    //imagen de 45x50
    //setPixmap(QPixmap(":/image/asset-generation-edefd626-2631-4eb9-9d5e-bae60f6dc727-3-small.jpg"));
    //scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fondo")));
    //ellipse = new QGraphicsEllipseItem(0,0,100,100);
    //ellipse->setStartAngle(90*16);
    //ellipse->setSpanAngle(270*16);
    float posx, posy, velx , vely ,r, mass, K, e;
    posx = 0;
    posy = 150;
    r = 50;
    mass = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.2;
    esf = new movimientos(posx,posy,velx,vely,mass,r,K,e);
    qDebug()<< "peronaje";
}

personaje::~personaje()
{
    delete esf;
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::cyan);        //asigna el color
    //painter->drawRect (boundingRect());    //dibuja una elipse encerrada en la boundingRect
    QPixmap qpixmap(":/image/asset-generation-edefd626-2631-4eb9-9d5e-bae60f6dc727-3-small.jpg");
    painter->drawPixmap(0,0,50,50,qpixmap);
}

QRectF personaje::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void personaje::setEscala(float s)
{
    escala=s;
}


void personaje::actualizar(float v_lim)
{//actualiza variables y posiciones
    esf->actualizar();
    setPos(esf->get_posX(),(v_lim-esf->get_posY()));




/*
    v = pow(((vx*vx)+(vy*vy)),1/2);
    angulo = atan2(vy/vx);
    ax = -((1/(2))*pow(v,2)*(50*50)*0.1)*cos(angulo);
    ay = (-((1/(2))*pow(v,2)*(50*50)*0.1)*cos(angulo))-g;
    px = px+(vx*dt)+((ax*pow(dt,2))/2);
    py = py+(vy*dt)+((ay*pow(dt,2))/2);
    vx = vx+ax*dt;
    vy = vy+ay*dt;

    posicion(px,py);
    vy=vy-g*dt;
    px+= vx*dt;
    py+= vy*dt;
    setPos(px,py);*/


}
movimientos *personaje::getEsf()
{
    return esf;
}

