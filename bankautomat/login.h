#ifndef LOGIN_H
#define LOGIN_H
#include "customer.h"
#include <QDialog>
#include "myurl.h"
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "dll_rfid.h"
#include <QTimer>
#include <QDebug>


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
    void receiveCardNumber(QString); //Kortinnumeron vastaanottaja slotti

private slots:
    void on_btnLogin_clicked(); //Salasanan syötön jälkeen tuleva kirjaudu toiminto
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

    short logintries;

};

#endif // LOGIN_H
