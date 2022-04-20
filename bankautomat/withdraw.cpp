#include "withdraw.h"
#include "ui_withdraw.h"


withdraw::withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
   /*prestapi->withdrawExe(20);
    connect(prestapi,SIGNAL(withdrawSignalToExe(QJsonObject)),
            this,SLOT(receiveSignalFromRestapi(QString)));*/
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_pushButton_20_clicked()
{

    emit signalToWithdraw();
    ui->lineEdit->setText("Nosto onnistui, 20 euroa");
}


void withdraw::on_pushButton_40_clicked()
{

}


void withdraw::on_pushButton_60_clicked()
{

}


void withdraw::on_pushButton_100_clicked()
{

}


void withdraw::on_lopetaIstunto_clicked()
{
    this->close();
}


void withdraw::on_muuSumma_clicked()
{

}

void withdraw::receiveSignalFromRestapi(QString s)
{
    ui->lineEdit->setText(s);

}
