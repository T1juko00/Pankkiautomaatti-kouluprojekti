QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    customer.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    myurl.cpp \
    withdraw.cpp

HEADERS += \
    card.h \
    customer.h \
    login.h \
    mainwindow.h \
    myurl.h \
    withdraw.h

FORMS += \
    card.ui \
    customer.ui \
    login.ui \
    mainwindow.ui \
    withdraw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32: LIBS += -L$$PWD/DLL_RFID/build/debug/ -lDLL_RFID

INCLUDEPATH += $$PWD/DLL_RFID
DEPENDPATH += $$PWD/DLL_RFID


win32: LIBS += -L$$PWD/restapiDLL/build/debug/ -lrestapiDLL

INCLUDEPATH += $$PWD/restapiDLL
DEPENDPATH += $$PWD/restapiDLL
