#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "myurl.h"
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDialog>
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
    void receiveWithdrawSignal(short);

private slots:
    void on_btnShowtransactions_clicked();
    void balanceSlot(QNetworkReply *reply);
    void on_nostoNappi_clicked();

private:
    Ui::Customer *ui;
    MyUrl *objectMyUrl;

    QNetworkAccessManager *balanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QByteArray webtoken;

    restapiDLL *pRestapiDLL;
};

#endif // CUSTOMER_H
