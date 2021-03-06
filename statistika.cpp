#include "statistika.h"
#include "ui_statistika.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QStringListModel>
#include <QListView>
#include <QMessageBox>
#include <QTextStream>
#include <QComboBox>
#include <QDebug>
#include <QList>
#include <QLabel>
#include "podaci.h"
#include "igrac.h"
#include "podaci.h"
#include <QDate>
#include <QStringList>

//lista u koju se smjestaja broj 1, ako je smjestano 4 jedinica znaci da su popunjeni podaci za sva cetiri igraca
QList<int>Popunjeno;

//globalna varijabla za datum
QDate datumMeca;

QGraphicsScene* scene;

QList<igrac>igraciZaTeren;

//Ako je varijabla fajl=0 tada se se podaci ne citaju iz fajla vec se trebaju unijeti
  int fajl=0;


//TENISKE LOPTICE ZA SETOVE
QString filename2 = ":images/LOPTICA1.png";
QImage loptica1(filename2);

QString filename5 = ":images/LOPTICA2.png";
QImage loptica2(filename5);

QString filename9 = ":images/LOPTICA3.png";
QImage loptica3(filename9);


statistika::statistika(QWidget *parent):
    //QWidget(parent)//
    ui(new Ui::statistika)

{
    ui->setupUi(this);




    //BOJA BUTTON-A
    ui->pushButton->setStyleSheet("background-color: lightgreen; color: black");
    ui->pushButton_2->setStyleSheet("background-color: lightblue; color: black");
    ui->pushButton_3->setStyleSheet("background-color: lightgreen; color: black");
    ui->pushButton_4->setStyleSheet("background-color: lightblue; color: black");
    ui->pushButton_5->setStyleSheet("background-color: lightblue; color: black");
    ui->pushButton_6->setStyleSheet("background-color: lightblue; color: black");
    ui->pushButton_7->setStyleSheet("background-color: red; color: white");


   //MODEL
    model=new QStringListModel(this);

    ui->comboBox->setModel(model);
    ui->comboBox_2->setModel(model);
    ui->comboBox_3->setModel(model);
    ui->comboBox_4->setModel(model);
    ui->comboBox_5->setModel(model);
    ui->comboBox_6->setModel(model);
    ui->comboBox_7->setModel(model);
    ui->comboBox_8->setModel(model);
    ui->comboBox_9->setModel(model);
    ui->comboBox_10->setModel(model);
    ui->comboBox_11->setModel(model);
    ui->comboBox_12->setModel(model);
     ui->comboBox_13->setModel(model);
      ui->comboBox_14->setModel(model);


    QStringList list;

    //FILE IZ KOJEG SE UČITAVAJU IGRAČI
    QFile textFile(":/file/igraci1.txt");
    if(!textFile.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"Error",textFile.errorString());
}


    //TEXTSTREAM ZA ČITANJE IZ FAJLA
    QTextStream textStream(&textFile);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            list.append(line); // populate the stringlist
    }

    model->setStringList(list); //Ispisivannje u listu

}

//ISPISIVANJE IMENA NA DRES
void statistika::printImeIgraca(QString ime, int x, int y){
  if(ime !=""){
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setPos(x,y);
    QFont titleFont("cosmic sans",10, QFont::Bold);
    io->setDefaultTextColor(Qt::white);
    io->setFont(titleFont);
    io->setPlainText(ime);

   scene->addItem(io);
}
}

statistika::~statistika()
{

    delete ui;

}


