#ifndef DRAWDLL_H
#define DRAWDLL_H

#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkReply>
#include "restapidll.h"

class drawDLL : public restapiDLL
{
    Q_OBJECT
public:
    explicit drawDLL();
    explicit drawDLL (QObject *parent = nullptr);
    ~drawDLL();
    void withdraw(double amount)override;

private:
    QJsonObject replyToJsonObject(QNetworkReply *reply);
    QString baseUrl;
    QNetworkAccessManager *accManager;
    QNetworkReply *reply;
    QByteArray responseData;


private slots:
    void Replyslot(QNetworkReply * reply);

};

#endif // DRAWDLL_H
