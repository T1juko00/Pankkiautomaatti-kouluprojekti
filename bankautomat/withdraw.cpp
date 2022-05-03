#include "withdraw.h"
#include "ui_withdraw.h"


withdraw::withdraw(QWidget *parent) : QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
    prestapi = new restapiDLL;
    pCreateValueDraw = new createValueDraw;

    connect(prestapi,SIGNAL(withDrawalSignalToExe(QByteArray)),
            this,SLOT(receiveSignalFromRestApi(QByteArray)));

}

withdraw::~withdraw()
{
    delete prestapi;
    delete ui;
    delete pCreateValueDraw;
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
    pCreateValueDraw->exec();
}

