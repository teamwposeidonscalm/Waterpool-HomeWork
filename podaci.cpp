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


 void podaci::setPodaciIme(QString ime,QList<QString>poeni) {
ui->podaciIme->setText(ime);
Poen=poeni;
 }
//Vrsi  upisivanje podataka o igracu u fajl
void podaci::on_save_clicked()
{
    //Provjera da li su popunjeni svi podaci
    if(ui->podaciIme->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {

        QMessageBox::warning(this,"Info","Popunite prazna mjesta");
        ui->save->setDisabled(true);

    }

    else
        {


    QString nazivFajla = "savePodaci.txt";

    QFile file(nazivFajla);
//Dohvatanje podatke iz input field
    QString ime = ui->podaciIme->text();
    QString naziv_tima = ui->lineEdit_2->text();
    QString godine = ui->lineEdit_3->text();

    QDate datum=getDatum();
//Vrsi konvertovanje dohvacenog datuma iz tipa QDate u QString
    QString datumString= datum.toString("dd.MM.yyyy");

    QString set1=Poen[0];
    QString set2=Poen[1];
    QString set3=Poen[2];

//Kreirani objekat tipa igrac
    igrac teniser(ime,naziv_tima,godine,datumString,set1,set2,set3);
//Smjesta tenisere u listu za teren
    ZaTeren.push_back(teniser);


    if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append) )
    {
    QTextStream stream(&file);
//Ubacuje podatke u tekstualni fajl
    stream <<"Ime:" + ime + "|"   "Naziv tima:" + naziv_tima + "|"   "Godine:" + godine + "|"  "Datum:" + datumString+"|"<<"Set1: "+set1+"|"<<"Set2: "+set2+"|"<<"Set3: "+set3+"|"<<endl;
    QMessageBox::information(this,"Info","Vaši podaci su  snimljeni u fajl!");

}



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
    naziv_tima.clear();
    godine.clear();
    datumString.clear();

    close();
    }


}

