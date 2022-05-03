#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    objLogin = new Login;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objLogin;
    ui=nullptr;
    objLogin=nullptr;

}



void MainWindow::on_btnLogin_clicked()
{
    objLogin->show();

    objLogin->show();
        ui->setupUi(this);
            timerCounter=0;

            objQTimer = new QTimer();
            connect(objQTimer, SIGNAL(timeout()),
                    this, SLOT(TimerSlot()));

            objQTimer->start(1000);
}

void MainWindow::TimerSlot()
{
    //qDebug() << "Timer:"<<timerCounter;
    timerCounter++;

    if(timerCounter==20)
        {
            objQTimer->stop();
            delete objQTimer;
            objQTimer = nullptr;
            this->close();
            delete ui;
            objLogin->close();

        }
}
