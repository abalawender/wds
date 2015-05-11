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
#include <QPushButton>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "ciecz.hh"

/*! 
 * \file
 * \brief Zawiera definicje metod klasy Zbiornik.
 * 
 * W pliku znajduja sie: 
 * - definicje konstruktorow, metod i przeciazen klasy Zbiornik.
 */

const int PODSTAWA = 200;
const int WYSOKOSC = 200;
const int GRUBOSC  = 3;
const int PROMIEN  = 10;
const int R = 255;
const int G = 0;
const int B = 0;
const int ODPOWIEDNI_CZAS = 1000; // [ms]

////////////////////////////////////////////////////////////////
Zbiornik::Zbiornik(QWidget *wRodzic):  QWidget(wRodzic)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
  connect(&_Stoper,SIGNAL(timeout()),this,SLOT(GdyOdpowiedniCzas()));
  _Stoper.setInterval(ODPOWIEDNI_CZAS);
  _Stoper.setSingleShot(false);
  _Stoper.start();
}

// x, y lewa gora zbiornika
void Zbiornik::RysujZbiornik( QPainter& Rysownik, 
                              int       Podstawa,
                              int       Wysokosc,
                              int       Grubosc,
                              int       x,
                              int       y)
{
  QPen Piorko(Rysownik.pen());
  Piorko.setWidth(Grubosc);
  Rysownik.setPen(Piorko);
  
  Rysownik.drawLine(x, y, x, y+Wysokosc); // Lewa
  Rysownik.drawLine(x+Podstawa, y, x+Podstawa, y+Wysokosc); // Prawa
  Rysownik.drawLine(x, y+Wysokosc, x+Podstawa, y+Wysokosc); // Podstawa
  }


void Zbiornik::RysujCzasteczke( QPainter&    Rysownik, 
                                  const int    Promien,
                                  const Kolor  RGB, 
                                  const double x,
                                  const double y)
{
  QPen Piorko(Rysownik.pen());
  
  Rysownik.setPen(QColor(RGB._r, RGB._g, RGB._b));
  
  // Draws the ellipse defined by the rectangle beginning at (x, y) with the given width and height.
  Rysownik.drawEllipse(x+Promien/2, y+Promien/2, Promien/2, Promien/2); // Center in [x, y].  
}

void Zbiornik::RysujZbiornikZCzasteczkami( QPainter& Rysownik )
{
  QTime Czas;
  Czas.start();
  RysujZbiornik(Rysownik, PODSTAWA, WYSOKOSC, GRUBOSC, width()/2-PODSTAWA/2, height()/2-WYSOKOSC/2);
  RysujCzasteczke(Rysownik, PROMIEN, Kolor(R, G, B),
                  rand()%width(), rand()%height());
}

void Zbiornik::paintEvent( QPaintEvent * )
{
  QPainter Rysownik(this);
  
  RysujZbiornikZCzasteczkami(Rysownik);
  
  // TODO funkcja rysuj czasteczki
  for (std::list<Czasteczka>::iterator it = Czasteczki.begin(); 
                               it != Czasteczki.end(); it++)
  {
    RysujCzasteczke(Rysownik,(*it)._Promien, (*it)._RGB, (*it)._x, (*it)._y);
  }
}

void Zbiornik::GdyOdpowiedniCzas()
{
  update();
  QDate Data = QDate::currentDate();
  QString NapisDaty;
  QLocale Lokalizacja(QLocale::Polish);
  
  NapisDaty = Lokalizacja.toString(Data);
  emit ZglosNapis(NapisDaty);
  
  // TODO Tutaj to ma byc?
  Czasteczki.push_back(Czasteczka(rand()%width(), rand()%height(),
                       PROMIEN, Kolor(rand()%255,
                                      rand()%255,
                                      rand()%255)));
}

/////////////////////////////////////////////////////////////////
OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  Zbiornik *wOkno = new Zbiornik(this);
  setCentralWidget(wOkno);
  setStatusBar(new QStatusBar());
  connect(wOkno, SIGNAL(ZglosNapis(const QString &)),
          this, SLOT(GdyNapis(const QString &)));
          
  //TODO Zmienic na obrazki.
  QPushButton *wPlay = new QPushButton(tr("Play"), this);
  QPushButton *wPause = new QPushButton(tr("Pause"), this);
  QPushButton *wStop = new QPushButton(tr("Stop"), this);
  // TODO Jak zmienic?
  wPause->move(width()/2, height()/2+WYSOKOSC/2+10);
  wPlay->move(width()/2-20, height()/2+WYSOKOSC/2+10);
  wStop->move(width()/2+20, height()/2+WYSOKOSC/2+10); 
  
  resize(1.5*PODSTAWA, 1.5*WYSOKOSC);
}

void OknoGlowne::GdyNapis(const QString &Napis)
{
  statusBar()->showMessage(Napis);
}

/////////////////////////////////////////////////////////////////
int main( int argc, char * argv[] ) 
{
  srand(time(NULL));
  
  QApplication App(argc,argv);
  OknoGlowne   Okno;
 
  Okno.show();
 
  return App.exec();
}
