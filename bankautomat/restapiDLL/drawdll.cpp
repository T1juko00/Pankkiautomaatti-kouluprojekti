#include "drawdll.h"


drawDLL::drawDLL(QString baseUrl)
{
    this->baseUrl=baseUrl;

}

drawDLL::~drawDLL()
{
    delete accManager;
    accManager = nullptr;
    delete reply;
    reply = nullptr;
}

QJsonObject drawDLL::replyToJsonObject(QNetworkReply *reply)
{
    QByteArray responseData = reply->readAll();
        QJsonObject jsonObj = QJsonDocument::fromJson(responseData).object();
        return jsonObj;
}

void drawDLL::DLLslot(double amount)
{
    QJsonObject jsonObj;
    jsonObj.insert("amount", amount);

    QNetworkRequest req((baseUrl + "/withdraw/100"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    accManager = new QNetworkAccessManager(this);
    connect(accManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

    reply = accManager->post(req, QJsonDocument(jsonObj).toJson());
}

void drawDLL::ReSlot(QNetworkReply * reply)
{
    emit withdrawSignalToDLL(replyToJsonObject(reply));
}
