#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "restapidll.h"
#include <QDialog>
#include "myurl.h"
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>



namespace Ui {
class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:

    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();
signals:
    void signalToWithdraw();

public slots:
    void receiveSignalFromRestApi(QByteArray);

private slots:
    void on_pushButton_20_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_60_clicked();
    void on_pushButton_100_clicked();
    void on_lopetaIstunto_clicked();


public slots:

    void receiveSignalFromRestapi(QString);

private:

    Ui::withdraw *ui;
    restapiDLL *prestapi;



};

#endif // WITHDRAW_H
