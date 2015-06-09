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
int STAN = ePAUSE;

Zbiornik::Zbiornik(QWidget *wRodzic, const Vector& lewa_gora_xy,
                   const double podstawa, const double wysokosc, const double grubosc, const int kat_obrotu):
  QWidget(wRodzic), _lewa_gora_xy(lewa_gora_xy), _podstawa(podstawa),
  _wysokosc(wysokosc), _grubosc(grubosc), _kat_obrotu(kat_obrotu),
  _czas_sym(0.0), _odpowiedni_czas(25)
{
  setAutoFillBackground(true);
  setPalette(QPalette(Qt::white));
  connect(&_Stoper,SIGNAL(timeout()),
          this,SLOT(GdyOdpowiedniCzas()));
  _Stoper.setInterval(_odpowiedni_czas);
  _Stoper.setSingleShot(false);
  _Stoper.start();

  //QMetaObject::connectSlotsByName(this);
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

  Rysownik.translate(width()/2, height()/2);
  Rysownik.rotate(_kat_obrotu);
  x=0-Podstawa/2; y=0-Wysokosc/2;

  Rysownik.drawLine(x, y, x, y+Wysokosc); // Lewa
  Rysownik.drawLine(x+Podstawa, y, x+Podstawa, y+Wysokosc); // Prawa
  Rysownik.drawLine(x, y+Wysokosc, x+Podstawa, y+Wysokosc); // Podstawa

  Rysownik.translate(-width()/2, -height()/2);
}

void Zbiornik::RysujZbiornikZCzasteczkami( QPainter& Rysownik )
{
  QTime Czas;
  Czas.start();
  RysujZbiornik(Rysownik, _podstawa, _wysokosc, GRUBOSC, _lewa_gora_xy.getX(), _lewa_gora_xy.getY());

  for (std::list<Czasteczka>::iterator it = Czasteczki.begin();
       it != Czasteczki.end(); it++)
  {
    if (CzyWewnatrzZbiornika((*it))) {
      (*it).RysujCzasteczke(Rysownik, (*it).Promien(), (*it).RGB(),
                            (*it).xy().getX(), (*it).xy().getY());
    }
  }
}

bool Zbiornik::CzyWewnatrzZbiornika(const double x, const double y) const
{
  return ((x>lewa_gora_xy().getX()-grubosc()/2) && (x<lewa_gora_xy().getX()+podstawa()-grubosc()/2)) &&
    ((y>lewa_gora_xy().getY()) && (y<lewa_gora_xy().getY()+wysokosc()-grubosc()/2));
}

bool Zbiornik::CzyWewnatrzZbiornika(const Vector& xy) const
{
  return CzyWewnatrzZbiornika(xy.getX(), xy.getY());
}

bool Zbiornik::CzyWewnatrzZbiornika(const Czasteczka& cz) const
{
  double cz_x, cz_y, zb_x, zb_y; // Wspolrzedne lewej gory czasteczki i zbiornika.
  cz_x = cz.xy().getX();
  cz_y = cz.xy().getY();
  zb_x = lewa_gora_xy().getX();
  zb_y = lewa_gora_xy().getY();

  return ( ((cz_x > zb_x+grubosc()/2) && (cz_x+2*cz.Promien() < zb_x+podstawa()-grubosc()/2)) &&
           ((cz_y > zb_y-PASKI)       && (cz_y+2*cz.Promien() < zb_y+wysokosc()-grubosc()/2-PASKI)) );
}

void Zbiornik::paintEvent( QPaintEvent * )
{
  QPainter Rysownik(this);
  RysujZbiornikZCzasteczkami(Rysownik);
}


#include "simulation.hh"
simulation s( 200, setup( new params_t ) );

void Zbiornik::GdyOdpowiedniCzas()
{
  //std::cout << s << std::endl;
  if(STAN == ePLAY)
  {
    _czas_sym += odpowiedni_czas()*1.0/1000;
    update(); // -> paintEvent

    // TODO SPH
    for ( auto it = Czasteczki.begin();
        it != Czasteczki.end(); ++it)
        {
          (*it).xy().getX() += rand()%7-3;
          (*it).xy().getY() += rand()%7-3;
        }

    Czasteczki.push_back(Czasteczka(
                                    Vector(1.5*PODSTAWA+rand()%PODSTAWA-PODSTAWA/2,
                                           2*WYSOKOSC-rand()%(WYSOKOSC/2)),
                                    PROMIEN,
                                    Kolor(rand()%255, rand()%255, rand()%255)));
  }

  emit ZglosLiczbeCzasteczek(Czasteczki.size());
  emit ZglosCzasSymulacji(czas_sym());
}
