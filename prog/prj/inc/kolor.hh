#ifndef KOLOR_HH
#define KOLOR_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

/*!
 * \file
 * \brief Zawiera definicje klasy Kolor oraz deklaracje jej metod.
 *
 * W pliku znajduja sie:
 * - definicja klasy Kolor (modeluje pojecie Koloru),
 * - definicje konstruktorow, 
 * - deklaracje atrybutow.
 */

/*!
 * \brief Klasa modelująca kolor.
 * 
 * Klasa opisuje kolor w formacie RGB.
 */
class Kolor
{
  public:
    /*!
     * \brief Konstruktor.
     *
     * Konstruktor parametryczny, inicjalizujacy kolor podanymi wartosciami.
     * \param[in] r - wartosc odcieniu czerwonego, [0, 255]
     * \param[in] g - wartosc odcieniu zielonego, [0, 255]
     * \param[in] b - wartosc odcieniu niebieskiego, [0, 255]
     */
    Kolor(int r, int g, int b) { _r = r; _g = g; _b = b; };
    
    /*!
     * \brief Konstruktor kopiujacy.
     *
     * Konstruktor kopiujacy.
     * \param[in] rgb - obiekt do skopiowania
     */
    Kolor(const Kolor& rgb) { _r=rgb._r; _g=rgb._g; _b=rgb._b; };
    
  // TODO
  //private:
    /*!
     * \brief Atrybut opisujacy wartosc odcieniu czerwonego.
     * 
     * Atrybut opisujacy wartosc odcieniu czerwonego.
     */
    int _r;
    
    /*!
     * \brief Atrybut opisujacy wartosc odcieniu zielonego.
     * 
     * Atrybut opisujacy wartosc odcieniu zielonego.
     */
    int _g;
    
    /*!
     * \brief Atrybut opisujacy wartosc odcieniu niebieskiego.
     * 
     * Atrybut opisujacy wartosc odcieniu niebieskiego.
     */
    int _b;
};

#endif
