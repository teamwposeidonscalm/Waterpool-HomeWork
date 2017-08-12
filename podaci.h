#ifndef PODACI_H
#define PODACI_H

#include <QDialog>
#include<QList>
#include "igrac.h"


namespace Ui {
class podaci;

}

class podaci : public QDialog
{
    Q_OBJECT

public:
    explicit podaci(QWidget *parent = 0);
    void setPodaciIme(QString ime, QString tim);

    ~podaci();



private slots:
    void on_save_clicked();

private:
    Ui::podaci *ui;
    QList<QString>Poen;
};
  QList<igrac>getIgrace();
#endif // PODACI_H
