#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include "dll_rfid.h"
#include "restapidll.h"
#include <QMainWindow>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *objQTimer;

private slots:
    void on_btnLogin_clicked(); //Kirjaudu sisään nappi
    void TimerSlot(); //Automaattisen ajastin sulkijan slotti

private:
    Ui::MainWindow *ui;
    Login *objLogin;
    restapiDLL *prestapi;

    short timerCounter;



};
#endif // MAINWINDOW_H
