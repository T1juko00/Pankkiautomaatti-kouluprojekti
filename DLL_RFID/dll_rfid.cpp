#include "dll_rfid.h"

DLL_RFID::DLL_RFID(QObject *parent): QObject(parent)
{
   qDebug()<<"DLL luotu";
   pEngine = new engine(this);
   connect(pEngine,SIGNAL(sendSignalToInterface(QString)),
           this,SLOT(receiveSignalFromEngine(QString)));
}

DLL_RFID::~DLL_RFID()

{

    qDebug()<<"DLL tuhottu";
    disconnect(pEngine,SIGNAL(sendSignalToInterface(QString)),
            this,SLOT(receiveSignalFromEngine(QString)));
    delete pEngine;
    pEngine = nullptr;

}

void DLL_RFID::OpenRFIDReader()
{

    pEngine->open();

}

void DLL_RFID::receiveSignalFromEngine(QString s)
{
    emit sendSignalToExe(s);
}






