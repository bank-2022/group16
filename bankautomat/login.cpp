#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    objectMyUrl=new MyUrl;
    base_url=objectMyUrl->getBase_url();

}

Login::~Login()
{
    delete ui;
    ui=nullptr;
    delete objectAsiakasMain;
    objectAsiakasMain=nullptr;
}

void Login::on_btnLogin_clicked()
{
    //qDebug()<<"base_url="+base_url;
    Korttinumero=ui->leUsername->text();
    PIN=ui->lePassword->text();


    QJsonObject jsonObj;
    jsonObj.insert("Korttinumero",Korttinumero);
    jsonObj.insert("PIN",PIN);


    qDebug () << " PIN : " + PIN + "    Korttinumero : "+ Korttinumero;
    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}


void Login::loginSlot(QNetworkReply *reply)
{
   response_data=reply->readAll();
   qDebug()<<response_data;
   if(response_data!="false"){
   token="Bearer "+response_data;
   id="2";
   objectAsiakasMain=new AsiakasMain(Korttinumero,token);
   objectAsiakasMain->show();
   this->close();


}
   else{  ui->leUsername->setText("");
       ui->lePassword->setText("");
       ui->labeltunnusluku->setText("väärä tunnusluku");












   }
}
