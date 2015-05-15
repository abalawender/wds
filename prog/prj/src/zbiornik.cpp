#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "zbiornik.hh"

/*! 
 * \file
 * \brief Zawiera definicje metod klasy Zbiornik.
 * 
 * W pliku znajduja sie: 
 * - definicje konstruktorow, metod i przeciazen klasy Zbiornik.
 */

bool PLAY = true;

Zbiornik::Zbiornik(QWidget *wRodzic):  QWidget(wRodzic)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
  connect(&_Stoper,SIGNAL(timeout()),
          this,SLOT(GdyOdpowiedniCzas()));
  _Stoper.setInterval(ODPOWIEDNI_CZAS);
  _Stoper.setSingleShot(false);
  _Stoper.start();
}

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
  //RysujCzasteczke(Rysownik, PROMIEN, Kolor(R, G, B),
  //                rand()%width(), rand()%height());
}

void Zbiornik::paintEvent( QPaintEvent * )
{
  QPainter Rysownik(this);
  
  //std::cout << "***paintEvent" << std::endl;
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
  if(PLAY)
  //if(true)
  {
    update(); // -> paintEvent
  }
  
  // TODO
  for (std::list<Czasteczka>::iterator it = Czasteczki.begin(); 
       it != Czasteczki.end(); it++)
       {
         (*it)._x += rand()%7-3;
         (*it)._y += rand()%7-3;
       }
       
       // TODO przesunac uklad wspolrzednych
  Czasteczki.push_back(Czasteczka(
                                  1.5*PODSTAWA+rand()%PODSTAWA-PODSTAWA/2, 
                                  2*WYSOKOSC-rand()%(WYSOKOSC/2),
                                  PROMIEN, 
                                  Kolor(rand()%255, rand()%255, rand()%255)));
}