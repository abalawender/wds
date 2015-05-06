#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
//#define M_PI (3.141592654)
#define DAMP 0.75
#define XMAX 1.5
#define YMAX 1.5

#define LOG( MSG) do { std::cerr << "\e[32m" << __FILE__ << "\e[31m:\e[33m" << __LINE__ \
    << "\e[35m:\e[34m" << std::setw(16) << __FUNCTION__ << "\e[36m : \e[37m" << MSG << "\e[0m\n"; } while( false )

class Vector {
    public:
        float x, y;
        Vector( float _x=0, float _y=0 ) : x(_x), y(_y) { }
        Vector& operator+= (const Vector& _v) { x += _v.x; y += _v.y; return *this; }
        Vector& operator-= (const Vector& _v) { x -= _v.x; y -= _v.y; return *this; }
        Vector& operator*= (const float& _c) { x *= _c; y *= _c; return *this;}
        Vector operator+ (const Vector& _v) const { return Vector( x+_v.x,  y+_v.y); }
        Vector operator- (const Vector& _v) const { return Vector( x-_v.x,  y-_v.y); }
        Vector operator* (const float& _c) const { return Vector( x*_c,  y*_c); }
        Vector& operator= (const Vector& _v) { x = _v.x; y = _v.y; return *this; }
        float normSquared() { return x*x+y*y; }
        friend std::ostream& operator<<( std::ostream& _os, const Vector& _s );
};

struct state_t {
    unsigned n;     // Number of particles
    float* rho;     // Densities
    Vector* p;      // Positions
    Vector* vh;     // Velocities (half step)
    Vector* v;      // Velocities (full step)
    Vector* a;      // Accelerations
    friend std::ostream& operator<<( std::ostream& _os, const state_t* _s );
};

