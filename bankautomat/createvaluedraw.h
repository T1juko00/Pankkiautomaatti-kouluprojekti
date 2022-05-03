#ifndef CREATEVALUEDRAW_H
#define CREATEVALUEDRAW_H

#include <QDialog>
#include "restapidll.h"

namespace Ui {
class createValueDraw;
}

class createValueDraw : public QDialog
{
    Q_OBJECT

public:
    explicit createValueDraw(QWidget *parent = nullptr);
    ~createValueDraw();

private slots:
    void on_nostaButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::createValueDraw *ui;
    QString value;
    restapiDLL *prestapi;
};

#endif // CREATEVALUEDRAW_H
