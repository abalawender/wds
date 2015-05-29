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

int STAN = ePLAY;

Zbiornik::Zbiornik(QWidget *wRodzic):  QWidget(wRodzic)//, lewa_gora_x(width()/2-PODSTAWA/2), lewa_gora_y(height()/2-WYSOKOSC/2)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
  connect(&_Stoper,SIGNAL(timeout()),
          this,SLOT(GdyOdpowiedniCzas()));
  _Stoper.setInterval(ODPOWIEDNI_CZAS);
  _Stoper.setSingleShot(false);
  _Stoper.start();
  
  czas_sym = 0.0;
  
  //TODO przekazywac przez parametry
  // TODO zmienic to!
  //lewa_gora_x = width()/2-PODSTAWA/2;
  //lewa_gora_y = height()/2-WYSOKOSC/2;
  podstawa = PODSTAWA;
  wysokosc = WYSOKOSC;
  
  //QMetaObject::connectSlotsByName(this);
}

void Zbiornik::RysujZbiornik( QPainter& Rysownik, 
                              int       Podstawa,
                              int       Wysokosc,
                              int       Grubosc,
                              int       x,
                              int       y)
{
  //std::cout << x << " " << y << std::endl;
  // TODO nie tutaj!
  lewa_gora_x = width()/2-PODSTAWA/2;
  lewa_gora_y = height()/2-WYSOKOSC/2;
  
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
  
  Rysownik.setPen(QColor(RGB.r(), RGB.g(), RGB.b()));
  
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

bool Zbiornik::CzyWewnatrzZbiornika(const int x, const int y) const 
{
  if ( ((x>lewa_gora_x) && (x<lewa_gora_x+podstawa)) && 
       ((y>lewa_gora_y) && (y<lewa_gora_y+wysokosc)) ) {
    return true;
  }
  return false;
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
    //std::cout << (*it).x() << " " << (*it).y() << " " << lewa_gora_x << " " << lewa_gora_y << std::endl;
    if (CzyWewnatrzZbiornika((*it).x()+((*it).Promien())/2, 
                             (*it).y()+((*it).Promien())/2)) {
      RysujCzasteczke(Rysownik,(*it).Promien(), (*it).RGB(), (*it).x(), (*it).y());
    }
  }
}

void Zbiornik::GdyOdpowiedniCzas()
{
  czas_sym += ODPOWIEDNI_CZAS*1.0/1000;
  if(STAN == ePLAY)
  {
    update(); // -> paintEvent
  
    // TODO SPH
    for (std::list<Czasteczka>::iterator it = Czasteczki.begin(); 
        it != Czasteczki.end(); it++)
        {
          (*it).x() += rand()%7-3;
          (*it).y() += rand()%7-3;
        }
        
        // TODO przesunac uklad wspolrzednych
    Czasteczki.push_back(Czasteczka(
                                    1.5*PODSTAWA+rand()%PODSTAWA-PODSTAWA/2, 
                                    2*WYSOKOSC-rand()%(WYSOKOSC/2),
                                    PROMIEN, 
                                    Kolor(rand()%255, rand()%255, rand()%255)));
  }
  //TODO
  emit ZglosLiczbeCzasteczek(Czasteczki.size());
  emit ZglosCzasSymulacji(czas_sym);
}