//PRIKAZ SCENE I LOPTICA NA TERENU
int statistika::on_pushButton_3_clicked()
{
qDebug()<<Popunjeno.size()<<endl;
if(Popunjeno.size()>0){

    scene = new QGraphicsScene();
   QGraphicsView* view = new QGraphicsView(scene);


   //SLIKA ZA POZADINU
   QString filename = ":/slike/teren.jpg";
   QImage image(filename);
   QGraphicsPixmapItem* sl1 = new QGraphicsPixmapItem(QPixmap::fromImage(image));


   //SLIKA DRESA ZA DRUGOG IGRAČA U PRVOM TIMU
   QString filename3 = ":/slike/kapa1.gif";
   QImage dres(filename3);
   QGraphicsPixmapItem* sl3 = new QGraphicsPixmapItem(QPixmap::fromImage(dres));
   sl3->setPos(200,200);

   //SLIKA DRESA ZA PRVOG IGRAČA U PRVOM TIMU
   QString filename4 = ":/slike/kapa1.gif";
   QImage dres2(filename4);
   QGraphicsPixmapItem* sl4 = new QGraphicsPixmapItem(QPixmap::fromImage(dres2));
   sl4->setPos(320,180);

   //SLIKA DRESA ZA TREĆEG IGRAČA U PRVOM TIMU
   QString filename7 = ":/slike/kapa1.gif";
   QImage dres7(filename7);
   QGraphicsPixmapItem* sl7 = new QGraphicsPixmapItem(QPixmap::fromImage(dres7));
   sl7->setPos(440,160);

   //SLIKA DRESA ZA ČETVRTOG IGRAČA U PRVOM TIMU
   QString filename8 = ":/slike/kapa1.gif";
   QImage dres8(filename8);
   QGraphicsPixmapItem* sl8 = new QGraphicsPixmapItem(QPixmap::fromImage(dres8));
   sl8->setPos(180,120);

   //SLIKA DRESA ZA PETOG IGRAČA U PRVOM TIMU
   QString filename9 = ":/slike/kapa1.gif";
   QImage dres9(filename9);
   QGraphicsPixmapItem* sl9 = new QGraphicsPixmapItem(QPixmap::fromImage(dres9));
   sl9->setPos(300,100);

   //SLIKA DRESA ZA ŠESTOG IGRAČA U PRVOM TIMU
   QString filename10 = ":/slike/kapa1.gif";
   QImage dres10(filename10);
   QGraphicsPixmapItem* sl10 = new QGraphicsPixmapItem(QPixmap::fromImage(dres10));
   sl10->setPos(410,90);

   //SLIKA DRESA ZA SEDMOG IGRAČA U PRVOM TIMU
   QString filename11 = ":/slike/kapa1.gif";
   QImage dres11(filename11);
   QGraphicsPixmapItem* sl11 = new QGraphicsPixmapItem(QPixmap::fromImage(dres11));
   sl11->setPos(230,50);



   //SLIKA DRESA ZA TREĆEG IGRAČA U DRUGOM TIMU
   QString filename5 = ":/slike/kapa2.gif";
   QImage dres3(filename5);
   QGraphicsPixmapItem* sl5 = new QGraphicsPixmapItem(QPixmap::fromImage(dres3));
   sl5->setPos(520,300);

   //SLIKA DRESA ZA DRUGOG IGRAČA U DRUGOM TIMU
   QString filename6 = ":/slike/kapa2.gif";
   QImage dres4(filename6);
   QGraphicsPixmapItem* sl6 = new QGraphicsPixmapItem(QPixmap::fromImage(dres4));
   sl6->setPos(400,320);

   //SLIKA DRESA ZA PRVOG IGRAČA U DRUGOM TIMU
   QString filename12 = ":/slike/kapa2.gif";
   QImage dres12(filename12);
   QGraphicsPixmapItem* sl12 = new QGraphicsPixmapItem(QPixmap::fromImage(dres12));
   sl12->setPos(280,340);

   //SLIKA DRESA ZA ČETVRTOG IGRAČA U DRUGOM TIMU
   QString filename13 = ":/slike/kapa2.gif";
   QImage dres13(filename13);
   QGraphicsPixmapItem* sl13 = new QGraphicsPixmapItem(QPixmap::fromImage(dres13));
   sl13->setPos(300,440);


   //SLIKA DRESA ZA PETOG IGRAČA U DRUGOM TIMU
   QString filename14 = ":/slike/kapa2.gif";
   QImage dres14(filename14);
   QGraphicsPixmapItem* sl14 = new QGraphicsPixmapItem(QPixmap::fromImage(dres14));
   sl14->setPos(420,420);

   //SLIKA DRESA ZA ŠESTOG IGRAČA U DRUGOM TIMU
   QString filename15 = ":/slike/kapa2.gif";
   QImage dres15(filename15);
   QGraphicsPixmapItem* sl15 = new QGraphicsPixmapItem(QPixmap::fromImage(dres15));
   sl15->setPos(540,400);

   //SLIKA DRESA ZA SEDMOG IGRAČA U DRUGOM TIMU
   QString filename16 = ":/slike/kapa2.gif";
   QImage dres16(filename16);
   QGraphicsPixmapItem* sl16 = new QGraphicsPixmapItem(QPixmap::fromImage(dres16));
   sl16->setPos(630,550);







   //PRIKAZIVANJE DRESOVA
   scene->addItem(sl1);
   scene->addItem(sl3);
   scene->addItem(sl4);
   scene->addItem(sl5);
   scene->addItem(sl6);
   scene->addItem(sl7);
   scene->addItem(sl8);
   scene->addItem(sl9);
   scene->addItem(sl10);
   scene->addItem(sl11);
   scene->addItem(sl12);
   scene->addItem(sl13);
   scene->addItem(sl14);
   scene->addItem(sl15);
   scene->addItem(sl16);




   //FIXED SIZE
   view->setFixedSize(1000,700);
   view->setSceneRect(0,0,1000,700);
   view->fitInView(0, 0, 636, 400, Qt::KeepAspectRatio);

   QGraphicsTextItem *text = scene->addText("Tim 1:");
   text->setPos(700, 40);
   text->setDefaultTextColor(Qt::white);
   QFont titleFont("cosmic sans",10, QFont::Bold);
   text->setFont(titleFont);

   QGraphicsTextItem *text1 = scene->addText("Tim 2:");
   text1->setPos(700, 60);
   text1->setDefaultTextColor(Qt::white);
   QFont titleFont1("cosmic sans",10, QFont::Bold);
   text1->setFont(titleFont1);

   QGraphicsTextItem *text2 = scene->addText("|");
   text2->setPos(750, 30);
   text2->setDefaultTextColor(Qt::white);
   QFont titleFont2("cosmic sans",30, QFont::Bold);
   text2->setFont(titleFont2);


    view->show();


//IME IGRAČA
if(fajl==0){  //Ne cita se iz fajla vec se podaci kupe iz input fielda
  igraciZaTeren=getIgrace();
}

/* PRVI TIM */

int i=0;
for(i;i<igraciZaTeren.size();i++){
    qDebug()<<igraciZaTeren[i].getIme()<<endl;
      qDebug()<<igraciZaTeren[i].getGol()<<endl;
       qDebug()<<igraciZaTeren[i].getGodine()<<endl;
       qDebug()<<igraciZaTeren[i].getBrAsistencija()<<endl;
        qDebug()<<igraciZaTeren[i].getTim()<<endl;
        if(i==0){
            /* Igrac 1 tim 1 prvi red*/
            printImeIgraca(igraciZaTeren[i].getIme(),260,30);
            iscrtajGol(igraciZaTeren[i].getGol().toInt(),270,60);// pozicije x ,y
            iscrtajAsistenciju(igraciZaTeren[i].getBrAsistencija().toInt(),270,80);//pozicije x y
        }

        if(i>0 && i<=3){
            /* Igrac 2-4 tim 1 drugi red */
            printImeIgraca(igraciZaTeren[i].getIme(),110+(i*120),100);
            iscrtajGol(igraciZaTeren[i].getGol().toInt(),160+(i*80),130);// pozicije x ,y
            iscrtajAsistenciju(igraciZaTeren[i].getBrAsistencija().toInt(),160+(i*80),150);//pozicije x y
        }
        if(i>3 && i<=7){
            /* Igrac 4-7 tim 1  treci red*/
            printImeIgraca(igraciZaTeren[i].getIme(),100+((i-3)*120),220);
            iscrtajGol(igraciZaTeren[i].getGol().toInt(),80+((i-3)*130),250);// pozicije x ,y
            iscrtajAsistenciju(igraciZaTeren[i].getBrAsistencija().toInt(),80+((i-3)*130),260);//pozicije x y
        }




}



//DATUM
QDate datum=getDatum();
QString datumString= datum.toString("dd.MM.yyyy");
printImeIgraca(datumString, 20, 10);


QString fileName = QFileDialog::getSaveFileName(this, "Save Scene", "", "Image (*.png)");
QPixmap pixMap = QPixmap::grabWidget(view);
pixMap.save(fileName);
close();

}
else {
    QMessageBox :: information(this, "PAŽNJA","Nije sve popunjeno \nPopunite prazna polja");
}


}


