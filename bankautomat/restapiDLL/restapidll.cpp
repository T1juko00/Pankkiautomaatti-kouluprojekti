#include "restapidll.h"

restapiDLL::restapiDLL(QObject *parent) : QObject(parent)
{
    qDebug() << "Rest api dll constructor";
    base_url="http://localhost:3001";

}

QString restapiDLL::getBase_url() const
{
    return base_url;
}
restapiDLL::~restapiDLL()
{
    qDebug()<<"RESTAPI DLL destructor";
}


void restapiDLL::getBalance(QString id)
{
    QString kalle;
    qDebug()<< "getBalanceFunc()";
    QString site_url=getBase_url()+"/customer/balance/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    request.setRawHeader(QByteArray("Authorization"),(webtoken));


    getBalanceManager = new QNetworkAccessManager(this);
    connect(getBalanceManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(getBalanceSlot(QNetworkReply*)));
    reply = getBalanceManager->get(request);

}


void restapiDLL::getBalanceSlot(QNetworkReply *reply)
{
    qDebug()<< "getBalanceSlot()";
    response_Data = reply ->readAll();
    qDebug()<<response_Data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_Data);
        QJsonArray json_array = json_doc.array();
        QString balance;
        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            balance+=json_obj["fname"].toString()+"|"+json_obj["lname"].toString()+"|"+QString::number(json_obj["id_account"].toInt())+"|"+QString::number(json_obj["balance"].toInt())+"\r";

            QString site_url="http://localhost:3001";
            site_url+"/account/withdraw20/"+2;
            QNetworkRequest request((site_url));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        }

        qDebug()<<balance;
        QString site_url="http://localhost:3001";
        site_url+"/transactions/"+2;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

       emit balanceSignal(balance);
}

void restapiDLL::withdrawal(QString id_account, QString amount)
{
        qDebug()<< "withdrawal account" <<id_account << "amount: " << amount;
        QJsonObject jsonObj;
        jsonObj.insert("id_account", id_account); //acc id
        jsonObj.insert("balance", amount); //withdrawal amount
        QString site_url="http://localhost:3001/account/withdrawlog";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        withDrawalManager = new QNetworkAccessManager(this);

        connect(withDrawalManager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(withDrawalSlot(QNetworkReply*)));

        reply = withDrawalManager->post(request, QJsonDocument(jsonObj).toJson());
}



void restapiDLL::withDrawalSlot(QNetworkReply *reply)
{
        qDebug()<< "withdrawalSlot()";
        response_Data=reply->readAll();
        qDebug()<<response_Data;
        emit withDrawalSignalToExe(response_Data);
        reply->deleteLater();
        withDrawalManager->deleteLater();
}




