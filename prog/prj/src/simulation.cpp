#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#define DAMP 0.75 //! współczynnik odbicia od ściany naczynia
#define XMAX 1.0  //! rozmiar naczynia X
#define YMAX 1.0  //! rozmiar naczynia Y

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
 * \file simulation.cpp
 * \brief Plik z kodem symulatora cieczy
 *
 * Zawiera definicje klas i funkcji pozwalających na przeprowadzenie symulacji zachowania
 * sparametryzowanego modelu cieczy w zadanym środowisku od określonego warunku początkowego.
 */

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
    const float  getX() const                   { return x; }
    /*!
     * \brief pobiera drugą współrzędną wektora
     * \return druga współrzędna wektora jako stała
     */
    const float  getY() const                    { return y; }
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
    float normSquared()                         { return x*x+y*y; }
};

std::ostream& operator<<( std::ostream& _os, const Vector& _s )  {
    return _os << "( " << _s.x << ", " << _s.y << " )";
}

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

void setup( params_t *params ) {
    params->nframes	= 700;      // Number of frames
    params->npframe	= 100;      // Steps per frame
    params->h	    = 0.05;     // Particle size
    params->dt	    = 0.0001;   // Time step
    params->rho0	= 1000;     // Reference density
    params->k	    = 1000;     // Bulk modulus
    params->mu	    = 0.1;      // Viscosity
    params->gx	    = 0.0;      // Gravity on X-axis
    params->gy	    = -9.8;     // Gravity on Y-axis
    params->mass	= 1;        // Particle mass
}
class simulation {
    friend std::ostream& operator<<( std::ostream& _os, const simulation& _s );

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
     * \param[in] rozmiar
     */
    simulation ( const unsigned& _n, params_t* _param  ) : n(_n), params( _param ),
                rho(new float[n]), p(new Vector[n]), vh(new Vector[n]), v(new Vector[n]), a(new Vector[n]) { }

    /*!
     * \brief funkcja
     *
     * \f[
     * |I| = \left| \alpha \right|
     * \f]
     */
    void compute_density( params_t* _p )
    {
        float h = _p->h;
        float h2 = h*h;
        float h8 = ( h2*h2 )*( h2*h2 );
        float C = 4 * _p->mass / M_PI / h8;

        memset(rho, 0, n*sizeof(float));
        for (unsigned i = 0; i < n; ++i) {
            rho[i] += 4 * _p->mass / M_PI / h2;
            for (unsigned j = i+1; j < n; ++j) {
                Vector dp = p[i]-p[j];
                float z = h2 - dp.normSquared();
                if (z > 0) {
                    float rho_ij = C*z*z*z;
                    rho[i] += rho_ij;
                    rho[j] += rho_ij;
                }
            }
        }
    }

    void compute_accel( params_t* params)
    {
        // Unpack basic parameters
        const float h = params->h;
        const float rho0 = params->rho0;
        const float h2 = h*h;
        // Compute density and color
        compute_density(params);
        // Start with gravity and surface forces
        Vector gravity(params->gx, params->gy);
        for (unsigned i = 0; i < n; ++i) {
            a[i] = gravity;
        }
        // Constants for interaction term
        float C0 = params->mass / M_PI / ( h2*h2 );
        float Cp = 15 * params->k;
        float Cv = -40 * params->mu;
        // Now compute interaction forces
        for (unsigned i = 0; i < n; ++i) {
            const float rhoi = rho[i];
            for (unsigned j = i+1; j < n; ++j) {
                Vector dp = p[i] - p[j];
                float r2 = dp.normSquared();
                if (r2 < h2) {
                    const float rhoj = rho[j];
                    Vector dv = v[i] - v[j];
                    float q = sqrt(r2) / h;
                    float u = 1-q;
                    float w0 = C0 * u/rhoi/rhoj;
                    float wp = w0 * Cp * (rhoi+rhoj-2*rho0) * u/q;
                    float wv = w0 * Cv;

                    a[i] += dp*wp + dv*wv;
                    a[j] -= dp*wp + dv*wv;
                }
            }
        }
    }

    void damp_reflect_x( float _barrier, unsigned i ) {
        if( !v[i].getX() ) return;   // ignore static
        float tbounce = (p[i].getX()-_barrier) / v[i].getX();
        p[i] -= v[i] * (1-DAMP) * tbounce;

        p[i].getX() = 2*_barrier - p[i].getX(); // reflect the position and velocities
        v[i].getX() = -v[i].getX();
        vh[i].getX() = -vh[i].getX();

        v[i] *= DAMP; // damp the velocities
        vh[i] *= DAMP;
    }

