#ifndef VECTOR_HH
#define VECTOR_HH
#include <iostream>

/*!
 * \brief klasa Vector
 *
 * Posiada metody do obsługi dwuelementowych wektorów o współrzędnych typu float
 */
class Vector {
    friend std::ostream& operator<<( std::ostream& _os, const Vector& _s );
    float x, y; //! Współrzędne wektora

    public:
    /*!
     * \brief konstruktor wektora
     *
     * Ustawia współrzędne wektora
     * \param[in] _x - pierwsza współrzędna (domyślnie: 0)
     * \param[in] _y - druga współrzędna (domyślnie: 0)
     */
    Vector( float _x=0, float _y=0 ) : x(_x), y(_y) { }
    /*!
     * \brief zwraga pierwszą współrzędną wektora
     * \return pierwsza współrzędna wektora jako stała
     */
    float  getX() const       { return x; }
    /*!
     * \brief pobiera drugą współrzędną wektora
     * \return druga współrzędna wektora jako stała
     */
    float  getY() const       { return y; }
    /*!
     * \brief pobiera pierwszą współrzędną wektora
     * \return pierwsza współrzędna wektora jako stała
     */
    float& getX()                          { return x; }
    /*!
     * \brief pobiera drugą współrzędną wektora
     * \return druga współrzędna wektora jako stała
     */
    float& getY()                          { return y; }
    /*!
     * \brief operator dodawania
     *
     * Dodaje wartość innego wektora do klasy
     * \param[in] _v - inny wektor
     * \return referencja na pierwotny obiekt
     */
    Vector& operator+= (const Vector& _v)       { x += _v.x; y += _v.y; return *this; }
    /*!
     * \brief operator odejmowania
     *
     * Odejmuje wartość innego wektora od klasy
     * \param[in] _v - inny wektor
     * \return referencja na pierwotny obiekt
     */
    Vector& operator-= (const Vector& _v)       { x -= _v.x; y -= _v.y; return *this; }
    /*!
     * \brief operator skalowania
     *
     * Skaluje wektor
     * \param[in] _c - współczynnik
     * \return referencja na pierwotny obiekt
     */
    Vector& operator*= (const float&  _c)       { x *= _c; y *= _c; return *this;}
    /*!
     * \brief operator dodawania
     *
     * Dodaje wartość dwóch wektorów
     * \param[in] _v - inny wektor
     * \return wektor będący sumą
     */
    Vector  operator+  (const Vector& _v) const { return Vector( x+_v.x,  y+_v.y); }
    /*!
     * \brief operator odejmowania
     *
     * Odejmuje wartość innego wektora od klasy
     * \param[in] _v - inny wektor
     * \return wektor będący różnicą
     */
    Vector  operator-  (const Vector& _v) const { return Vector( x-_v.x,  y-_v.y); }
    /*!
     * \brief operator skalowania
     *
     * Skaluje wektor
     * \param[in] _c - współczynnik skalowania
     * \return przeskalowany wektor
     */
    Vector  operator*  (const float&  _c) const { return Vector( x*_c,  y*_c); }
    /*!
     * \brief operator przypisania
     *
     * Przypisuje współrzędne innego wektora do klasy
     * \param[in] _v - inny wektor
     * \return referencja na pierwotny obiekt
     */
    Vector& operator=  (const Vector& _v)       { x = _v.x; y = _v.y; return *this; }
    /*!
     * \brief kwadrat normy
     *
     * Zwraca sumę kwadratów współrzędnych wektora
     * \return wartość kwadratu normy
     */
    float normSquared()                         { return x*x + y*y; }
};
#endif
