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
            this,SLOT(receiveBalanceSignalFromRestApi(QString)));
}

Customer::~Customer()
{
    delete ui;
    delete pwith;
    pwith = nullptr;
}

void Customer::receiveSignal()
{


}

void Customer::on_btnshowBalance_clicked()
{
    prestApi->getBalance("id");

}

void Customer::receiveBalanceSignalFromRestApi(QString s)
{
    ui->textBalance->setText(s);
}


void Customer::transSlot(QNetworkReply *reply)
{
    response_data = reply ->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString transactions;
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            transactions+=json_obj["date"].toString()+"|"+json_obj["events"].toString()+"|"+QString::number(json_obj["amount"].toInt())+"|"+json_obj["accountnumber"].toString()+"|"+QString::number(json_obj["cardnumber"].toInt())+"\r";


            QString site_url=objectMyUrl->getBase_url()+"/transactions/transactions/1/";
            QNetworkRequest request((site_url));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        }

        qDebug()<<transactions;

        QString site_url=objectMyUrl->getBase_url()+"/transactions/transactions/1/";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        ui->textBalance->setText(transactions);

}

void Customer::on_btnTrans_clicked()
{
    QString site_url=objectMyUrl->getBase_url()+"/transactions/transactions/1/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    request.setRawHeader(QByteArray("Authorization"),(webtoken));


    transManager = new QNetworkAccessManager(this);
    connect(transManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(transSlot(QNetworkReply*)));
    reply = transManager->get(request);


}


void Customer::on_nostoNappi_clicked()
{
    connect(pwith,SIGNAL(signalToWithdraw()),
            this,(SLOT(receiveSignal)));
    pwith->exec();

}






