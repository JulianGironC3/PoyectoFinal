#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>

#include "hongo.h"
#include "personaje.h"
#include "obstaculo.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    personaje *player;
    hongo *hon;
    obstaculo *o;


};
#endif // MAINWINDOW_H
