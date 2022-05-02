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
    prestapi->withdrawal("1","20");
    ui->lineEdit->setText("Nosto onnistui, ota rahat automaatista! | 20e");
}


void withdraw::on_pushButton_40_clicked()
{
    prestapi->withdrawal("1","40");
    ui->lineEdit->setText("Nosto onnistui, ota rahat automaatista! | 40e");
}


void withdraw::on_pushButton_60_clicked()
{
    prestapi->withdrawal("1","60");
    ui->lineEdit->setText("Nosto onnistui, ota rahat automaatista! | 60e");

}


void withdraw::on_pushButton_100_clicked()
{
    prestapi->withdrawal("1","100");
    ui->lineEdit->setText("Nosto onnistui, ota rahat automaatista! | 100e");

}


void withdraw::on_lopetaIstunto_clicked()
{
    this->close();
}

void withdraw::on_muuSumma_button_clicked()
{
    value = ui->lineEdit->text();
        QJsonObject jsonObj;
        jsonObj.insert("amount",value);
        prestapi->withdrawal("1",value);
         ui->lineEdit->setText("Nosto onnistui, ota rahat automaatista! | "+value);
}

