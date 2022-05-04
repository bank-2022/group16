#include "nosto.h"
#include "ui_nosto.h"
#include <QDebug>

Nosto::Nosto(QString username,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nosto)
{
    pusername=username;
    ui->setupUi(this);


}

Nosto::~Nosto()
{
    delete ui;
}

void Nosto::on_btnnostosulje_clicked()
{
    qDebug()<<webtoken;
    this->close();

}

const QByteArray &Nosto::getWebtoken() const
{
    return webtoken;
}

void Nosto::setWebtoken(const QByteArray &newWebtoken)
{
    webtoken = newWebtoken;
}


void Nosto::on_btn20e_clicked()
{
    QJsonObject jsonObj;
        amount = 20;
        qDebug()<<amount;
        jsonObj.insert("amount", amount);
        QString site_url="http://localhost:3000/tili/saldo/nosto/1";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(webtoken));
        nostoManager = new QNetworkAccessManager(this);
        connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
        ui->nostettuLabel->setText("20€ nostettu.");
}

void Nosto::nostoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
      qDebug()<<response_data;
}


void Nosto::on_btn40e_clicked()
{
    QJsonObject jsonObj;
        amount = 40;
        qDebug()<<amount;
        jsonObj.insert("amount", amount);
        QString site_url="http://localhost:3000/tili/saldo/nosto/1";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(webtoken));
        nostoManager = new QNetworkAccessManager(this);
        connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
        ui->nostettuLabel->setText("40€ nostettu.");
}


void Nosto::on_btn60e_clicked()
{
    QJsonObject jsonObj;
        amount = 60;
        qDebug()<<amount;
        jsonObj.insert("amount", amount);
        QString site_url="http://localhost:3000/tili/saldo/nosto/1";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(webtoken));
        nostoManager = new QNetworkAccessManager(this);
        connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
        ui->nostettuLabel->setText("60€ nostettu.");
}


void Nosto::on_btn100e_clicked()
{
    QJsonObject jsonObj;
        amount = 100;
        qDebug()<<amount;
        jsonObj.insert("amount", amount);
        QString site_url="http://localhost:3000/tili/saldo/nosto/1";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(webtoken));
        nostoManager = new QNetworkAccessManager(this);
        connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
        ui->nostettuLabel->setText("100€ nostettu.");
}


void Nosto::on_btn200e_clicked()
{
    QJsonObject jsonObj;
        amount = 200;
        qDebug()<<amount;
        jsonObj.insert("amount", amount);
        QString site_url="http://localhost:3000/tili/saldo/nosto/1";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(webtoken));
        nostoManager = new QNetworkAccessManager(this);
        connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
        ui->nostettuLabel->setText("200€ nostettu.");
}


void Nosto::on_btn500e_clicked()
{
    QJsonObject jsonObj;
        amount = 500;
        qDebug()<<amount;
        jsonObj.insert("amount", amount);
        QString site_url="http://localhost:3000/tili/saldo/nosto/1";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(webtoken));
        nostoManager = new QNetworkAccessManager(this);
        connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
        ui->nostettuLabel->setText("500€ nostettu.");
}


void Nosto::on_btnCSTe_clicked()
{
        QJsonObject jsonObj;
        amountMuu = ui->muuSumma->text();
        qDebug()<<amount;
        jsonObj.insert("amount", amountMuu);
        QString site_url="http://localhost:3000/tili/saldo/nosto/1";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader(QByteArray("Authorization"),(webtoken));
        nostoManager = new QNetworkAccessManager(this);
        connect(nostoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = nostoManager->put(request, QJsonDocument(jsonObj).toJson());
        ui->nostettuLabel->setText(amountMuu+"€"+" nostettu.");
}

