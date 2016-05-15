#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1000,563);//adjust the size of background
    settingBg(10,563);//set the photogroud
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg(int x_start , int y_end)
{
    QImage bg;
    bg.load(":/image/img/startpage.jpg");
    bg = bg.scaled(1000,y_end);
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init(x_start);
}
