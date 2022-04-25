#ifndef RESTAPIDLL_H
#define RESTAPIDLL_H

#include "restapiDLL_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QObject>
#include <QString>
#include <QDebug>


class RESTAPIDLL_EXPORT restapiDLL : public QObject
{
    Q_OBJECT
public:
    restapiDLL(QObject * parent = nullptr);
    ~restapiDLL();
    void withdrawal(QString,QString);
     void getBalance(QString id);

    QString getBase_url() const;

signals:
    void withDrawalSignalToExe(QByteArray);
    void balanceSignal(QString);


private slots:
    void withDrawalSlot(QNetworkReply *reply);
    void getBalanceSlot(QNetworkReply *reply);


private:
    QNetworkAccessManager *withDrawalManager;
    QNetworkReply *reply;
    QByteArray response_Data;
    QString base_url;
    QNetworkAccessManager *getBalanceManager;
    QByteArray webtoken;


};

#endif // RESTAPIDLL_H
