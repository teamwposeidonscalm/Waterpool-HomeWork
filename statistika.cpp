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
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setPos(x,y);
    QFont titleFont("cosmic sans",10, QFont::Bold);
    io->setDefaultTextColor(Qt::white);
    io->setFont(titleFont);
    io->setPlainText(ime);

   scene->addItem(io);

}

statistika::~statistika()
{

    delete ui;

}


//PRIKAZ SCENE I LOPTICA NA TERENU
int statistika::on_pushButton_3_clicked()
{

if(Popunjeno.size()==4){

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

//LOPTICE I REZULTAT
QList<QString>prviIgrac=getPoeniPrviIgrac();
  iscrtajLoptice(prviIgrac,320,30,15);

QList<QString>drugiIgrac=getPoeniDrugiIgrac();
  iscrtajLoptice(drugiIgrac,530,30,15);
  QList<QString>treciIgrac=getPoeniTreciIgrac();
    iscrtajLoptice(treciIgrac,300,610,15);

  QList<QString>cetvrtiIgrac=getPoeniCetvrtiIgrac();
    iscrtajLoptice(cetvrtiIgrac,580,610,15);

//SETOVI REZULTAT
int setoviTim1=0;
int setoviTim2=0;

//Ispisivanje i proracun gemova, poena, setova
for(int i=0;i<3;i++){
int gemIgrac1=prviIgrac[i].toInt();
int gemIgrac2=drugiIgrac[i].toInt();
int gemIgrac1Igrac2=(gemIgrac1+gemIgrac2)/4;
int gemIgrac3=treciIgrac[i].toInt();
int gemIgrac4=cetvrtiIgrac[i].toInt();
int gemIgrac3Igrac4=(gemIgrac3+gemIgrac4)/4;
if(gemIgrac1Igrac2==6){
  setoviTim1++;

  if(i==0){
  QString st1=QString::number(gemIgrac1Igrac2);
  printImeIgraca(st1,760,40);
  QString stt1=QString::number(gemIgrac3Igrac4);
  printImeIgraca(stt1,760,60);

}

  if(i==1){
  QString st1=QString::number(gemIgrac1Igrac2);
  printImeIgraca(st1,90,40);
  QString stt1=QString::number(gemIgrac3Igrac4);
  printImeIgraca(stt1,90,60);

}

  if(i==2){
  QString st1=QString::number(gemIgrac1Igrac2);
  printImeIgraca(st1,110,40);
  QString stt1=QString::number(gemIgrac3Igrac4);
  printImeIgraca(stt1,110,60);
}

}

//GEMOVI
if(gemIgrac3Igrac4==6){
      setoviTim2++;
    if(i==0){

  QString stt1=QString::number(gemIgrac1Igrac2);
  printImeIgraca(stt1,300,300);
  QString st2=QString::number(gemIgrac3Igrac4);
  printImeIgraca(st2,320,300);
  printImeIgraca(QString::number(setoviTim1),300,320);
  printImeIgraca(QString::number(setoviTim2),320,320);
}

     if(i==1){

  QString stt1=QString::number(gemIgrac1Igrac2);
  printImeIgraca(stt1,90,40);
  QString st2=QString::number(gemIgrac3Igrac4);
  printImeIgraca(st2,90,60);

}

  if(i==2){

  QString stt1=QString::number(gemIgrac1Igrac2);
  printImeIgraca(stt1,380,300);
  QString st2=QString::number(gemIgrac3Igrac4);
  printImeIgraca(st2,400,300);
  printImeIgraca(QString::number(setoviTim1),380,320);
  printImeIgraca(QString::number(setoviTim2),400,320);
}

}

}

//KRAJNJI REZULTAT
  printImeIgraca(QString::number(setoviTim1),770,40);
  printImeIgraca(QString::number(setoviTim2),770,60);



//IME IGRAČA
if(fajl==0){  //Ne cita se iz fajla vec se podaci kupe iz input fielda
  igraciZaTeren=getIgrace();
}
//istu funkciju za ispisivnje imena na sceni koristimo i za ispisivanje naziva tima i godina
QString ime1=igraciZaTeren[0].getIme();
QString ime2=igraciZaTeren[1].getIme();
QString ime3=igraciZaTeren[2].getIme();
QString ime4=igraciZaTeren[3].getIme();

QString ime5=igraciZaTeren[0].getIme();
printImeIgraca(ime5,260,30);
QString ime6=igraciZaTeren[1].getIme();
printImeIgraca(ime6,670,30);
QString ime7=igraciZaTeren[2].getIme();
printImeIgraca(ime7,230,610);
QString ime8=igraciZaTeren[3].getIme();
printImeIgraca(ime8,730,610);

QString tim1=igraciZaTeren[0].getTim();
printImeIgraca(tim1,260,45);
QString tim2=igraciZaTeren[1].getTim();
printImeIgraca(tim2,670,45);
QString tim3=igraciZaTeren[2].getTim();
printImeIgraca(tim3,230,625);
QString tim4=igraciZaTeren[3].getTim();
printImeIgraca(tim4,730,625);

QString godine1=igraciZaTeren[0].getGodine();
printImeIgraca(godine1,260,60);
QString godine2=igraciZaTeren[1].getGodine();
printImeIgraca(godine2,670,60);
QString godine3=igraciZaTeren[2].getGodine();
printImeIgraca(godine3,230,640);
QString godine4=igraciZaTeren[3].getGodine();
printImeIgraca(godine4,730,640);

//DATUM
QDate datum=getDatum();
QString datumString= datum.toString("dd.MM.yyyy");
printImeIgraca(datumString, 20, 10);

//PRINT IME IGRAČA
printImeIgraca(ime1,360,116);
printImeIgraca(ime2,560,116);
printImeIgraca(ime3,349,470);
printImeIgraca(ime4,600,470);

QString fileName = QFileDialog::getSaveFileName(this, "Save Scene", "", "Image (*.png)");
QPixmap pixMap = QPixmap::grabWidget(view);
pixMap.save(fileName);
close();

}
else {
    QMessageBox :: information(this, "PAŽNJA","Nije sve popunjeno \nPopunite prazna polja");
}


}

