#include "createvaluedraw.h"
#include "ui_createvaluedraw.h"
#include "QJsonObject"

createValueDraw::createValueDraw(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::createValueDraw)
{
    ui->setupUi(this);
    prestapi = new restapiDLL;
}

createValueDraw::~createValueDraw()
{
    delete ui;
    delete prestapi;
    prestapi = nullptr;
}

void createValueDraw::on_nostaButton_clicked()
{
    //Valinnaisen nosto tapahtuman toteutus

    value = ui->lineEdit->text();
    QJsonObject jsonObj;
    jsonObj.insert("amount",value);
    prestapi->withdraw("1",value);
    ui->lineEdit->setText("Nosto onnistui, ota rahat automaatista! | "+value+"e");
}


void createValueDraw::on_closeButton_clicked()
{
    //Valinnaisen nosto tapahtuman "SULJE" nappi

    this->close();
}

