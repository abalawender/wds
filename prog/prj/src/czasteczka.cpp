#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "czasteczka.hh"

/*! 
 * \file
 * \brief Zawiera definicje metod klasy Czasteczka.
 * 
 * W pliku znajduja sie: 
 * - definicje konstruktorow, metod i przeciazen klasy Czasteczka.
 */

void Czasteczka::RysujCzasteczke( QPainter&    Rysownik, 
                                  const int    Promien,
                                  const Kolor  RGB, 
                                  const double x,
                                  const double y)
{
  QPen Piorko(Rysownik.pen());
  //Sets the opacity of the painter to opacity. The value should be in the range 0.0 to 1.0, where 0.0 is fully transparent and 1.0 is fully opaque.
  Rysownik.setOpacity(0.5);
  // Antialiasing
  //Rysownik.setRenderHint(QPainter::HighQualityAntialiasing);
  //Zamalowanie wnetrza kolorem czasteczki.
  QBrush brush(QColor(RGB.r(), RGB.g(), RGB.b()), Qt::SolidPattern);
  Rysownik.setBrush(brush);
  Rysownik.setPen(QColor(RGB.r(), RGB.g(), RGB.b()));
  // Draws the ellipse defined by the rectangle beginning at (x, y) with the given width and height.
  Rysownik.drawEllipse(x, y, 2*Promien, 2*Promien);  
}