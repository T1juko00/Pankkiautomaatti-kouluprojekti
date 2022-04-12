#include "engine.h"

engine::engine(QObject *parent) : QObject(parent)
{
    pQSerialPort = new QSerialPort;
    pQSerialPortInfo = new QSerialPortInfo;
}

engine::~engine()
{
    pQSerialPort->close();
    delete pQSerialPort;
    pQSerialPort = nullptr;
    delete pQSerialPortInfo;
    pQSerialPortInfo = nullptr;

}

void engine::open()
{
    QList<QSerialPortInfo> ports = pQSerialPortInfo->availablePorts();
    qDebug()<<"free ports = "<<ports.count();
    QSerialPortInfo firstPort;
    if(ports.count() > 0)
    {
        qDebug()<<"reading first port ";
        firstPort = ports.first();

    }
    else {
        qDebug()<<"no connection";
        return;
    }
    pQSerialPort->setPortName("COM6");
    pQSerialPort->setBaudRate(9600);
    pQSerialPort->setDataBits(QSerialPort::Data8); //Databittien määrä kussakin merkissä on 8. Sitä käytetään useimmille datatyypeille, koska tämä koko vastaa tavun kokoa.
    if (!pQSerialPort->open(QIODevice::ReadWrite))
        {
            qDebug()<<"tried to open serial port but didnt open"<< Qt::endl;
        }

    qDebug()<<"Serial port opened, press user button";
    connect(pQSerialPort,SIGNAL(readyRead()),   //readyRead= This signal is emitted once every time new data is available for reading from the device's current read channel.
            this,SLOT(cardnumberRead()));       //It will only be emitted again once new data is available.
    readData.clear();
}


void engine::cardnumberRead()
{ 
    readData.append(pQSerialPort->readAll()); // readALL = Reads all remaining data from the device, and returns it as a byte array.
    QString data = QString::fromUtf8(readData); // utf8 = Palauttaa QStringin, joka on alustettu UTF-8-merkkijonolla
    if(readData.length() == 16)
        {
            qDebug()<<"koko datan koko = "<<readData.length(); //16
            qDebug()<<"koko luettu data = "<<data; // AAAAAAA/BBBBB/CCCCCCC
            data = data.mid(0,1); // kortinlukija arvo, aluta 4 merkkiä pois ja lopusta 3
            emit  sendSignalToInterface(data);
            return;
       }

}
