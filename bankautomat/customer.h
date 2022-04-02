#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "myurl.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDialog>

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QString CustUsername,QString Customerid,QByteArray token, QWidget *parent = nullptr);
    ~Customer();

private slots:
    void on_btnShowtransactions_clicked();
    void balanceSlot(QNetworkReply *reply);

private:
    Ui::Customer *ui;
    MyURL *objectMyURL;

    QNetworkAccessManager *balanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QByteArray webtoken;
};

#endif // CUSTOMER_H
