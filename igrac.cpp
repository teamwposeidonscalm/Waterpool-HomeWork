#include "igrac.h"

igrac::igrac( QString _ime, QString _tim, QString _godine, QString _date, QString _prviset, QString _drugiset, QString _treciset)
{
ime=_ime;
tim=_tim;
godine=_godine;
date=_date;
prviset=_prviset;
drugiset=_drugiset;
treciset=_treciset;

}

     QString igrac::getIme(){
     return ime;
     }
     QString igrac:: getTim(){
     return tim;
     }

     QString igrac:: getGodine(){
     return godine;
     }

     QString igrac:: getDate(){
     return date;
     }

     QString igrac:: getPrviSet(){
     return prviset;
     }

     QString igrac:: getDrugiSet(){
     return drugiset;
     }

     QString igrac:: getTreciSet(){
     return treciset;
     }




