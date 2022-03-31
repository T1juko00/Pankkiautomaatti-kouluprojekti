#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QString CustUsername,QString Customerid,QByteArray token, QWidget *parent = nullptr);
    ~Customer();

private slots:
    void on_btnShowtransactions_clicked();

private:
    Ui::Customer *ui;
};

#endif // CUSTOMER_H