//IME NA DRESU
QString statistika::getImeIgrac1(){
    return ui->comboBox->currentText();
}

QString statistika::getImeIgrac2(){
    return ui->comboBox_2->currentText();
}

QString statistika::getImeIgrac3(){
    return ui->comboBox_3->currentText();
}

QString statistika::getImeIgrac4(){
    return ui->comboBox_4->currentText();
}

//ISCRTAVANJE LOPTICA
void statistika::iscrtajGol(int brPoena,int x, int y){

    for(int t=0;t<brPoena;t++){
    QGraphicsPixmapItem* sl2;
     sl2= new QGraphicsPixmapItem(QPixmap::fromImage(loptica1));
    sl2->setPos(x+(t*17),y);
    scene->addItem(sl2);

    }
    //ZATVARA NAKON STO SE KLIKNE DUGME POKRENI
    close();
}


void statistika::iscrtajAsistenciju(int brAsistencija,int x, int y){

    for(int t=0;t<brAsistencija;t++){
    QGraphicsPixmapItem* sl2;
     sl2= new QGraphicsPixmapItem(QPixmap::fromImage(loptica2));
    sl2->setPos(x+(t*17),y);
    scene->addItem(sl2);

    }
    //ZATVARA NAKON STO SE KLIKNE DUGME POKRENI
    close();
}

