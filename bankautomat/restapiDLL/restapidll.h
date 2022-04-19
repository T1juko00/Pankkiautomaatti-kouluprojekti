#ifndef RESTAPIDLL_H
#define RESTAPIDLL_H

#include "restapiDLL_global.h"
#include <QObject>
#include <QJsonArray>
#include "drawdll.h"

class RESTAPIDLL_EXPORT restapiDLL : public QObject
{
    Q_OBJECT
public:
    restapiDLL(QString baseUrl);
    ~restapiDLL();

private:
   drawDLL * pdrawDLL;

signals:

   void withdrawSignalToExe(QJsonObject result);


public slots:

   void withdrawExe(double amount);


private slots:
   void withdrawSlot(QJsonObject result);
};

#endif // RESTAPIDLL_H