    void damp_reflect_y( float _barrier, unsigned i ) {
        if( !v[i].getY() ) return;   // ignore static
        float tbounce = (p[i].getY()-_barrier) / v[i].getY();
        p[i] -= v[i] * (1-DAMP) * tbounce;

        p[i].getY() = 2*_barrier - p[i].getY(); // reflect the position and velocities
        v[i].getY() = -v[i].getY();
        vh[i].getY() = -vh[i].getY();

        v[i] *= DAMP; // damp the velocities
        vh[i] *= DAMP;
    }


    void reflect_bc( ) {
        for( size_t i = 0; i < n; ++i) {
            if( p[i].getX() < 0 ) damp_reflect_x( 0, i);
            else if( p[i].getX() > XMAX ) damp_reflect_x( XMAX, i);

            if( p[i].getY() < 0 ) damp_reflect_y( 0, i);
            else if( p[i].getY() > YMAX ) damp_reflect_y( YMAX, i);
        }
    }

    void leapfrog_start( float dt ) {
        for( unsigned i = 0; i < n; ++i) {
            vh[i] = v[i] + a[i] * (dt / 2);
            v[i] += a[i]*dt;
            p[i] += vh[i]*dt;
        }
        reflect_bc( );
    }
    void leapfrog_step( float dt ) {
        for( unsigned i = 0; i < n; ++i) {
            vh[i] += a[i]*dt;
            v[i] = vh[i] + a[i] * (dt / 2);
            p[i] += vh[i]*dt;
        }
        reflect_bc( );
    }

    void check_state( )
    {
        for (unsigned i = 0; i < n; ++i) {
            assert( p[i].getX() >= 0 || p[i].getX() <= XMAX );
            assert( p[i].getY() >= 0 || p[i].getY() <= YMAX );
        }
    }

    typedef bool (simulation::*indicate_fun_t)(float, float);

    bool box_indicator( float x, float y ) {
        return ( x < XMAX/2 ) && ( y > YMAX/2 );
    }

    simulation& place_particles( params_t* params, indicate_fun_t indicate_fun ) {
        unsigned counter = -1;
        float hh = params->h/1.3;
        // count how many particles would fit in the region
        for( float y = 0; y < YMAX; y += hh )
            for( float x = 0; x < XMAX; x += hh )
                if( (this->*indicate_fun)( x, y ) ) {
                    if( counter < n ) p[counter] = Vector( x, y );
                    ++counter;
                }
        n = std::min( n, counter );

        params->mass = 1;
        compute_density( params );
        float rhos = 0, rho2s = 0;
        for( size_t i = 0; i < n; ++i ) {
            rho2s += rho[i] * rho[i];
            rhos += rho[i];
        }
        params->mass *= params->rho0 * rhos / rho2s;
        return *this;
    }

    void init() {
        place_particles( params, &simulation::box_indicator );
        compute_accel( params );
        leapfrog_start( params->dt );
        check_state();
    }
    void go() {
        for( unsigned j = 0; j < params->npframe; ++j ) {
            compute_accel( params );
            leapfrog_step( params->dt );
            check_state();
        }
    }
    const unsigned& getN() const { return n; }

};

std::ostream& operator<<( std::ostream& _os, const simulation& _s )  {
    for( unsigned i = 0; i < _s.n; ++i ) {
        _os.write( (char*)&_s.p[i], sizeof( Vector ) );
        _os.write( (char*)&_s.rho[i], sizeof( float ) );
    }
    return _os;
}

int main() {
    params_t* params = new params_t;
    LOG( "INIT" );
    setup (params);
    simulation s(200, params);

    LOG( "Simulating movement of " << s.getN() << " fluid particles" );
    std::cout << "what comes next is binary data\n";
    std::cout.write( (char*)&s.getN(), sizeof(s.getN()) );

    s.init();
    std::cout << s;

    for( unsigned i = 0; i < params->nframes; ++i ) {
    //    //if( i == 300 ) params->gy = 0; // becuz fuck the gravity
    //    for( unsigned j = 0; j < params->npframe; ++j ) {
    //        compute_accel( state, params );
    //        leapfrog_step( state, params->dt );
    //        check_state( state );
    //    }
        s.go();
        std::cout << s;
    }
    LOG( "DONE" );
    return 0;
}
