#ifndef ASIAKASMAIN_H
#define ASIAKASMAIN_H

#include "myurl.h"
#include "nosto.h"
#include "saldo.h"
#include "ui_saldo.h"
#include "tilitapahtumat.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class AsiakasMain;
}

class AsiakasMain : public QDialog
{
    Q_OBJECT

public:
    explicit AsiakasMain(QString asiUsername, QByteArray token, QWidget *parent = nullptr);
    ~AsiakasMain();

private slots:
    void on_btnWitdraw_clicked();

    void on_btnShowmoney_clicked();

    void on_btnShowdetails_clicked();

    void on_btnLogout_clicked();
    void detailsSlot(QNetworkReply *reply);
    void showmoneySlot(QNetworkReply *reply);


private:
    Ui::AsiakasMain *ui;
    MyUrl *objectMyUrl;
    Nosto * pNosto;
    Saldo * pSaldo;
    Tilitapahtumat * pTilitapahtumat;
    QNetworkAccessManager *detailsManager;
    QNetworkAccessManager *showmoneyManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QByteArray webtoken;
QString tilitapahtuma;

};

#endif // ASIAKASMAIN_H
