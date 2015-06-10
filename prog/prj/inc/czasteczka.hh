#ifndef CZASTECZKA_HH
#define CZASTECZKA_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <QPainter>
#include <QRectF>

#include "kolor.hh"
#include "vector.hh"

/*!
 * \file
 * \brief Zawiera definicje klasy Czasteczka oraz deklaracje jej metod.
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
     * \param[in] xy - wektor polozenia czasteczki
     * \param[in] r - promien czasteczki
     * \param[in] rgb - kolor czasteczki
     */
    Czasteczka(Vector xy, int r, const Kolor& rgb):
    _xy(xy), _Promien(r), _RGB(rgb) { } ;
    
    /*!
     * \brief Metoda rysujaca czasteczke.
     * 
     * Rysuje czasteczke o zadanych parametrach
     * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
     * \param[in] Promien - promien czasteczki 
     * \param[in] RGB - kolor czasteczki w formacie RGB
     * \param[in] x - polozenie czasteczki na osi x 
     * \param[in] y - polozenie czasteczki na osi y 
     */                    
    void RysujCzasteczke( QPainter&    Rysownik, 
                          const int    Promien,
                          const Kolor  RGB,
                          const double x,
                          const double y);
      
    
    /*!
     * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
     *
     * Interfejs pozwalajacy na odczyt prywatnych danych.
     * \return _xy - prywatny atrybut opisujacy polozenie czasteczki
     */
    Vector xy() const { return _xy; };
    /*!
     * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
     *
     * Interfejs pozwalajacy na zmiane prywatnych danych.
     * \return _xy - referencja na prywatny atrybut opisujacy polozenie czasteczki
     */
    Vector& xy() { return _xy; };
    
    /*!
     * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
     *
     * Interfejs pozwalajacy na odczyt prywatnych danych.
     * \return _Promien - prywatny atrybut opisujacy promien czasteczki
     */
    int Promien() const { return _Promien; };
    /*!
     * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
     *
     * Interfejs pozwalajacy na zmiane prywatnych danych.
     * \return _Promien - referencja na prywatny atrybut opisujacy promien czasteczki
     */
    int& Promien() { return _Promien; };
    
    /*!
     * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
     *
     * Interfejs pozwalajacy na odczyt prywatnych danych.
     * \return _RGB - prywatny atrybut opisujacy polozenie kolor czasteczki
     */
    Kolor RGB() const { return _RGB; };
    /*!
     * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
     *
     * Interfejs pozwalajacy na zmiane prywatnych danych.
     * \return _RGB - referencja na prywatny atrybut opisujacy promien czasteczki
     */
    Kolor& RGB() { return _RGB; };
    
  private:
    /*!
     * \brief Atrybut opisujacy polozenie czasteczki.
     * 
     * Atrybut opisujacy polozenie czasteczki w kartezjanskim ukladzie wspolrzednych.
     */
    Vector _xy;
    
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