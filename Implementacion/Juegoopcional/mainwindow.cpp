#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(); //creamos la escena
    h_limit=1220;                   //Asigna el tamaño de la interfaz
    v_limit=720;
    scene->setSceneRect(0,0,h_limit, v_limit); // agaregamos el rectangulo

    ui->graphicsView->setScene(scene); // pintamos en rectangulo
    scene->addRect(scene->sceneRect());
    scene->setBackgroundBrush(QBrush(QImage(":/image/fondobosque.jpg")));


    rect = new obstaculo();
    rect->posiciono(400,450);
    scene->addItem(rect);

    hongo1 = new hongo();
    hongo1->posicion(180,v_limit-100);
    scene->addItem(hongo1);

    hongo2 = new hongo();
    hongo2->posicion(800,v_limit-100);
    scene->addItem(hongo2);

    arbol1 = new arbol();
    arbol1->posicion(400,v_limit-330);
    scene->addItem(arbol1);

    arbol2 = new arbol();
    arbol2->posicion(1000,v_limit-330);
    scene->addItem(arbol2);

    player = new personaje();
    player->actualizar(h_limit); //actualiza variables y le da la posicion
    scene->addItem(player);

    multiplicacionm= new multiplicacion();
    multiplicacionm->setPos(0,0);
    scene->addItem(multiplicacionm);

    timerll = new QTimer();
    connect(timerll, SIGNAL(timeout()),this,SLOT(lluvia()));
    timerll->start(1200);

    timerllp = new QTimer();
    connect(timerllp, SIGNAL(timeout()),this,SLOT(lluviap()));
    timerllp->start(10000);

    timerpro=new QTimer();
    connect(timerpro, SIGNAL(timeout()),this,SLOT(lluviaproduct()));
    timerpro->start(5000);

    timeres = new QTimer();
    connect(timeres, SIGNAL(timeout()),this,SLOT(lluviar()));


    timerp=new QTimer();
    connect(timerp, SIGNAL(timeout()),this,SLOT(actualizar()));
    timerp->start(10);

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


        if (player->collidesWithItem(hongo1) or player->collidesWithItem(hongo2)){
            b->set_posX(b->get_posX()-5);
            b->set_vel(0,0,b->get_posX()-5,b->get_posY());
            //b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY());

        }
    }

    if (event->key() == Qt::Key_A ){
        b->set_vel(-20,b->get_velY(),b->get_posX(), b->get_posY());

        if (player->collidesWithItem(hongo1) or player->collidesWithItem(hongo2)){
            b->set_posX(b->get_posX()+5);
            b->set_vel(0,0,b->get_posX()+5,b->get_posY());

            //b->set_vel(b->get_e()*b->get_velX(),b->get_velY(), b->get_Radio(), b->get_posY()) ;//con el borde izquierdo

        }
    }


    if (event->key() == Qt::Key_W){
        b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());
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
    int random_numberm=rand()%9;
    lluviam.push_back(new meteoro(random_numberm)); //escoge el numero que caera

    int random_number=rand()%1200;//posicion desde donde cae

    lluviam.last()->setX(random_number);
    lluviam.last()->setPos(lluviam.last()->getX(),0);
    //lluviam.last()->timerm ->start(40);

    scene->addItem(lluviam.last());
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
    //if(b->get_posY()>v_limit-100 && b->get_posX()>180 && b->get_posY()<280){
      //  b->set_vel(b->get_velX(),b->get_velY()+20,b->get_Radio(),b->get_posY());
    //}



    for(auto item:lluviam){//colisiones con el personaje y meteoros
        //item->timerm->start(40);

        if(item->collidesWithItem(player)) { //si toca un numero mal se queda quieto el personaje

            for(auto item:lluviam) item->timerm->stop();
            timerll->stop(); // si lo toca se para todo
            timerpro->stop();
            timerp->stop();
            timerllp->stop();
            timeres->start(2000);
            perder *perdiste=new perder();
            perdiste->setPos((h_limit/2)-200,(v_limit/2)-200);
            scene->addItem(perdiste);



        }
            /*
            timerp->stop();
            for(auto itemr: productos){ //cambia de color el resultado
                respuesta *resultado=new respuesta();
                resultado->posicion(itemr->getX(),itemr->getY());
                scene->addItem(resultado);
            }*/


        else if(item->collidesWithItem(arbol1) or item->collidesWithItem(arbol2)) item->timerm->stop();

        else if(item->getY()>v_limit-100){
                     //for(auto item: lluviam )
                     scene->removeItem(item);
                     lluviam.removeOne(item);
                 }
    }


    for(auto item2:poderm){ //colision con poder

        if(item2->collidesWithItem(player)) {
            scene->removeItem(item2);
            poderm.removeOne(item2);
            b->set_velX(b->get_velX()+60);

        }
        else if(item2->collidesWithItem(hongo1) or item2->collidesWithItem(hongo2)) item2->timermp->stop();

        else if(item2->getY()>v_limit-100){
            scene->removeItem(item2);
            poderm.removeOne(item2);
        }
    }

    for(auto item3 : productos){
        if(item3->collidesWithItem(player)){
            //codigo que de puntuaciom
            scene->removeItem(item3);
            productos.removeOne(item3);
        }
            else if(item3->getY()>v_limit-100){
            scene->removeItem(item3);
            productos.removeOne(item3);
            }
    }

}

void MainWindow::lluviap()
{
    poderm.push_back(new poder);

    int random_number=rand()%h_limit;//poner el tamño total de la pantalla menos lo que ida el enemigo de ancho
    cout << random_number;
    poderm.last()->setX(random_number);
    poderm.last()->setPos(poderm.last()->getX(),0);
    scene->addItem(poderm.last());


/*
    poder *meteorop= new poder();

    int random_number2=rand()%1200;//poner el tamño total de la pantalla menos lo que ida el enemigo de ancho
    cout << random_number2;
    meteorop->setPos(random_number2,0);
    scene->addItem(meteorop);
*/
}

void MainWindow::lluviaproduct()
{
    int random_number=rand()%h_limit;
    productos.push_back(new meteoroproducto(4));
    productos.last()->setX(random_number);
    productos.last()->setPos(productos.last()->getX(),0);
    scene->addItem(productos.last());
}

void MainWindow::lluviar()
{
    int random_number=rand()%h_limit;

    productosres.push_back(new respuesta);
    productosres.last()->setX(random_number);
    productosres.last()->setPos(productosres.last()->getX(),0);
    scene->addItem(productosres.last());
}

