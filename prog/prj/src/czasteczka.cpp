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
  Rysownik.setPen(QColor(RGB.r(), RGB.g(), RGB.b()));
  // Draws the ellipse defined by the rectangle beginning at (x, y) with the given width and height.
  Rysownik.drawEllipse(x, y, 2*Promien, 2*Promien);  
}