void statistika::on_pushButton_2_clicked()
{
    podaci podaci;
    QString name= ui->comboBox->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim1");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

void statistika::on_pushButton_4_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_2->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim1");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}
void statistika::on_pushButton_5_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_3->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim1");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}
void statistika::on_pushButton_6_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_4->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim1");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}


void statistika::on_pushButton_7_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_5->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim1");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}


void statistika::on_pushButton_8_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_5->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim1");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}

void statistika::on_pushButton_9_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_7->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim1");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}


void statistika::on_pushButton_10_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_9->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}


void statistika::on_pushButton_11_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_8->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }

}


void statistika::on_pushButton_12_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_12->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

void statistika::on_pushButton_13_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_6->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

void statistika::on_pushButton_14_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_10->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

void statistika::on_pushButton_15_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_13->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

void statistika::on_pushButton_16_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_11->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

void statistika::on_pushButton_17_clicked()
{
    podaci podaci;
    QString name= ui->comboBox_14->currentText();
    if(name!="") {
        Popunjeno.push_back(1);
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

void statistika::ucitajDijalogIgrace(QList<igrac> a){
    podaci podaci;
    QString name= ui->comboBox_5->currentText();
    if(name!="") {
    podaci.setPodaciIme(name,"Tim2");
       podaci.setModal(true);
       podaci.exec();
    } else {
           QMessageBox::warning(this,"Info","Niste odabrali igrača");
   }
}

//OTVARA FILE DIALOG
void statistika::on_pushButton_clicked()
{
    QList<igrac>probni;
    QString Fileime=QFileDialog::getOpenFileName(this,tr("Open File"),"C://","All files(*.*);;Text File (*.txt)");
   qDebug()<<Fileime<<endl;
    if(!Fileime.isEmpty()){
fajl=1;//setujemo varijablu fajl=1 ako u fajlu ima podataka te ce se podaci na sceni ucitavati iz fajla
  probni=procitajStatistiku(Fileime); //parsira sve podatke iz fajla ipripremi ih u listu igraca

  ucitajDijalogIgrace(probni); //sve podatke iz fajla popuni u input fieldovima
  QMessageBox::information(this,"File Name",Fileime);
igraciZaTeren=probni;

   }
}



//GET DATUM
QDate getDatum(){
    return datumMeca;
    }


//ČITA STATISTIKU
QList<igrac> procitajStatistiku(QString nazivFajla){
    QList<igrac>ListaIgracaFajl;
   // QString nazivFajla = ":file/savePodaci.txt";
    QFile file(nazivFajla);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
    QTextStream stream(&file);

    while (!stream.atEnd()) {
        QString line =stream.readLine();

        QStringList info=line.split('|');

      igrac temp(info[0].replace("Ime:",""),info[1].replace("Naziv tima:",""),info[2].replace("Godine:",""),info[3].replace("Datum:",""),info[4].replace("Gol:",""),info[5].replace("Asistencija:",""));
qDebug()<<info[0] <<" "+info[1]+" "+info[2]+" "+info[3]+" "+info[4]+" "+info[5]+" "<<endl;


     ListaIgracaFajl.push_back(temp);
         Popunjeno.push_back(1);
    }
} file.close();
    return ListaIgracaFajl;

}




