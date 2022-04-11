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


    //WEBTOKEN ALKU

    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

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
            balance+=json_obj["fname"].toString()+"|"+json_obj["lname"].toString()+"|"+QString::number(json_obj["cardnumber"].toInt())+"|"+QString::number(json_obj["balance"].toInt())+"\r";
        }

        qDebug()<<balance;

        ui->textBalance->setText(balance);
}
