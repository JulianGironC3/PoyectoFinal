#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(); //creamos la escena
    h_limit=1250;                   //Asigna el tamaño de la interfaz
    v_limit=600;
    scene->setSceneRect(0,0,h_limit, v_limit); // agaregamos el rectangulo

    ui->graphicsView->setScene(scene); // pintamos en rectangulo
    scene->addRect(scene->sceneRect());
    scene->setBackgroundBrush(QBrush(QImage(":/image/fondo-plano-naturaleza.jpg")));

    timerll = new QTimer();
    connect(timerll, SIGNAL(timeout()),this,SLOT(lluvia()));
    timerll->start(1000);

    timerp=new QTimer();
    connect(timerp, SIGNAL(timeout()),this,SLOT(actualizar()));
    timerp->start(6);

    player = new personaje();
    player->actualizar(h_limit); //actualiza variables y le da la posicion
    scene->addItem(player);

    rect = new obstaculo();
    rect->posiciono(400,450);
    scene->addItem(rect);

    hongo1 = new hongo();
    hongo1->posicion(250,450);
    scene->addItem(hongo1);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    movimientos *b = player->getEsf();
    if (event->key() == Qt::Key_D ){
        b->set_vel(20,b->get_velY(),b->get_posX(), b->get_posY());
    }
    if (event->key() == Qt::Key_A ){
        b->set_vel(-20,b->get_velY(),b->get_posX(), b->get_posY());
    }
    if (event->key() == Qt::Key_W){
        b->set_vel(b->get_velX(),40,b->get_posX(), b->get_posY());
    }
/*
    V = pow(((VX*VX)+(VY*VY)),1/2);
    angulo = atan2(VY, VX);
    AX = -((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo);
    AY = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))-G;
    PX = PX + (VX*dt) + ((AX*(dt*dt))/2);
    PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
{
    if(event->key()== Qt::Key_D and player->getPx()<650){
        player->set_velp(20,player->getVy(),player->getPx(),player->getPy());
        //player->set_vel(10,player->getVy(),player->getPx(),player->getPy());
    }

    if(event->key()== Qt::Key_A and player->getPx()>0){
        player->set_velp(-20,player->getVy(),player->getPx(),player->getPy());        //player->set_vel(-10,player->getVy(),player->getPx(),player->getPy());
    }

    if(event->key()== Qt::Key_Space ){
        player->set_velp(player->getVx(),40,player->getPx(),player->getPy());        //player->set_vel(-10,player->getVy(),player->getPx(),player->getPy());
    }

    //player->posicion();

    player->actualizar();*/
}

void MainWindow::actualizar()
{
    player->actualizar(v_limit);
    bordescollision(player->getEsf());
}

void MainWindow::lluvia()
{
    meteoro *meteoro1= new meteoro();

    int random_number=rand()%700;//poner el tamño total de la pantalla menos lo que ida el enemigo de ancho
    cout << random_number;
    meteoro1->setX(random_number);
    meteoro1->setPos(meteoro1->getX(),0);
    scene->addItem(meteoro1);
}

void MainWindow::bordescollision(movimientos *b)
{
    if(b->get_posX()<0){
        b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
    }
    if(b->get_posX()>h_limit-b->get_Radio()){//posicion con el borde derecho.
        b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());
    }
    if(b->get_posY()<b->get_Radio()){//choque con el borde superior.
        b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
    }
    if(b->get_posY()>v_limit){//choque con el borde inferior.
        b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), v_limit-b->get_Radio());
    }
}

