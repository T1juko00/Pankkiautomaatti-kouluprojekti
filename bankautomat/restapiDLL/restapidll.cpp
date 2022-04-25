#include "restapidll.h"



restapiDLL *restapiDLL::instance()
{
   /* pdrawDLL = new drawDLL;

    connect(pdrawDLL,SIGNAL(withdrawSignalToExe),
            this,SLOT(withdrawSlot(QJsonObject)));*/
}

restapiDLL::restapiDLL(QObject *parent) : QObject(parent)
{

}

restapiDLL::~restapiDLL()
{
    /*delete pdrawDLL;
    pdrawDLL = nullptr;*/
    qDebug()<<"ollaan destructor ";

}

