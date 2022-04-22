#include "drawdll.h"

drawDLL::drawDLL()
{
    baseUrl="http://localhost:3001";
    qDebug()<<"ollaan constructor ";
}

drawDLL::drawDLL(QObject *parent) : restapiDLL(parent)
{
    baseUrl="http://localhost:3001";
    qDebug()<<"ollaan constructor1 ";
    accManager = new QNetworkAccessManager(this);
    connect(this->accManager,&QNetworkAccessManager::finished,
            this,&drawDLL::replyToJsonObject);
}

drawDLL::~drawDLL()
{
    delete accManager;
    accManager = nullptr;
    delete reply;
    reply = nullptr;
    qDebug()<<"ollaan destructor 2 ";
}

void drawDLL::withdraw(double amount)
{
    QJsonObject jsonObj;
    jsonObj.insert("amount", amount);


    QNetworkRequest req((baseUrl + "/withdraw/100"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    this->accManager->post(req, QJsonDocument(jsonObj).toJson());
}

QJsonObject drawDLL::replyToJsonObject(QNetworkReply *reply)
{
        QByteArray responseData = reply->readAll();
        QJsonObject jsonObj = QJsonDocument::fromJson(responseData).object();
        return jsonObj;

}

void drawDLL::Replyslot(QNetworkReply * reply)
{
     QJsonDocument jsonDoc;
     QJsonObject jsonObj;
     QByteArray responseData = reply->readAll();            //lukee kaiken datan
     jsonDoc = QJsonDocument::fromJson(responseData);       //vastaanottaa dataa
     jsonObj = jsonDoc.object();

    emit withdrawSignalToExe(replyToJsonObject(reply));
}
