#include "statistika.h"
#include <QApplication>
#include <QListView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    statistika w;//kreiras objekat tipa statistika
   w.show();

    return a.exec();
}
