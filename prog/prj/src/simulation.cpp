#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include "simulation.hh"
#define DAMP (0.75f) //! współczynnik odbicia od ściany naczynia
#define XMAX 1.0  //! rozmiar naczynia X
#define YMAX 1.0  //! rozmiar naczynia Y

/*!
 * \file simulation.cpp
 * \brief Plik z kodem symulatora cieczy
 *
 * \TODO Zawiera definicje klas i funkcji pozwalających na przeprowadzenie symulacji zachowania
 * sparametryzowanego modelu cieczy w zadanym środowisku od określonego warunku początkowego.
 */

//std::ostream& operator<<( std::ostream& _os, const Vector& _s )  {
//    return _os << "( " << _s.x << ", " << _s.y << " )";
//}

params_t* setup( params_t *params ) {
    params->nframes	= 300;      // Number of frames
    params->npframe	= 100;      // Steps per frame
    params->h	    = 0.05;     // Particle size
    params->dt	    = 0.0004;   // Time step
    params->rho0	= 1000;     // Reference density
    params->k	    = 1000;     // Bulk modulus
    params->mu	    = 0.1;      // Viscosity
    params->gx	    = 0.0;      // Gravity on X-axis
    params->gy	    = -9.8;     // Gravity on Y-axis
    params->mass	= 1;        // Particle mass
    return params;
}

simulation::simulation ( const unsigned& _n, params_t* _param  ) : n(_n),
    rho(new float[n]), p(new Vector[n]), vh(new Vector[n]), v(new Vector[n]), a(new Vector[n]), params( _param ) { init(); }

void simulation::computeDensity( params_t* _p )
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
void simulation::computeAccel( params_t* params)
{
    // Unpack basic parameters
    const float h = params->h;
    const float rho0 = params->rho0;
    const float h2 = h*h;
    // Compute density and color
    computeDensity(params);
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

void simulation::dampReflect( float _barrier, unsigned i, float& (Vector::*getter)() ) {
    float tbounce = ((p[i].*getter)()-_barrier) / (v[i].*getter)();
    p[i] -= v[i] * (1.0-DAMP) * tbounce;

    (p[i].*getter)()  = 2*_barrier - (p[i].*getter)(); // reflect the position and velocities
    (v[i].*getter)()  = -(v[i].*getter)();
    (vh[i].*getter)() = -(vh[i].*getter)();

    v[i] *= DAMP; // damp the velocities
}

void simulation::reflectParticles( ) {
    for( size_t i = 0; i < n; ++i) {
        if( p[i].getX() < 0 ) dampReflect( 0, i, &Vector::getX);
        else if( p[i].getX() > XMAX ) dampReflect( XMAX, i, &Vector::getX);

        if( p[i].getY() < 0 ) dampReflect( 0, i, &Vector::getY);
        else if( p[i].getY() > YMAX ) dampReflect( YMAX, i, &Vector::getY);
    }
}

void simulation::integrationInit( float dt ) {
    for( unsigned i = 0; i < n; ++i) {
        vh[i] = v[i] + a[i] * (dt / 2);
        v[i] += a[i]*dt;
        p[i] += vh[i]*dt;
    }
    reflectParticles( );
}
void simulation::integrate( float dt ) {
    for( unsigned i = 0; i < n; ++i) {
        vh[i] += a[i]*dt;
        v[i] = vh[i] + a[i] * (dt / 2);
        p[i] += vh[i]*dt;
    }
    reflectParticles( );
}

bool simulation::box_indicator( float x, float y ) {
    return ( x < XMAX/2 ) && ( y > YMAX/2 );
}

simulation& simulation::place_particles( params_t* params, bool (simulation::*containerIndicator)( float x, float y ) ) {
    unsigned counter = -1;
    float hh = params->h/1.3;
    // count how many particles would fit in the region
    for( float y = 0; y < YMAX; y += hh )
        for( float x = 0; x < XMAX; x += hh )
            if( (this->*containerIndicator)( x, y ) ) {
                if( counter < n ) p[counter] = Vector( x, y );
                ++counter;
            }
    n = std::min( n, counter );

    params->mass = 1;
    computeDensity( params );
    float rhos = 0, rho2s = 0;
    for( size_t i = 0; i < n; ++i ) {
        rho2s += rho[i] * rho[i];
        rhos += rho[i];
    }
    params->mass *= params->rho0 * rhos / rho2s;
    return *this;
}

void simulation::init() {
    place_particles( params, &simulation::box_indicator );
    computeAccel( params );
    integrationInit( params->dt );
}

void simulation::step() {
    for( unsigned j = 0; j < params->npframe; ++j ) {
        computeAccel( params );
        integrate( params->dt );
    }
    LOG( "sim[0]: v " << v[0] << "\tp " << p[0] << "\ta " << a[0] );
}

std::ostream& operator<<( std::ostream& _os, const simulation& _s )  {
    for( unsigned i = 0; i < _s.n; ++i ) {
      _os.write( (char*)&_s.p[i], sizeof( Vector ) );
      _os.write( (char*)&_s.rho[i], sizeof( float ) );
    }
    return _os;
}

int funkcja_main() {
    LOG( "INIT" );
    params_t* params = setup( new params_t );
    simulation s(200, params);

    LOG( "Simulating movement of " << s.getN() << " fluid particles" );
    std::cout << "what comes next is binary data\n";
    std::cout.write( (char*)&s.getN(), sizeof(s.getN()) );

    std::cout << s;

    for( unsigned i = 0; i < params->nframes; ++i ) {
        //if( i == 300 ) params->gy = 0; // becuz fuck the gravity
        s.step();
        std::cout << s;
    }
    LOG( "DONE" );
    return 0;
}

#ifdef MAIN
int main() {
    funkcja_main();
    return 0;
}
#endif
