#ifndef RESTAPIDLL_H
#define RESTAPIDLL_H

#include "restapiDLL_global.h"
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>


class RESTAPIDLL_EXPORT restapiDLL : public QObject
{
    Q_OBJECT
public:
    static restapiDLL *instance();
    explicit restapiDLL (QObject *parent = nullptr);
    ~restapiDLL();
    virtual void withdraw(double amount)=0;



signals:

   void withdrawSignalToExe(QJsonObject result);


};

#endif // RESTAPIDLL_H
