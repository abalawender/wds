#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector.hh>

/*!
 * \brief makro do logowania
 *
 * Łatwe w użyciu makro poprawiające czytelność komunikatów. Pętla do...while
 * zastosowana aby wymusić poprawne użycie średnika po poleceniu.
 * \param[in] MSG - wiadomość do wyświetlenia
 */

#define LOG( MSG) do { std::cerr << "\e[32m" << __FILE__ << "\e[31m:\e[33m" << __LINE__ \
    << "\e[35m:\e[34m" << std::setw(16) << __FUNCTION__ << "\e[36m : \e[37m" << MSG << "\e[0m\n"; } while( false )


/*!
 * \file simulation.hh
 * \brief Plik z definicją klasy symulatora cieczy
 *
 * Zawiera definicję klasy i funkcji pozwalających na przeprowadzenie symulacji zachowania
 * sparametryzowanego modelu cieczy w zadanym środowisku od określonego warunku początkowego.
 */

struct params_t {
    unsigned nframes;       // Number of frames
    unsigned npframe;       // Steps per frame
    float h;                // Particle size
    float dt;               // Time step
    float rho0;             // Reference density
    float k;                // Bulk modulus
    float mu;               // Viscosity
    float gx;               // Gravity on X-axis
    float gy;               // Gravity on Y-axis
    float mass;             // Particle mass
};

params_t* setup( params_t *params );

class simulation {
    friend std::ostream& operator<<( std::ostream& _os, const simulation& _s );

    friend class Zbiornik;

    unsigned n;     //! Liczba cząstek
    float* rho;     //! Gęstości
    Vector* p;      //! Pozycje
    Vector* vh;     //! Prędkości (half step)
    Vector* v;      //! Prędkości (full step)
    Vector* a;      //! Przyspieszenia

    params_t* params;

    public:

    /*!
     * \brief konstruktor klasy
     *
     * Alokuje pamięć na potrzeby przechowania stanu symulacji
     * \param[in] _n - maksymalna liczba cząstek
     * \param[in] _param - wskaźnik na strukturę parametrów symulacji
     */
    simulation ( const unsigned& _n, params_t* _param  );
   // : n(_n),
   //             rho(new float[n]), p(new Vector[n]), vh(new Vector[n]), v(new Vector[n]), a(new Vector[n]), params( _param ) { init(); }

    /*!
     * \brief wylicza przybliżenia gęstości
     *
     * Implementuje formułę:
     * \f[
     * \rho_i = \frac{4m}{\pi h^8}\sum_{j\in N_i} (h^2-r^2)^3,
     * \f]
     * która pozwala przybliżyć wartość gęstości w miejscu i-tej cząstki na
     * podstawie jej oddziaływań ze wszystkimi innymi cząstkami w zbiorniku.
     * \note wartość ciśnienia zawizualizować można kolorem cząstki.
     */
    void computeDensity( params_t* _p );

    /*!
     * \brief wylicza przyspieszenia cząstek
     *
     * Implementuje formułę:
     * \f[
     * a_i = \frac{1}{\rho_i}\sum_{j\in N_i} f^{interact}_{ij} + g.
     * \f]
     * która pozwala przybliżyć wartość przyspieszenia każdej cząstki
     * jako sumę wektorów oddziaływań między wszystkimi cząsteczkami i wektora grawitacji
     * \note wektor grawitacji może ulegać zmianie podczas trwania symulacji
     */
    void computeAccel( params_t* params);

    /*!
     * \brief odbija cząstkę od powierzchni
     *
     * odpowiednio modyfikuje położenie cząstki oraz zmniejsza wartości prędkości i ich zwroty
     * \param[in] _barrier - odpowiednia współrzędna krawędzi
     * \param[in] i - numer cząstki
     * \param[in] getter - wskaźnik na metodę wybierającą odpowiednią współrzędną z Vectora
     */
    void dampReflect( float _barrier, unsigned i, float& (Vector::*getter)() );

    /*!
     * \brief szuka kolizji cząstek ze ścianami naczynia
     *
     * po wykryciu kolizji wywołuje dampReflect z odpowiednimi parametrami
     */
    void reflectParticles( );

    /*!
     * \brief inicjalizuje integrator
     *
     * zadaje początkowe parametry dynamiczne cząstek
     * \param[in] dt - wartość skoku czasu symulacji
     */
    void integrationInit( float dt );
    /*!
     * \brief całkuje przyspieszenia i prędkości
     *
     * odpowiada za realizację ruchu symulowanych cząstek
     * \param[in] dt - wartość skoku czasu symulacji
     */
    void integrate( float dt );

    /*!
     * \brief sprawdza przynależność punku do obszaru początkowego
     *
     * sprawdza przynależność punku do obszaru początkowego - prostokąta
     * \param[in] x - pierwsza współrzędna
     * \param[in] y - druga współrzędna
     * \return true jeśli warunek spełniony
     */
    bool boxIndicator( float x, float y );
    /*!
     * \brief sprawdza przynależność punku do obszaru początkowego
     *
     * sprawdza przynależność punku do obszaru początkowego - zewnętrza ćwierci okręgu
     * \param[in] x - pierwsza współrzędna
     * \param[in] y - druga współrzędna
     * \return true jeśli warunek spełniony
     */
    bool circleIndicator( float x, float y );

    /*!
     * \brief dodaje cząsteczki do symulacji
     *
     * iteruje po siatce punktów wewnątrz zbiornika i dodaje do symulacji te, dla których warunek określony przez funkcję containerIndicator jest spełniony
     * \param[in] params - parametry symulacji
     * \param[in] containerIndicator - warunek przynależności do obszaru
     */
    simulation& placeParticles( params_t* params, bool (simulation::*containerIndicator)( float x, float y ) );

    /*!
     * \brief inicjuje symulację
     *
     * dodaje cząstki do symulacji i określa ich początkowe parametry dynamiczne
     */
    void init();

    /*!
     * \brief realizuje krok symulacji
     *
     * odpowiada za realizację ruchu symulowanych cząstek
     */
    void step();

    /*!
     * \brief zwraca liczbę cząstek użytych do symulacji
     *
     * zwraca liczbę cząstek użytych do symulacji
     * \return liczba cząstek
     */
    const unsigned& getN() const { return n; }

};
