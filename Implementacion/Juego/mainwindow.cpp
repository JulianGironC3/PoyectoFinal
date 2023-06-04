#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(); //creamos la escena

    scene->setSceneRect(0,0,700,500); // agaregamos el rectangulo
    ui->graphicsView->setScene(scene); // pintamos en rectangulo
    scene->addRect(scene->sceneRect());
    //scene->setBackgroundBrush(QBrush(QImage(":/imagenes/asset-generation-5ab129bf-d3fa-4b03-ad18-d6201f48ae00-3-small.jpg")));



    player = new personaje();
    player->posicion(0,0);
    scene->addItem(player);

    //obstaculos
    hon = new hongo();
    hon->posiciono(100,0);
    scene->addItem(hon);

    o = new obstaculo();
    o->posiciono(50,50);
    scene->addItem(o);








}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)

/*
    V = pow(((VX*VX)+(VY*VY)),1/2);
    angulo = atan2(VY, VX);
    AX = -((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo);
    AY = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))-G;
    PX = PX + (VX*dt) + ((AX*(dt*dt))/2);
    PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt; */
{
    if(event->key()== Qt::Key_D and player->getPx()<650){
         player->setPx(player->getPx()+10);
        //player->set_vel(10,player->getVy(),player->getPx(),player->getPy());
    }

    if(event->key()== Qt::Key_A and player->getPx()>0){
        player->setPx(player->getPx()-10);
        //player->set_vel(-10,player->getVy(),player->getPx(),player->getPy());
    }

    player->posicion();

    //player->actualizar();
}

