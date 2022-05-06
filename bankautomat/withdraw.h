#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "restapidll.h"
#include <QDialog>
#include "myurl.h"
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "createvaluedraw.h"



namespace Ui {
class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:

    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();
    QTimer *objQTimer;

public slots:
    void receiveSignalFromRestApi(QByteArray);

private slots:
    void on_pushButton_20_clicked(); //20e nosto nappi
    void on_pushButton_40_clicked(); //40e nosto nappi
    void on_pushButton_60_clicked(); //60e nosto nappi
    void on_pushButton_100_clicked(); //100e nosto nappi
    void on_lopetaIstunto_clicked(); //Sulje nosto tapahtumat nappi
    void on_muuSumma_button_clicked(); //Valinnaisen summan tapahtuma (avaa uuden ikkunan)

private:

    Ui::withdraw *ui;
    restapiDLL *prestapi;
    QString value;
    short timerCountTwo;
    createValueDraw *pCreateValueDraw;


};

#endif // WITHDRAW_H