//POENI
QList<QString> statistika::getPoeniPrviIgrac(){
//metod za dohvatanje poena iz input fielda i smjestanje u listu
    QList<QString>PoeniPrviIgrac;
QString poen=ui->prviSetIgrac1->text();
PoeniPrviIgrac.push_back(poen);
poen=ui->drugiSetIgrac1->text();
PoeniPrviIgrac.push_back(poen);
poen=ui->treciSetIgrac1->text();
PoeniPrviIgrac.push_back(poen);
return PoeniPrviIgrac;
}


QList<QString> statistika::getPoeniDrugiIgrac(){
    QList<QString>PoeniDrugiIgrac;
QString poen=ui->prviSetIgrac2->text();
PoeniDrugiIgrac.push_back(poen);
poen=ui->drugiSetIgrac2->text();
PoeniDrugiIgrac.push_back(poen);
poen=ui->treciSetIgrac2->text();
PoeniDrugiIgrac.push_back(poen);
return PoeniDrugiIgrac;
}

QList<QString> statistika::getPoeniTreciIgrac(){
    QList<QString>PoeniTreciIgrac;
QString poen=ui->prviSetIgrac3->text();
PoeniTreciIgrac.push_back(poen);
poen=ui->drugiSetIgrac3->text();
PoeniTreciIgrac.push_back(poen);
poen=ui->treciSetIgrac3->text();
PoeniTreciIgrac.push_back(poen);
return PoeniTreciIgrac;

}

QList<QString> statistika::getPoeniCetvrtiIgrac(){
      datumMeca=ui->mojDate->date();
    QList<QString>PoeniCetvrtiIgrac;
QString poen=ui->prviSetIgrac4->text();
PoeniCetvrtiIgrac.push_back(poen);
poen=ui->drugiSetIgrac4->text();
PoeniCetvrtiIgrac.push_back(poen);
poen=ui->treciSetIgrac4->text();
PoeniCetvrtiIgrac.push_back(poen);
return PoeniCetvrtiIgrac;
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
void statistika::iscrtajLoptice(QList<QString>prviset, int x, int y, int z){

    for(int t=0;t<3;t++){

 QGraphicsPixmapItem* sl2;

//Priprema broja loptica za isrtavanje na scenu u zavisnosi od broja poenaa
QString poeni=prviset[t];
int p=poeni.toInt();
//4 poena=1 loptica na sceni
p=p/4;
    for (int i=0; i<p; i++){
if(t==0){ //prvi set
     sl2= new QGraphicsPixmapItem(QPixmap::fromImage(loptica1));
}

if(t==1){ //drugi set
    sl2= new QGraphicsPixmapItem(QPixmap::fromImage(loptica2));
}
if(t==2){ //treci set
    sl2= new QGraphicsPixmapItem(QPixmap::fromImage(loptica3));
}
    sl2->setPos(x+i*z,y+(t*17));
    scene->addItem(sl2);
    }
    }

    //ZATVARA NAKON STO SE KLIKNE DUGME POKRENI
    close();

}

//OTVARA FILE DIALOG
void statistika::on_pushButton_clicked()
{
    QList<igrac>probni;
    QString Fileime=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files(*.*);;Text File (*.txt)"
                );
   if(!Fileime.isEmpty()){
fajl=1;//setujemo varijablu fajl=1 ako u fajlu ima podataka te ce se podaci na sceni ucitavati iz fajla
  probni=procitajStatistiku(Fileime); //parsira sve podatke iz fajla ipripremi ih u listu igraca

  ucitajDijalogIgrace(probni); //sve podatke iz fajla popuni u input fieldovima
  QMessageBox::information(this,"File Name",Fileime);
igraciZaTeren=probni;

   }

}

