#include "restapidll.h"


restapiDLL::restapiDLL(QString baseUrl)
{
    pdrawDLL = new drawDLL(baseUrl);

    connect(pdrawDLL,SIGNAL(withdrawSignalToExe),
            this,SLOT(withdrawSlot(QJsonObject)));
}

restapiDLL::~restapiDLL()
{
    delete pdrawDLL;
    pdrawDLL = nullptr;

}

void restapiDLL::withdrawExe(double amount)
{
    pdrawDLL->DLLslot(amount);
}

void restapiDLL::withdrawSlot(QJsonObject result)
{
    emit withdrawSignalToExe(result);
}
