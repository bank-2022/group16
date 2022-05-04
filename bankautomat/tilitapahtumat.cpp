#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

Tilitapahtumat::Tilitapahtumat(QString tapahtuma, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tilitapahtumat)
{
    ui->setupUi(this);
    qDebug()<<tapahtuma;
    ui->textEditkayttajantiedot->setText(tapahtuma);
}

Tilitapahtumat::~Tilitapahtumat()
{
    delete ui;
}

void Tilitapahtumat::on_btnclosetilitapahtumat_clicked()
{
    ui->textEditkayttajantiedot->clear();
    this->close();
}

