#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QStatusBar>
#include <QTime>
#include <QDate>
#include <QLocale>
#include <QWidget>
#include <QSlider>
#include <iostream>
#include <sstream>
#include <QMainWindow>
#include <QSpinBox>
#include <QProgressBar>
#include <QLCDNumber>


#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif


#include "ciecz.hh"

#define PODSTAWA        40
#define WYSOKOSC        50
#define GRUBOSC         3


////////////////////////////////////////////////////////////////
Zbiornik::Zbiornik(QWidget *wRodzic):  QWidget(wRodzic)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
}

void Zbiornik::RysujZbiornik( QPainter& Rysownik, 
                                 int       Podstawa,
                                 int       Wysokosc,
                                 int       Grubosc)
{
  QPen Piorko(Rysownik.pen());
  
  Piorko.setWidth(Grubosc);
  Rysownik.setPen(Piorko);
  Rysownik.drawLine(-Podstawa/2,Wysokosc,Podstawa/2,Wysokosc); // Podstawa
  Rysownik.drawLine(-Podstawa/2,0,-Podstawa/2,Wysokosc); // Lewa
  Rysownik.drawLine(Podstawa/2,0,Podstawa/2,Wysokosc); // Prawa
}


void Zbiornik::paintEvent( QPaintEvent * )
{
  QPainter Rysownik(this);
  Rysownik.translate(width()/2,height()/2);
  
  int Podstawa = PODSTAWA;
  int Wysokosc = WYSOKOSC;
  int Grubosc = GRUBOSC;
  
  RysujZbiornik(Rysownik,Podstawa,Wysokosc,Grubosc);
  //RysujCzasteczki(...);
}
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
Kanwa::Kanwa(QWidget *wRodzic):  QWidget(wRodzic)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
  
  Zbiornik *wZbiornik = new Zbiornik(this);
  wZbiornik->setGeometry(0,0,200,200);
}
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Kanwa *wOknoKanwa = new Kanwa(this);
  resize(220,180);
  setCentralWidget(wOknoKanwa);
}
/////////////////////////////////////////////////////////////////

int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  OknoGlowne   Okno;
  
  Okno.show();
 
  return App.exec();
}
