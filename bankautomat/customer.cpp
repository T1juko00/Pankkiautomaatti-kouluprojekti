#include "customer.h"
#include "ui_customer.h"


Customer::Customer(QString CustUsername, QString Customerid, QByteArray token, QWidget *parent) :
QDialog(parent),
ui(new Ui::Customer)
{
    ui->setupUi(this);
    //ui->labelUsername->setText(CustUsername);
    username = CustUsername;
    webtoken = token;
    ui->labelCustomerid->setText(Customerid);
    ui->labelCustomerid->setText(token);
    objectMyUrl = new MyUrl;
}

Customer::~Customer()
{
    delete ui;
}

void Customer::on_btnShowtransactions_clicked()
{
    QString site_url=objectMyUrl->getBase_url()+"/customer/balance/"+username;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    request.setRawHeader(QByteArray("Authorization"),(webtoken));


    balanceManager = new QNetworkAccessManager(this);
    connect(balanceManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(balanceSlot(QNetworkReply*)));
    reply = balanceManager->get(request);

}

void Customer::balanceSlot(QNetworkReply *reply)
{
    response_data = reply ->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString balance;
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            balance+=json_obj["fname"].toString()+"|"+json_obj["lname"].toString()+"|"+QString::number(json_obj["id_account"].toInt())+"|"+QString::number(json_obj["balance"].toInt())+"\r";


            QString site_url=objectMyUrl->getBase_url()+"/account/withdraw20/"+2;
            QNetworkRequest request((site_url));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        }

        qDebug()<<balance;

        QString site_url=objectMyUrl->getBase_url()+"/transactions/"+2;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        ui->textBalance->setText(balance);

}
