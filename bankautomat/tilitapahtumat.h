#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Tilitapahtumat;
}

class Tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tilitapahtumat(QString tapahtuma, QWidget *parent = nullptr);
    ~Tilitapahtumat();

private slots:
    void on_btnclosetilitapahtumat_clicked();

private:
    Ui::Tilitapahtumat *ui;

};

#endif // TILITAPAHTUMAT_H