//UČITAVA IGRAČE I POENE
void statistika::ucitajDijalogIgrace(QList<igrac>probni){


QString Igrac1=probni[0].getIme();
ui->comboBox->setItemText(0,Igrac1);
ui->comboBox->setCurrentIndex(0);

QString Set1Igrac1=probni[0].getPrviSet().replace("Set1:","");
ui->prviSetIgrac1->setText(Set1Igrac1);
QString Set2Igrac1=probni[0].getDrugiSet().replace("Set2:","");
ui->drugiSetIgrac1->setText(Set2Igrac1);
QString Set3Igrac1=probni[0].getTreciSet().replace("Set3:","");
ui->treciSetIgrac1->setText(Set3Igrac1);



QString Igrac2=probni[1].getIme();
ui->comboBox_2->setItemText(1,Igrac2);
ui->comboBox_2->setCurrentIndex(1);

QString Set1Igrac2=probni[1].getPrviSet().replace("Set1:","");
ui->prviSetIgrac2->setText(Set1Igrac2);
QString Set2Igrac2=probni[1].getDrugiSet().replace("Set2:","");
ui->drugiSetIgrac2->setText(Set2Igrac2);
QString Set3Igrac2=probni[1].getTreciSet().replace("Set3:","");
ui->treciSetIgrac2->setText(Set3Igrac2);



QString Igrac3=probni[2].getIme();
ui->comboBox_3->setItemText(2,Igrac3);
ui->comboBox_3->setCurrentIndex(2);

QString Set1Igrac3=probni[2].getPrviSet().replace("Set1:","");
ui->prviSetIgrac3->setText(Set1Igrac3);
QString Set2Igrac3=probni[2].getDrugiSet().replace("Set2:","");
ui->drugiSetIgrac3->setText(Set2Igrac3);
QString Set3Igrac3=probni[2].getTreciSet().replace("Set3:","");
ui->treciSetIgrac3->setText(Set3Igrac3);



QString Igrac4=probni[3].getIme();
ui->comboBox_4->setItemText(3,Igrac4);
ui->comboBox_4->setCurrentIndex(3);

QString Set1Igrac4=probni[3].getPrviSet().replace("Set1:","");
ui->prviSetIgrac4->setText(Set1Igrac4);
QString Set2Igrac4=probni[3].getDrugiSet().replace("Set2:","");
ui->drugiSetIgrac4->setText(Set2Igrac4);
QString Set3Igrac4=probni[3].getTreciSet().replace("Set3:","");
ui->treciSetIgrac4->setText(Set3Igrac4);

}


//PROVJERAVA DA LI SU UNESENI ISTI IGRAČI
void statistika::on_pushButton_2_clicked()
{
    if (ui->comboBox->currentText().isEmpty() || ui->comboBox_2->currentText().isEmpty() || ui->comboBox_3->currentText().isEmpty() ||
            ui->comboBox_4->currentText().isEmpty()){
        QMessageBox::information(this,"PAŽNJA","Niste odabrali 4 igrača. \nOdaberite 4 igrača za igru.");
    }
    else

    if(ui->comboBox->currentText() == ui->comboBox_2->currentText() || ui->comboBox->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox->currentText()== ui->comboBox_4->currentText() || ui->comboBox_2->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox_2->currentText() == ui->comboBox_4->currentText() || ui->comboBox_3->currentText()== ui->comboBox_4->currentText()){
        QMessageBox::information(this, "PAŽNJA","Odabrali ste istog igrača više puta .\nOdaberite drugog igrača.");

}
    else
        {


    Popunjeno.push_back(1);
    podaci podaci;
    QString imeIgraca=getImeIgrac1();
    QList<QString>poen=getPoeniPrviIgrac();
    podaci.setPodaciIme(imeIgraca,poen);
    podaci.setModal(true);
    podaci.exec();
}


}

