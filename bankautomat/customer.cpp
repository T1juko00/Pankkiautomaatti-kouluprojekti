#include "customer.h"
#include "ui_customer.h"


Customer::Customer(QString CustUsername, QString Customerid, QByteArray token, QWidget *parent) :
QDialog(parent),
ui(new Ui::Customer)
{
    ui->setupUi(this);
    ui->labelUsername->setText(CustUsername);
    //ui->labelCustomerid->setText(Customerid);
    ui->labelCustomerid->setText(token);
}

Customer::~Customer()
{
    delete ui;
}

void Customer::on_btnShowtransactions_clicked()
{

}
