#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsItem>


#include "personaje.h"
#include "obstaculo.h"
#include "hongo.h"
#include "meteoro.h"
#include "poder.h"
#include "arbol.h"
#include "meteoroproducto.h"
#include "multiplicacion.h"
#include "respuesta.h"
#include "perder.h"

#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void keyPressEvent(QKeyEvent *event);
    void actualizar();
    void lluvia();
    void bordescollision(movimientos *b);
    void lluviap();
    void lluviaproduct();
    void lluviar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    multiplicacion *multiplicacionm;
    obstaculo *rect;
    personaje *player;
    arbol *arbol1;
    arbol *arbol2;
    hongo *hongo1;
    hongo *hongo2;
    QTimer *timerll;
    QTimer *timerp;
    QTimer *timerllp;
    QTimer *timeres;
    QTimer *timerpro;
    int h_limit;                //longitud en X del mundo
    int v_limit;
    QList<meteoro*> lluviam; //meteoros lluvia
    QList<poder*> poderm;
    QList<meteoroproducto*> productos;
    QList<respuesta*> productosres;





};
#endif // MAINWINDOW_H
