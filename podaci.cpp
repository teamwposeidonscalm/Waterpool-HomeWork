#include "podaci.h"
#include "ui_podaci.h"
#include <QMessageBox>
#include <QFile>
#include <QDate>
#include <QTextStream>
#include <QString>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include "igrac.h"
#include "statistika.h"

//Globalna varijabla u njoj se smještaju igrači koji se prikazuju na sceni
QList<igrac>ZaTeren;


podaci::podaci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::podaci)
{
    ui->setupUi(this);

    //SLIKA
    QPixmap pix(":/slike/vaterpolo.png");
    ui->label_5->setPixmap(pix);



    //BOJA BUTTON-A
  ui->pushButton->setStyleSheet("background-color: red; color: white");
    ui->save->setStyleSheet("background-color: lightgreen; color: black");

}

  QList<igrac>getIgrace(){
     return ZaTeren;
  }

podaci::~podaci()
{
    delete ui;
}


 void podaci::setPodaciIme(QString ime,QString tim) {
ui->namePlayer->setText(ime);
ui->timName->setText(tim);
 }

 //Vrsi  upisivanje podataka o igracu u fajl
void podaci::on_save_clicked()
{

    //Provjera da li su popunjeni svi podaci
    if(ui->namePlayer->text().isEmpty() || ui->lineEdit_2->text().isEmpty()|| ui->lineEdit_3->text().isEmpty() )
    {

        QMessageBox::warning(this,"Info","Popunite podatke");


    }

    else
        {


    QString nazivFajla = "savePodaci.txt";

    QFile file(nazivFajla);
//Dohvatanje podatke iz input field
    QString ime = ui->namePlayer->text();
    QString gol = ui->lineEdit_2->text();
    QString godine = ui->lineEdit_3->text();
    QString tim= ui->timName->text();
      QDate datum=getDatum();
   QString datumString= datum.toString("dd.MM.yyyy");


   if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append) )
   {
   QTextStream stream(&file);
//Ubacuje podatke u tekstualni fajl
   stream <<"Ime:" + ime + "|" "Naziv tima:" + tim + "|"   "Godine:" + godine + "|"  "Datum:" + datumString+"|" "Gol:"+ gol+ "|"<<endl;
   QMessageBox::information(this,"Info","Vaši podaci su  snimljeni u fajl!");

}

ZaTeren.push_back(igrac(ime,tim,godine,datumString, gol));
//Vrsi konvertovanje dohvacenog datuma iz tipa QDate u QString



    QMessageBox MessageBox;
    MessageBox.setText(tr("Želite li otvoriti vaš file?"));
    MessageBox.setWindowTitle("Info");
    QAbstractButton* otvoriFajl = MessageBox.addButton(tr("Da"), QMessageBox::YesRole);
    MessageBox.addButton(tr("Ne"), QMessageBox::NoRole);

    MessageBox.exec();

    if (MessageBox.clickedButton()==otvoriFajl) {
        QDesktopServices::openUrl(QUrl("savePodaci.txt", QUrl::TolerantMode));
}
    ime.clear();
    godine.clear();
    datumString.clear();

    close();
    }


}

