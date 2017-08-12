#ifndef IGRAC_H
#define IGRAC_H

#include <QWidget>

class igrac
{


public:
    explicit igrac( QString _ime, QString _tim, QString _godine, QString _date, QString _prviset, QString _drugiset, QString _treciset);
     QString getIme();
     QString getTim();
     QString getGodine();
     QString getDate();
     QString getPrviSet();
     QString getDrugiSet();
     QString getTreciSet();
private :
    QString ime;
    QString tim;
    QString godine;
    QString date;
    QString prviset;
    QString drugiset;
    QString treciset;


signals:

public slots:
};

#endif // IGRAC_H
