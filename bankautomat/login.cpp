#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    objectMyUrl = new MyUrl;
    base_url=objectMyUrl->getBase_url();
    pDLLRFID = new DLL_RFID;
    pDLLRFID->OpenRFIDReader();
    logintries = 0;

    connect(pDLLRFID,SIGNAL(sendSignalToExe(QString)),
            this,SLOT(receiveCardNumber(QString))); //Signaali luotu RFID-lukijan DLL kautta

}

Login::~Login()
{
    delete pDLLRFID;
    pDLLRFID=nullptr;
    delete ui;
    ui=nullptr;
    delete objCustomerMain;
    objCustomerMain=nullptr;
}

void Login::receiveCardNumber(QString s)
{
    ui->leUsername->setText(s);
}


void Login::on_btnLogin_clicked()
{
   qDebug()<<"base_url="+base_url;

   username=ui->leUsername->text();
   password=ui->lePassword->text();

    //Pekan materiaaleista

    QJsonObject jsonObj;
    jsonObj.insert("username",username);
    jsonObj.insert("password",password);

    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug()<<response_data;
    if(response_data!="false") {
    token ="Bearer "+response_data;
    id="2";
    objCustomerMain=new Customer(username,id,token);
    objCustomerMain->show();
    }
    else {
        ui->leUsername->setText("");
        ui->lePassword->setText("");

        qDebug() <<"Logintries:" <<logintries;
        logintries = logintries +1;

        if(logintries ==3){
            qDebug() <<"Kortinnumero tai PIN-koodi on väärä!";
            this->~Login();
        }

        }
    }
