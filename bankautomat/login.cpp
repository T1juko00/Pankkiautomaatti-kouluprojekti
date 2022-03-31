#include "login.h"
#include "ui_login.h"
#include <QDebug>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    objectMyURL = new MyURL;
    base_url=objectMyURL->getBase_url();

}

Login::~Login()
{
    delete ui;
    ui=nullptr;
    delete objCustomerMain;
    objCustomerMain=nullptr;
}

void Login::on_btnLogin_clicked()
{
    //qDebug()<<"base_url="+base_url;
    username=ui->leUsername->text();
    password=ui->lePassword->text();

    //Pekan materiaaleista
    QJsonObject jsonObj;
    jsonObj.insert("username",username);
    jsonObj.insert("password",password);

    QNetworkRequest request((base_url+"/login"));

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    if(response_data!="false") {
    token ="Bearer "+response_data;
    id="7";
    objCustomerMain=new Customer(username,id,token);
    objCustomerMain->show();
    }
    else{
        ui->leUsername->setText("");
        ui->lePassword->setText("");
    }
}

