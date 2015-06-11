#ifndef FLAGI_HH
#define FLAGI_HH

/*!
 * \file
 * \brief Zawiera globalne zmienne opisujace symulacje.
 *
 * W pliku znajduja sie:
 * - zmienne opisujaca stan symulacji,
 * - promien czasteczek,
 * - zalozone wymiary zbiornika,
 */

/*!
 * \brief Stan symulacji.
 * 
 * Stan symulacji to Play/Pause/Stop. Inicjalizacja w pliku zbiornik.cpp.
 * Wybor poczatkowego stanu w konstruktorze okienka.
 */
extern int STAN;

/*!
 * \brief Typ wyliczeniowy okreslajacy stany symulacji.
 * 
 * Stany symulacji to Play/Pause/Stop.
 */
enum {eSTOP,  /* Symulacja zatrzymana. */ 
      ePAUSE, /* Symulacja zamrozona. */
      ePLAY   /* Symulacja uruchomiona. */
}; 

/*!
 * \brief Promien czasteczki [px].
 * 
 * Promien czasteczki [px].
 */
const int PROMIEN  = 5;

/*!
 * \brief Dlugosc podstawy zbiornika  [px].
 * 
 * Dlugosc podstawy zbiornika [px].
 */
const int PODSTAWA = 200;

/*!
 * \brief Wysokosc zbiornika [px].
 * 
 * Wysokosc zbiornika [px].
 */
const int WYSOKOSC = 200;

/*!
 * \brief Grubosc krawedzi zbiornika [px].
 * 
 * Grubosc krawedzi zbiornika [px].
 * Grubosc jest symetryczna wzgledem osi.
 */
const int GRUBOSC  = 10;

/*!
 * \brief Suma grubosci paskow statusu itd. okienka [px].
 * 
 * Suma grubosci paskow statusu itd. okienka [px].
 * Potrzebne do liczenia pozycji.
 */
const int PASKI = 18;

#endif