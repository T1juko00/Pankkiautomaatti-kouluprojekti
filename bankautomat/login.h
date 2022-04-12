#ifndef LOGIN_H
#define LOGIN_H
#include<customer.h>
#include <QDialog>
#include <myurl.h>
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "dll_rfid.h"


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:
    void receiveCardNumber(QString);
private slots:
    void on_btnLogin_clicked();
    void loginSlot(QNetworkReply *reply);

private:
    Ui::Login *ui;
    QString username;
    QString password;
    QString id;
    Customer *objCustomerMain;
    MyUrl *objectMyUrl;
    QString base_url;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
    DLL_RFID *pDLLRFID;




};

#endif // LOGIN_H
