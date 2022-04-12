#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QList>

class engine : public QObject
{
    Q_OBJECT
public:
    engine(QObject * parent = nullptr);
    ~engine();
    void open(void);
signals:
    void sendSignalToInterface(QString);
public slots:
    void cardnumberRead();
private:
    QSerialPort * pQSerialPort;
    QSerialPortInfo *pQSerialPortInfo;
    QByteArray readData;
};

#endif // ENGINE_H
