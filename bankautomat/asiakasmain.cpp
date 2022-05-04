#include "asiakasmain.h"
#include "ui_asiakasmain.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include "nosto.h"
#include <QNetworkAccessManager>
#include <QJsonDocument>



AsiakasMain::AsiakasMain(QString asiUsername, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AsiakasMain)
{
    ui->setupUi(this);
    ui->labelUsername->setText(asiUsername);
    username=asiUsername;
    username=asiUsername;
    webtoken=token;
    //ui->labelAsiakasId->setText(asiId);
    //ui->labelStudentId->setText(token);
    objectMyUrl=new MyUrl;
    pSaldo = new Saldo;

}

AsiakasMain::~AsiakasMain()
{
    delete ui;
    delete pNosto;
    delete pSaldo;
    delete pTilitapahtumat;
}

void AsiakasMain::on_btnWitdraw_clicked()
{
    pNosto = new Nosto(username);
    pNosto->setWebtoken(webtoken);
    pNosto->exec();
}


void AsiakasMain::on_btnShowmoney_clicked()
{
    QString site_url=objectMyUrl->getBase_url()+"/tili/saldo/"+username;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU

    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    showmoneyManager = new QNetworkAccessManager(this);
    connect(showmoneyManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(showmoneySlot(QNetworkReply*)));
    reply = showmoneyManager->get(request);

    //pSaldo->exec();

    //response_data=reply->readAll();
   // qDebug()<<response_data;
   // ui->Raha->setText(response_data+"€");
}

void AsiakasMain::showmoneySlot(QNetworkReply *reply)
{
            response_data=reply->readAll();
           qDebug()<< response_data;
           QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
           QJsonArray json_array = json_doc.array();
           QString Saldo;
           foreach (const QJsonValue &value, json_array) {
               QJsonObject json_obj = value.toObject();
               Saldo+=json_obj["idTili"].toString()+json_obj["Tilinumero"].toString()+QString::number(json_obj["Saldo"].toDouble())+"\r";
           }
    ui->Raha->setText(Saldo+"€");

}


void AsiakasMain::on_btnShowdetails_clicked()
{
    QString site_url=objectMyUrl->getBase_url()+"/Tilitapahtumat/tilitapahtumat/1";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU

    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    detailsManager = new QNetworkAccessManager(this);
    connect(detailsManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(detailsSlot(QNetworkReply*)));
    reply = detailsManager->get(request);


}
void AsiakasMain::detailsSlot(QNetworkReply *reply)
    {
        response_data=reply->readAll();
        qDebug()<<response_data;
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonArray json_array = json_doc.array();

            foreach (const QJsonValue &value, json_array) {
                QJsonObject json_obj = value.toObject();
                tilitapahtuma+=QString::number(json_obj["idTilitapahtuma"].toInt())+" | "+json_obj["Paivays"].toString()+" | "+json_obj["Tapahtuma"].toString()+" | "+QString::number(json_obj["Summa"].toDouble())+"\r";
            }
            qDebug()<<"Tapahtuma="+tilitapahtuma;
            pTilitapahtumat = new Tilitapahtumat(tilitapahtuma);
            pTilitapahtumat->show();
}


void AsiakasMain::on_btnLogout_clicked()
{
this->close();


}









