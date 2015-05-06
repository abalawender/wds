#ifndef CZASTECZKA_HH
#define CZASTECZKA_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "kolor.hh"

class Czasteczka
{
  public:
    Czasteczka(int x, int y, int r, Kolor rgb):
    _x(x), _y(y), _Promien(r), _RGB(rgb) { } ;
    
    int _x; //TODO Zmienic na wektor
    int _y;
    int _Promien;
    Kolor _RGB; 
};

#endif
