#include "igrac.h"

igrac::igrac( QString _ime, QString _tim, QString _godine, QString _date, QString _gol)
{
ime=_ime;
tim=_tim;
godine=_godine;
date=_date;
gol=_gol;

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


     QString igrac:: getGol(){
     return gol;
     }




