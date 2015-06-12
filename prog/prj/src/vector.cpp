#include "vector.hh"

/*!
 * \file
 * \brief Zawiera definicje metod klasy Vector.
 *
 * W pliku znajduja sie:
 * - definicja przeciezenia operatora << .
 */

std::ostream& operator<<( std::ostream& _os, const Vector& _s ) {
    return _os << "(" << _s.x << ", " << _s.y << ")";
}

