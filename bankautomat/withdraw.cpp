#include "withdraw.h"
#include "ui_withdraw.h"


withdraw::withdraw(QWidget *parent) : QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
    prestapi = new restapiDLL;
    connect(prestapi,SIGNAL(withDrawalSignalToExe(QByteArray)),
            this,SLOT(receiveSignalFromRestApi(QByteArray)));

}

withdraw::~withdraw()
{
   delete prestapi;
    delete ui;
}

void withdraw::receiveSignalFromRestApi(QByteArray)
{

}



void withdraw::on_pushButton_20_clicked()
{

    emit signalToWithdraw();
    prestapi->withdrawal("1","20");
    ui->lineEdit->setText("Nosto onnistui, 20 euroa");
}


void withdraw::on_pushButton_40_clicked()
{
    prestapi->withdrawal("1","40");
    ui->lineEdit->setText("Nosto onnistui, 40 euroa");
}


void withdraw::on_pushButton_60_clicked()
{
    prestapi->withdrawal("1","60");
    ui->lineEdit->setText("Nosto onnistui, 60 euroa");

}


void withdraw::on_pushButton_100_clicked()
{
    prestapi->withdrawal("1","100");
    ui->lineEdit->setText("Nosto onnistui, 100 euroa");

}


void withdraw::on_lopetaIstunto_clicked()
{
    this->close();
}



void withdraw::receiveSignalFromRestapi(QString s)
{
    ui->lineEdit->setText(s);

}
