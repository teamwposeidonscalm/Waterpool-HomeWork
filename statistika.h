#ifndef STATISTIKA_H
#define STATISTIKA_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStringListModel>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsTextItem>
#include <QMap>
#include <QList>
#include "igrac.h"
#include "podaci.h"


namespace Ui {
class statistika;
}

class statistika : public QWidget
{
    Q_OBJECT

public:
    explicit statistika(QWidget *parent = 0);
    QGraphicsScene* scene;
    QGraphicsView*view;


    ~statistika();


private slots:
/* Kreirane 4 liste tipa int i u njima se smjestaju broj poena od svakog seta,+ za svakog igraca (podaci koji s uneseni input filed*/
    QList<QString>getPoeniPrviIgrac();
    QList<QString>getPoeniDrugiIgrac();
    QList<QString>getPoeniTreciIgrac();
    QList<QString>getPoeniCetvrtiIgrac();

/*Funkcija za iscrtavanje label-a na scenu unosemo string koji hocemo da ispisemo i koordinate */
    void printImeIgraca(QString ime, int x, int y);


/*Metodi za dohvatanje imena iz comboBoxa */
    QString getImeIgrac1();
    QString getImeIgrac2();
    QString getImeIgrac3();
    QString getImeIgrac4();

/* Tipka pokreni */
    int on_pushButton_3_clicked();


/* Funkcija za isrtavanje poena na sceni , proslijedimo joj listu poena i koordinate gdje ce isrtati */
    void iscrtajLoptice(QList<QString>prviset,int x, int y,int z);



    void on_pushButton_clicked();
    void on_pushButton_2_clicked();



/* Kada importujemo fajl, ovdje se vrsi klasifikacija podataka i ispisivanje u dijalozima */
    void ucitajDijalogIgrace(QList<igrac>lista);


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();




private:
    Ui::statistika *ui;
    QStringListModel *model;
    QStringListModel *model2;
    QStringListModel *prozor;

};

    QDate getDatum();


/*Otvara importovani textualni fajl vrši parsiranje i vraća listu sa podacima o pojedinačnim igračima */
    QList<igrac>procitajStatistiku(QString nazivFajla);

#endif // STATISTIKA_H
