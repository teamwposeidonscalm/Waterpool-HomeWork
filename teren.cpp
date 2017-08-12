#include "teren.h"
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


teren::teren(QGraphicsView *parent) : QGraphicsView(parent)
{
    QGraphicsScene* scene;
    scene = new QGraphicsScene();


   QGraphicsView* view = new QGraphicsView(scene);


   //SLIKA ZA POZADINU
   QString filename = "C:/Users/Alma/Documents/Finalni2/pozadina.jpg";
   QImage image(filename);
   QGraphicsPixmapItem* sl1 = new QGraphicsPixmapItem(QPixmap::fromImage(image));


   //SLIKA DRESA ZA DRUGOG IGRAČA U PRVOM TIMU
   QString filename3 = "C:/Users/Alma/Documents/Finalni2/DRES2.png";
   QImage dres(filename3);
   QGraphicsPixmapItem* sl3 = new QGraphicsPixmapItem(QPixmap::fromImage(dres));
   sl3->setPos(180,-70);

   //SLIKA DRESA ZA PRVOG IGRAČA U PROM TIMU
   QString filename4 = "C:/Users/Alma/Documents/Finalni2/DRES2.png";
   QImage dres2(filename4);
   QGraphicsPixmapItem* sl4 = new QGraphicsPixmapItem(QPixmap::fromImage(dres2));
   sl4->setPos(-20,-70);

   //SLIKA DRESA ZA DRUGOG IGRAČA U DRUGOM TIMU
   QString filename5 = "C:/Users/Alma/Documents/Finalni2/DRES.png";
   QImage dres3(filename5);
   QGraphicsPixmapItem* sl5 = new QGraphicsPixmapItem(QPixmap::fromImage(dres3));
   sl5->setPos(120,270);

   //SLIKA DRESA ZA PRVOG IGRAČA U DRUGOM TIMU
   QString filename6 = "C:/Users/Alma/Documents/Finalni2/DRES.png";
   QImage dres4(filename6);
   QGraphicsPixmapItem* sl6 = new QGraphicsPixmapItem(QPixmap::fromImage(dres4));
   sl6->setPos(370,270);

   //PRIKAZIVANJE DRESOVA
   scene->addItem(sl1);
   scene->addItem(sl3);
   scene->addItem(sl4);
   scene->addItem(sl5);
   scene->addItem(sl6);


   //FIXED SIZE
   view->setFixedSize(1000,700);
   view->setSceneRect(0,0,1000,700);
   view->fitInView(0, 0, 636, 400, Qt::KeepAspectRatio);


   view->show();


} void teren::mouseMoveEvent(QMouseEvent *event){
    QGraphicsView::mouseMoveEvent(event);
}

void teren::mousePressEvent(QMouseEvent *event){
    QGraphicsView::mousePressEvent(event);
}

