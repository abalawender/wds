#include <iostream>
#include <cstring>
#include <cmath>
//#define M_PI (3.141592654)
#define DAMP 0.75
#define XMAX 1
#define YMAX 1

class Vector {
    public:
        float x, y;
        Vector( float _x=1.1, float _y=1.2 ) : x(_x), y(_y) { }
        Vector& operator+= (const Vector& _v) { x += _v.x; y += _v.y; return *this; }
        Vector& operator-= (const Vector& _v) { x -= _v.x; y -= _v.y; return *this; }
        Vector& operator*= (const float& _c) { x *= _c; y *= _c; return *this;}
        Vector operator+ (const Vector& _v) const { return Vector( x*_v.x,  y*_v.y); }
        Vector operator- (const Vector& _v) const { return Vector( x-_v.x,  y-_v.y); }
        Vector operator* (const float& _c) const { return Vector( x*_c,  y*_c); }
        Vector& operator= (const Vector& _v) { x = _v.x; y = _v.y; return *this; }
        float normSquared() { return x*x+y*y; }
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

std::ostream& operator<<( std::ostream& _os, const state_t* _s )  {
    _os.write( (char*)_s->v, sizeof( Vector )*_s->n );
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
    float Cp =15*k;
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

                Vector dv = v[i] -v [j];
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
    //for (int i = 0; i < s->n; ++i) {
    //    float xi = s->x[2*i+0];
    //    float yi = s->x[2*i+1];
    //    assert( xi >= 0 || xi <= 1 );
    //    assert( yi >= 0 || yi <= 1 );
    //}
}


int main() {
    state_t* state = alloc( 200 );
    params_t* params;

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
    return 0;
}
