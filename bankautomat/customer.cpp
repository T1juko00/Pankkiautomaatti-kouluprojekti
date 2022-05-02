#include "customer.h"
#include "ui_customer.h"


Customer::Customer(QString CustUsername, QString Customerid, QByteArray token, QWidget *parent) :
QDialog(parent),
ui(new Ui::Customer)
{
    ui->setupUi(this);
    username = CustUsername;
    webtoken = token;
    ui->labelCustomerid->setText(Customerid);
    ui->labelCustomerid->setText(token);
    objectMyUrl = new MyUrl;
    pwith = new withdraw;
    prestApi = new restapiDLL;

    connect(prestApi,SIGNAL(balanceSignal(QString)),
            this,SLOT(receiveBalanceSignalFromRestApi(QString))); //Signaali luotu saldo näkymälle

    connect(prestApi,SIGNAL(sendTransactionsToExe(QString)),
            this,SLOT(receiveTransactionsSignal(QString))); //Signaali luotu tilitapahtumalle
}

Customer::~Customer()
{
    delete ui;
    delete pwith;
    pwith = nullptr;
}

void Customer::on_btnshowBalance_clicked()
{
    prestApi->getBalance("id");

}

void Customer::receiveBalanceSignalFromRestApi(QString s)
{
    ui->textBalance->setText(s);
}

void Customer::receiveTransactionsSignal(QString s)
{
    ui->textBalance->setText(s);
}



void Customer::on_btnTrans_clicked()
{
    prestApi->getTransactions("1");
}


void Customer::on_nostoNappi_clicked()
{

    pwith->exec();

}

void Customer::on_closeButton_clicked()
{
    this->close();
}

