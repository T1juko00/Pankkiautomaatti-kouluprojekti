#ifndef DRAWDLL_H
#define DRAWDLL_H

#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkReply>

class drawDLL : public QObject
{
    Q_OBJECT
public:
    drawDLL(QString baseUrl);
    ~drawDLL();

private:
    QJsonObject replyToJsonObject(QNetworkReply *reply);
    QString baseUrl;
    QNetworkAccessManager *accManager;
    QNetworkReply *reply;
    QByteArray responseData;
    QByteArray token;

signals:

    void withdrawSignalToDLL(QJsonObject result);  // TODO


public slots:

    void DLLslot(double amount);

private slots:
    void ReSlot(QNetworkReply * reply);

};

#endif // DRAWDLL_H
