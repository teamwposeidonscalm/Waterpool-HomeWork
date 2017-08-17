#ifndef IGRAC_H
#define IGRAC_H

#include <QWidget>

class igrac
{


public:
    explicit igrac( QString _ime, QString _tim, QString _godine, QString _date, QString _gol, QString _brasistencija);
     QString getIme();
     QString getTim();
     QString getGodine();
     QString getDate();
     QString getGol();
     QString getBrAsistencija();

private :
    QString ime;
    QString tim;
    QString godine;
    QString date;
    QString gol;
    QString brasistencija;



signals:

public slots:
};

#endif // IGRAC_H
