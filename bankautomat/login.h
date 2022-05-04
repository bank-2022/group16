#ifndef LOGIN_H
#define LOGIN_H

#include "myurl.h"

#include <QDialog>
#include <asiakasmain.h>
#include <asiakasmain.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnLogin_clicked();
    void loginSlot (QNetworkReply *reply);

private:
    Ui::Login *ui;
    QString Korttinumero;
    QString PIN;
    QString id;
    AsiakasMain *objectAsiakasMain;
    MyUrl *objectMyUrl;
    QString base_url;


    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;


};

#endif // LOGIN_H