std::ostream& operator<<( std::ostream& _os, const Vector& _s )  {
    return _os << "( " << _s.x << ", " << _s.y << " )";
}
std::ostream& operator<<( std::ostream& _os, const state_t* _s )  {
    _os.write( (char*)_s->p, sizeof( Vector )*_s->n );
    return _os;
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

state_t* alloc( const unsigned& n ) {
    state_t *ret = new state_t;
    ret->n = n;
    ret->rho = new float[ n ];
    ret->p   = new Vector[ n ];
    ret->vh  = new Vector[ n ];
    ret->v   = new Vector[ n ];
    ret->a   = new Vector[ n ];
    return ret;
}

void compute_density(state_t* _s, params_t* _p)
{
    int n = _s->n;
    float* rho = _s->rho;
    const Vector* p = _s->p;
    float h = _p->h;
    float h2 = h*h;
    float h8 = ( h2*h2 )*( h2*h2 );
    float C = 4 * _p->mass / M_PI / h8;

    memset(rho, 0, n*sizeof(float));
    for (int i = 0; i < n; ++i) {
        rho[i] += 4 * _p->mass / M_PI / h2;
        for (int j = i+1; j < n; ++j) {
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

void compute_accel(state_t* state, params_t* params)
{
    // Unpack basic parameters
    const float h= params->h;
    const float rho0 = params->rho0;
    const float k= params->k;
    const float mu= params->mu;
    const float mass = params->mass;
    const float h2= h*h;
    // Unpack system state
    const float* rho = state->rho;
    const Vector* p= state->p;
    const Vector* v= state->v;
    Vector* a= state->a;
    int n = state->n;
    // Compute density and color
    compute_density(state, params);
    // Start with gravity and surface forces
    Vector gravity(params->gx, params->gy);
    for (int i = 0; i < n; ++i) {
        a[i] = gravity;
    }
    // Constants for interaction term
    float C0 = mass / M_PI / ( (h2)*(h2) );
    float Cp = 15*k;
    float Cv = -40*mu;
    // Now compute interaction forces
    for (int i = 0; i < n; ++i) {
        const float rhoi = rho[i];
        for (int j = i+1; j < n; ++j) {
            Vector dp = p[i] - p[j];
            float r2 = dp.normSquared();
            if (r2 < h2) {
                const float rhoj = rho[j];
                float q = sqrt(r2)/h;
                float u = 1-q;
                float w0 = C0 * u/rhoi/rhoj;
                float wp = w0 * Cp * (rhoi+rhoj-2*rho0) * u/q;
                float wv = w0 * Cv;

                Vector dv = v[i] - v[j];
                a[i] += dp*wp + dv*wv;
                a[j] -= dp*wp + dv*wv;
            }
        }
    }
}

void damp_reflect_x( float _barrier, state_t* _s, unsigned i ) {
    if( !_s->v[i].x ) return;   // ignore static
    float tbounce = (_s->p[i].x-_barrier) / _s->v[i].x;
    _s->p[i] -= _s->v[i] * (1-DAMP) * tbounce;

    _s->p[i].x = 2*_barrier - _s->p[i].x; // reflect the position and velocities
    _s->v[i].x = -_s->v[i].x;
    _s->vh[i].x = -_s->vh[i].x;

    _s->v[i] *= DAMP; // damp the velocities
    _s->vh[i] *= DAMP;
}

void damp_reflect_y( float _barrier, state_t* _s, unsigned i ) {
    if( !_s->v[i].y ) return;   // ignore static
    float tbounce = (_s->p[i].y-_barrier) / _s->v[i].y;
    _s->p[i] -= _s->v[i] * (1-DAMP) * tbounce;

    _s->p[i].y = 2*_barrier - _s->p[i].y; // reflect the position and velocities
    _s->v[i].y = -_s->v[i].y;
    _s->vh[i].y = -_s->vh[i].y;

    _s->v[i] *= DAMP; // damp the velocities
    _s->vh[i] *= DAMP;
}


void reflect_bc( state_t* _s ) {
    for( int i = 0; i < _s->n; ++i) {
        if( _s->p[i].x < 0 )    damp_reflect_x( 0, _s, i);
        else if( _s->p[i].x > XMAX ) damp_reflect_x( XMAX, _s, i);

        if( _s->p[i].y < 0 )    damp_reflect_y( 0, _s, i);
        else if( _s->p[i].y > YMAX ) damp_reflect_y( YMAX, _s, i);
    }
}

void leapfrog_start( state_t* _s, float dt ) {
    for( int i = 0; i < _s->n; ++i) {
        _s->vh[i] = _s->v[i] + _s->a[i] * (dt / 2);
        _s->v[i] += _s->a[i]*dt;
        _s->p[i] += _s->vh[i]*dt;
    }
    reflect_bc( _s );
}
void leapfrog_step( state_t* _s, float dt ) {
    for( int i = 0; i < _s->n; ++i) {
        _s->vh[i] += _s->a[i]*dt;
        _s->v[i] = _s->vh[i] + _s->a[i] * (dt / 2);
        _s->p[i] += _s->vh[i]*dt;
    }
    reflect_bc( _s );
}

void check_state( state_t* s)
{
    for (int i = 0; i < s->n; ++i) {
        if( !( s->p[i].x >= 0 || s->p[i].x <= XMAX ) ) LOG( "MAJOR FUCKUP " << i
                << ": " << s->p[i].x << ", " << s->p[i].y );
        if( !( s->p[i].y >= 0 || s->p[i].y <= YMAX ) ) LOG( "MAJOR FUCKUP " << i
                << ": " << s->p[i].x << ", " << s->p[i].y );
    }
    for (int i = 0; i < s->n; ++i) {
        assert( s->p[i].x >= 0 || s->p[i].x <= XMAX );
        assert( s->p[i].y >= 0 || s->p[i].y <= YMAX );
    }
}

typedef bool (*indicate_fun_t)(float, float);

bool box_indicator( float x, float y ) {
    return ( x < XMAX/2 ) && ( y > YMAX/2 );
}

state_t* place_particles( params_t* params, indicate_fun_t indicate_fun ) {
    unsigned n = 0;
    float hh = params->h/1.3; // [TODO] why 1.3 ??
    // count how many particles would fit in the region
    for( float x = 0; x < XMAX; x += hh )
        for( float y = 0; y < YMAX; y += hh )
            if( indicate_fun( x, y ) ) ++n;
    state_t* state = alloc( n );
    for( float x = 0; x < XMAX; x += hh )
        for( float y = 0; y < YMAX; y += hh )
            if( indicate_fun( x, y ) ) state->p[--n] = Vector( x, y );

    params->mass = 1;
    compute_density( state, params );
    float rhos = 0, rho2s = 0;
    for( int i = 0; i < state->n; ++i ) {
        rho2s += (state->rho[i]) * (state->rho[i]);
        rhos += state->rho[i];
    }
    params->mass *= params->rho0 * rhos / rho2s;
    return state;
}

void setup( params_t *params ) {
    params->nframes	= 400;      // Number of frames
    params->npframe	= 100;      // Steps per frame
    params->h	    = 0.05;     // Particle size
    params->dt	    = 0.0001;   // Time step
    params->rho0	= 1000;     // Reference density
    params->k	    = 1000;     // Bulk modulus
    params->mu	    = 0.1;      // Viscosity
    params->gx	    = 0.0;        // Gravity on X-axis
    params->gy	    = -9.8;     // Gravity on Y-axis
    params->mass	= 1;        // Particle mass
}

int main() {
    params_t* params = new params_t;
    LOG( "INIT" );
    setup (params);
    state_t* state = place_particles( params, box_indicator );
    LOG( "Simulating movement of " << state->n << " fluid particles" );
    std::cout << "what comes next is binary data\n";
    std::cout.write( (char*)&state->n, sizeof(state->n) );

    compute_accel( state, params );
    leapfrog_start( state, params->dt );
    check_state( state );
    std::cout << state;

    for( int i = 0; i < params->nframes; ++i ) {
        for( int j = 0; j < params->npframe; ++j ) {
            compute_accel( state, params );
            leapfrog_step( state, params->dt );
            check_state( state );
        }
        std::cout << state;
    }
    LOG( "DONE" );
    return 0;
}
