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
 * - definicje konstruktorow oraz metod klasy Zbiornik.
 */

/*!
 * \brief Poczatkowy stan symulacji.
 *
 * Poczatkowy stan symulacji to Play/Pauza/Stop.
 */
int STAN = ePAUSE;

Zbiornik::Zbiornik(QWidget *wRodzic, const Vector& lewa_gora_xy,
                   const double podstawa, const double wysokosc, const double grubosc, const int kat_obrotu):
  QWidget(wRodzic), _Symulacja( 400, setup( new params_t ) ), useGravity(true),
  _lewa_gora_xy(lewa_gora_xy), _podstawa(podstawa),
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

  GdyOdpowiedniCzas();
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
  Rysownik.setRenderHint(QPainter::Antialiasing);
  Rysownik.translate(width()/2, height()/2);
  Rysownik.rotate(_kat_obrotu);
  x=0-Podstawa/2; y=0-Wysokosc/2;

  Rysownik.drawLine(x, y, x, y+Wysokosc); // Lewa
  Rysownik.drawLine(x+Podstawa, y, x+Podstawa, y+Wysokosc); // Prawa
  Rysownik.drawLine(x, y+Wysokosc, x+Podstawa, y+Wysokosc); // Podstawa
  Rysownik.drawLine(x, y, x+Podstawa, y); // Pokrywa

  Rysownik.translate(-width()/2, -height()/2);
}

void Zbiornik::RysujZbiornikZCzasteczkami( QPainter& Rysownik )
{
  QTime Czas;
  Czas.start();
  // triki z gruboscia i promieniem, zeby latwiej umieszczac czasteczki w zbiorniku
  RysujZbiornik(Rysownik,
                _podstawa+GRUBOSC, // szerokosc pustej przestrzeni w zbiorniku == _podstawa
                _wysokosc+GRUBOSC,
                GRUBOSC,
                _lewa_gora_xy.getX()-PROMIEN,
                _lewa_gora_xy.getY()-PROMIEN );

  for( auto c : Czasteczki )
  {
      c.RysujCzasteczke(Rysownik, c.Promien(), c.RGB(),
                        _lewa_gora_xy.getX()+(_podstawa-2*GRUBOSC+2)*c.xy().getX(),
                        _lewa_gora_xy.getY()+_wysokosc-2*(1+PROMIEN+GRUBOSC)-(_wysokosc-2*PROMIEN+2)*c.xy().getY()+PASKI);
  }
}

// bool Zbiornik::CzyWewnatrzZbiornika(const double x, const double y) const
// {
//     LOG( "(x, y)" << x << " " <<  y );
//   return ((x>lewa_gora_xy().getX()-grubosc()/2) && (x<lewa_gora_xy().getX()+podstawa()-grubosc()/2)) &&
//     ((y>lewa_gora_xy().getY()) && (y<lewa_gora_xy().getY()+wysokosc()-grubosc()/2));
// }
//
// bool Zbiornik::CzyWewnatrzZbiornika(const Vector& xy) const
// {
//     LOG( "(x, y)" << xy );
//   return CzyWewnatrzZbiornika(xy.getX(), xy.getY());
// }
//
// bool Zbiornik::CzyWewnatrzZbiornika(const Czasteczka& cz) const
// {
//   double cz_x, cz_y, zb_x, zb_y; // Wspolrzedne lewej gory czasteczki i zbiornika.
//   cz_x = cz.xy().getX();
//   cz_y = cz.xy().getY();
//   zb_x = lewa_gora_xy().getX();
//   zb_y = lewa_gora_xy().getY();
//
//   return ( ((cz_x > zb_x+grubosc()/2) && (cz_x+2*cz.Promien() < zb_x+podstawa()-grubosc()/2)) &&
//            ((cz_y > zb_y-PASKI)       && (cz_y+2*cz.Promien() < zb_y+wysokosc()-grubosc()/2-PASKI)) );
// }

void Zbiornik::paintEvent( QPaintEvent * )
{
  // Wersja latwiejsza
  //QPainter Rysownik(this);
  //Rysownik.setRenderHint(QPainter::HighQualityAntialiasing);
  //RysujZbiornikZCzasteczkami(Rysownik);

  // Wersja pod niezalezna sprzetowo
  QImage image(size(), QImage::Format_ARGB32_Premultiplied);
  QPainter imagePainter(&image);
  imagePainter.initFrom(this);
  imagePainter.setRenderHint(QPainter::HighQualityAntialiasing, true);
  imagePainter.eraseRect(rect());
  RysujZbiornikZCzasteczkami(imagePainter);
  imagePainter.end();

  QPainter widgetPainter(this);
  widgetPainter.drawImage(0, 0, image);
}



void Zbiornik::GdyOdpowiedniCzas()
{
  if(STAN == ePLAY)
  {
    _czas_sym += odpowiedni_czas()*1.0/1000;
    update(); // -> paintEvent

    Czasteczki.clear();

    for( unsigned i = 0; i < _Symulacja.getN(); ++i ) {
        float blue = (_Symulacja.rho[i]-950)*2; //0-200
        blue = std::min( 200.0f, std::max( 0.0f, blue ) ); // make sure we don't go beyond

        Czasteczki.push_back(Czasteczka( _Symulacja.p[i],
                    PROMIEN, Kolor(10, 0.5*(255-blue), 255-blue ) ) );
    }

    //TODO dodac rotate() do klasy vector!!!
    float gx0 = 0, gy0 = -9.8, alpha = -_kat_obrotu * M_PI / 180;

    _Symulacja.params->gx = gx0 * cos(alpha) + gy0  * sin(alpha);
    _Symulacja.params->gy = (useGravity ? gx0 * sin(alpha) + gy0  * cos(alpha) : 0 );
    _Symulacja.step();
  }
  else if(STAN == eSTOP) 
  {
    update(); // -> paintEvent

    Czasteczki.clear();

    for( unsigned i = 0; i < _Symulacja.getN(); ++i ) {
        float blue = (_Symulacja.rho[i]-950)*2; //0-200
        blue = std::min( 200.0f, std::max( 0.0f, blue ) ); // make sure we don't go beyond

        Czasteczki.push_back(Czasteczka( _Symulacja.p[i],
                    PROMIEN, Kolor(10, 0.5*(255-blue), 255-blue ) ) );
    }
  }

  emit ZglosLiczbeCzasteczek(Czasteczki.size());
  emit ZglosCzasSymulacji(czas_sym());
}
