#ifndef KOLOR_HH
#define KOLOR_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

class Kolor
{
  public:
    Kolor(int r, int g, int b) { _r = r; _g = g; _b = b; };
    Kolor(const Kolor& rgb) { _r=rgb._r; _g=rgb._g; _b=rgb._b; };
    int _r;
    int _g;
    int _b;
};

#endif
