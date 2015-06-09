#include "vector.hh"
std::ostream& operator<<( std::ostream& _os, const Vector& _s ) {
    return _os << "(" << _s.x << ", " << _s.y << ")";
}

