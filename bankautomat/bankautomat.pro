QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    asiakasmain.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    myurl.cpp \
    nosto.cpp \
    saldo.cpp \
    tilitapahtumat.cpp

HEADERS += \
    asiakasmain.h \
    login.h \
    mainwindow.h \
    myurl.h \
    nosto.h \
    saldo.h \
    tilitapahtumat.h

FORMS += \
    asiakasmain.ui \
    login.ui \
    mainwindow.ui \
    nosto.ui \
    saldo.ui \
    tilitapahtumat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
