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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    obstaculo *rect;
    personaje *player;
    hongo *hongo1;
    QTimer *timerll;
    QTimer *timerp;
    int h_limit;                //longitud en X del mundo
    int v_limit;
    QList<meteoro*> lluviam;




};
#endif // MAINWINDOW_H
