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

/*!
 * \brief Poczatkowy stan symulacji.
 * 
 * Poczatkowy stan symulacji to Play/Pauza/Stop.
 */
int STAN = eSTOP;

Zbiornik::Zbiornik(QWidget *wRodzic):  QWidget(wRodzic), _odpowiedni_czas(25)//, lewa_gora_x(width()/2-PODSTAWA/2), lewa_gora_y(height()/2-WYSOKOSC/2)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
  connect(&_Stoper,SIGNAL(timeout()),
          this,SLOT(GdyOdpowiedniCzas()));
  _Stoper.setInterval(_odpowiedni_czas);
  _Stoper.setSingleShot(false);
  _Stoper.start();
  
  _czas_sym = 0.0;
  
  //TODO przekazywac przez parametry
  // TODO zmienic to!
  //lewa_gora_x = width()/2-PODSTAWA/2;
  //lewa_gora_y = height()/2-WYSOKOSC/2;
  _podstawa = PODSTAWA;
  _wysokosc = WYSOKOSC;
  
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
  lewa_gora_xy().getX() = width()/2-PODSTAWA/2;
  lewa_gora_xy().getY() = height()/2-WYSOKOSC/2;
  
  QPen Piorko(Rysownik.pen());
  Piorko.setWidth(Grubosc);
  Rysownik.setPen(Piorko);
  
  Rysownik.drawLine(x, y, x, y+Wysokosc); // Lewa
  Rysownik.drawLine(x+Podstawa, y, x+Podstawa, y+Wysokosc); // Prawa
  Rysownik.drawLine(x, y+Wysokosc, x+Podstawa, y+Wysokosc); // Podstawa
}

void Zbiornik::RysujZbiornikZCzasteczkami( QPainter& Rysownik )
{
  QTime Czas;
  Czas.start();
  RysujZbiornik(Rysownik, PODSTAWA, WYSOKOSC, GRUBOSC, width()/2-PODSTAWA/2, height()/2-WYSOKOSC/2);

  for (std::list<Czasteczka>::iterator it = Czasteczki.begin(); 
       it != Czasteczki.end(); it++)
  {
    //std::cout << (*it).x() << " " << (*it).y() << " " << lewa_gora_x << " " << lewa_gora_y << std::endl;
    if ( CzyWewnatrzZbiornika( (*it).xy().getX()+(*it).Promien(), 
                               (*it).xy().getY()+(*it).Promien() ))
    {
      (*it).RysujCzasteczke(Rysownik,(*it).Promien(), (*it).RGB(), (*it).xy().getX(), (*it).xy().getY());
    }
  }
}

bool Zbiornik::CzyWewnatrzZbiornika(const Vector& xy) const 
{
  if ( ((xy.getX()>lewa_gora_xy().getX()) && (xy.getX()<lewa_gora_xy().getX()+podstawa())) && 
       ((xy.getY()>lewa_gora_xy().getY()) && (xy.getY()<lewa_gora_xy().getY()+wysokosc())) ) {
    return true;
  }
  return false;
}

bool Zbiornik::CzyWewnatrzZbiornika(const double x, const double y) const 
{
  if ( ((x>lewa_gora_xy().getX()) && (x<lewa_gora_xy().getX()+podstawa())) && 
       ((y>lewa_gora_xy().getY()) && (y<lewa_gora_xy().getY()+wysokosc())) ) {
    return true;
    }
    return false;
}

void Zbiornik::paintEvent( QPaintEvent * )
{
  QPainter Rysownik(this);
  RysujZbiornikZCzasteczkami(Rysownik);
}

void Zbiornik::GdyOdpowiedniCzas()
{
  if(STAN == ePLAY)
  {
    _czas_sym += odpowiedni_czas()*1.0/1000;
    update(); // -> paintEvent
    
    // TODO SPH
    for (std::list<Czasteczka>::iterator it = Czasteczki.begin(); 
        it != Czasteczki.end(); it++)
        {
          (*it).xy().getX() += rand()%7-3;
          (*it).xy().getY() += rand()%7-3;
        }
        
        // TODO przesunac uklad wspolrzednych
    Czasteczki.push_back(Czasteczka(
                                    Vector(1.5*PODSTAWA+rand()%PODSTAWA-PODSTAWA/2, 
                                           2*WYSOKOSC-rand()%(WYSOKOSC/2)),
                                    PROMIEN, 
                                    Kolor(rand()%255, rand()%255, rand()%255)));
  }

  emit ZglosLiczbeCzasteczek(Czasteczki.size());
  emit ZglosCzasSymulacji(czas_sym());
}