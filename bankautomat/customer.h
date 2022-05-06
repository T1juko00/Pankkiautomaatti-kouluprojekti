#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "myurl.h"
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDialog>
#include "withdraw.h"
#include "restapidll.h"



namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QString CustUsername,QString Customerid,QByteArray token, QWidget *parent = nullptr);
    ~Customer();

public slots:
    void receiveBalanceSignalFromRestApi(QString); //Saldo näkymän signaali
    void receiveTransactionsSignal(QString); //Tilitapahtumien signaali

private slots:
    void on_nostoNappi_clicked(); //Nosto tapahtuman "PushButton"
    void on_btnshowBalance_clicked(); //Saldo näkymän "PushButton"
    void on_btnTrans_clicked(); //Tilipahtumien "PushButton"

    void on_closeButton_clicked(); //Kirjaudu ulos "SULJE" toiminto

private:
    Ui::Customer *ui;
    MyUrl *objectMyUrl;

    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *transManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QByteArray webtoken;
    withdraw *pwith;
    restapiDLL *prestApi;
};

#endif // CUSTOMER_H
