#ifndef CZASTECZKA_HH
#define CZASTECZKA_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "kolor.hh"

/*!
 * \file
 * \brief Zawiera definicje klasy Kolor oraz deklaracje jej metod.
 *
 * W pliku znajduja sie:
 * - definicja klasy Czasteczka (modeluje pojecie czasteczki),
 * - definicje konstruktorow, 
 * - deklaracje atrybutow.
 */

/*!
 * \brief Klasa modelująca czasteczke.
 * 
 * Klasa zawierajaca podstawowe atrybuty czasteczki.
 */
class Czasteczka
{
  public:
    /*!
     * \brief Konstruktor.
     *
     * Konstruktor parametryczny, inicjalizujacy czasteczke podanymi wlasnosciami.
     * \param[in] x - polozenie czasteczki na osi x
     * \param[in] y - polozenie czasteczki na osi y
     * \param[in] r - promien czasteczki
     * \param[in] rgb - kolor czasteczki
     */
    Czasteczka(int x, int y, int r, const Kolor& rgb):
    _x(x), _y(y), _Promien(r), _RGB(rgb) { } ;
    
    //TODO
    //private:
    //TODO Zmienic x, y na wektor
    /*!
     * \brief Atrybut opisujacy polozenie czasteczki na osi x.
     * 
     * Atrybut opisujacy polozenie czasteczki na osi x.
     */
    int _x;
    
    /*!
     * \brief Atrybut opisujacy polozenie czasteczki na osi y.
     * 
     * Atrybut opisujacy polozenie czasteczki na osi y.
     */
    int _y;
    
    /*!
     * \brief Atrybut okreslajacy promien czasteczki.
     * 
     * Atrybut okreslajacy promien czasteczki.
     */
    int _Promien;
    
    /*!
     * \brief Atrybut opisujacy kolor czasteczki.
     * 
     * Atrybut opisujacy kolor czasteczki.
     */
    Kolor _RGB; 
};

#endif