//PROVJERAVA DA LI SU UNESENI ISTI IGRAČI
void statistika::on_pushButton_4_clicked()
{
    if (ui->comboBox->currentText().isEmpty() || ui->comboBox_2->currentText().isEmpty() || ui->comboBox_3->currentText().isEmpty() ||
            ui->comboBox_4->currentText().isEmpty()){
        QMessageBox::information(this,"PAŽNJA","Niste odabrali 4 igrača. \nOdaberite 4 igrača za igru.");
    }
    else

    if(ui->comboBox->currentText() == ui->comboBox_2->currentText() || ui->comboBox->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox->currentText()== ui->comboBox_4->currentText() || ui->comboBox_2->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox_2->currentText() == ui->comboBox_4->currentText() || ui->comboBox_3->currentText()== ui->comboBox_4->currentText()){
        QMessageBox::information(this, "PAŽNJA","Odabrali ste istog igrača više puta .\nOdaberite drugog igrača.");

}
    else


    Popunjeno.push_back(1);
    podaci podaci;
    QString imeIgraca=getImeIgrac2();
    QList<QString>poen=getPoeniDrugiIgrac();
    podaci.setPodaciIme(imeIgraca,poen);
    podaci.setModal(true);
    podaci.exec();

  //  }
}

//PROVJERAVA DA LI SU UNESENI ISTI IGRAČI
void statistika::on_pushButton_5_clicked()
{
    if (ui->comboBox->currentText().isEmpty() || ui->comboBox_2->currentText().isEmpty() || ui->comboBox_3->currentText().isEmpty() ||
            ui->comboBox_4->currentText().isEmpty()){
        QMessageBox::information(this,"PAŽNJA","Niste odabrali 4 igrača. \nOdaberite 4 igrača za igru.");
    }
    else

    if(ui->comboBox->currentText() == ui->comboBox_2->currentText() || ui->comboBox->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox->currentText()== ui->comboBox_4->currentText() || ui->comboBox_2->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox_2->currentText() == ui->comboBox_4->currentText() || ui->comboBox_3->currentText()== ui->comboBox_4->currentText()){
        QMessageBox::information(this, "PAŽNJA","Odabrali ste istog igrača više puta .\nOdaberite drugog igrača.");

}
    else
        {

    Popunjeno.push_back(1);
    podaci podaci;
    QString imeIgraca=getImeIgrac3();
    QList<QString>poen=getPoeniTreciIgrac();
    podaci.setPodaciIme(imeIgraca,poen);
    podaci.setModal(true);
    podaci.exec();

    }
}

//PROVJERAVA DA LI SU UNESENI ISTI IGRAČI
void statistika::on_pushButton_6_clicked()
{
    if (ui->comboBox->currentText().isEmpty() || ui->comboBox_2->currentText().isEmpty() || ui->comboBox_3->currentText().isEmpty() ||
            ui->comboBox_4->currentText().isEmpty()){
        QMessageBox::information(this,"PAŽNJA","Niste odabrali 4 igrača. \nOdaberite 4 igrača za igru.");
    }
    else

    if(ui->comboBox->currentText() == ui->comboBox_2->currentText() || ui->comboBox->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox->currentText()== ui->comboBox_4->currentText() || ui->comboBox_2->currentText()== ui->comboBox_3->currentText() ||
            ui->comboBox_2->currentText() == ui->comboBox_4->currentText() || ui->comboBox_3->currentText()== ui->comboBox_4->currentText()){
        QMessageBox::information(this, "PAŽNJA","Odabrali ste istog igrača više puta .\nOdaberite drugog igrača.");

}
    else
        {

    Popunjeno.push_back(1);//za svakog igraca smjestamo u listu popunjeno broj 1 cime se signalizira da je sve uspjesno i korektno popunjeno
    podaci podaci;
    QString imeIgraca=getImeIgrac4();
    QList<QString>poen=getPoeniCetvrtiIgrac();
    podaci.setPodaciIme(imeIgraca,poen);
    podaci.setModal(true);
    podaci.exec();

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

        igrac temp(info[0].replace("Ime:",""),info[1].replace("Naziv tima:",""),info[2].replace("Godine:",""),info[3],info[4],info[5],info[6]);


     ListaIgracaFajl.push_back(temp);
         Popunjeno.push_back(1);
    }
} file.close();
    return ListaIgracaFajl;

}




