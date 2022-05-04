#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class Nosto;
}

class Nosto : public QDialog
{
    Q_OBJECT

public:
    explicit Nosto(QString username,QWidget *parent = nullptr);
    ~Nosto();

    const QByteArray &getWebtoken() const;
    void setWebtoken(const QByteArray &newWebtoken);

private slots:
    void on_btnnostosulje_clicked();

    void on_btn20e_clicked();
    void nostoSlot (QNetworkReply *reply);

    void on_btn40e_clicked();

    void on_btn60e_clicked();

    void on_btn100e_clicked();

    void on_btn200e_clicked();

    void on_btn500e_clicked();

    void on_btnCSTe_clicked();

private:
    Ui::Nosto *ui;
    QByteArray webtoken;
    QNetworkAccessManager *nostoManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString pusername;
    double amount;
    QString amountMuu;
};

#endif // NOSTO_H
