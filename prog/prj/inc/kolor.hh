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
    
    /*!
     * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
     *
     * Interfejs pozwalajacy na odczyt prywatnych danych.
     * \return _r - prywatny atrybut opisujacy czerwony odcien
     */
    int r() const { return _r; };
    /*!
     * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
     *
     * Interfejs pozwalajacy na zmiane prywatnych danych.
     * \return _r - referencja na prywatny atrybut opisujacy czerwony odcien
     */
    int& r() { return _r; };
    
    /*!
     * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
     *
     * Interfejs pozwalajacy na odczyt prywatnych danych.
     * \return _g - prywatny atrybut opisujacy zielony odcien
     */
    int g() const { return _g; };
    /*!
     * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
     *
     * Interfejs pozwalajacy na zmiane prywatnych danych.
     * \return _g - referencja na prywatny atrybut opisujacy zielony odcien
     */
    int& g() { return _g; };
    
    /*!
     * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
     *
     * Interfejs pozwalajacy na odczyt prywatnych danych.
     * \return _b - prywatny atrybut opisujacy niebieski odcien
     */
    int b() const { return _b; };
    /*!
     * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
     *
     * Interfejs pozwalajacy na zmiane prywatnych danych.
     * \return _b - referencja na prywatny atrybut opisujacy niebieski odcien
     */
    int& b() { return _b; };
    
  private:
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
