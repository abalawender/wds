#include <QApplication>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "okno_glowne.hh"

/*! 
 * \file
 * \brief Zawiera ogolna strukture funkcji main.
 * 
 * W funkcji main wyroznia sie: 
 * - utworznie obiektu klasy QApplication i wstepne przetworzenie argumentow z linii wywolania,
 * - utworzenie okna aplikacji,
 * - wymuszenie ukazania sie okna,
 * - uruchomienie obslugi petli zdarzen dla calej aplikacji.
 */

int main( int argc, char * argv[] ) 
{
  srand(time(NULL));
  
  QApplication App(argc,argv);
  OknoGlowne   Okno;
 
  Okno.show();
 
  return App.exec();
}
