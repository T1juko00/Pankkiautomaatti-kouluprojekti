#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    objLogin=new Login;
}

MainWindow::~MainWindow()
{
    delete prestapi;
    prestapi = nullptr;
    delete ui;
    delete objLogin;
    ui=nullptr;
    objLogin=nullptr;

}


void MainWindow::on_btnLogin_clicked()
{
    objLogin->show();
}



