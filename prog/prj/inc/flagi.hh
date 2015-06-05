#ifndef FLAGI_HH
#define FLAGI_HH

/*!
 * \file
 * \brief Zawiera globalne zmienne opisujace symulacje.
 *
 * W pliku znajduja sie:
 * - zmienne opisujaca stan symulacji,
 * - poczatkowy promien czasteczek,
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
      ePAUSE, /* Symulacja wstrzymana. */
      ePLAY   /* Symulacja wykonuje sie. */
}; 

/*!
 * \brief Promien czasteczki.
 * 
 * Promien czasteczki.
 */
const int PROMIEN  = 5;

/*!
 * \brief Dlugosc podstawy zbiornika.
 * 
 * Dlugosc podstawy zbiornika.
 */
const int PODSTAWA = 200;

/*!
 * \brief Wysokosc zbiornika.
 * 
 * Wysokosc zbiornika.
 */
const int WYSOKOSC = 200;

/*!
 * \brief Grubosc krawedzi zbiornika.
 * 
 * Grubosc krawedzi zbiornika.
 * Grubosc jest symetryczna wzgledem osi.
 */
const int GRUBOSC  = 10;

/*!
 * \brief Suma grubosci paskow statusu itd. okienka.
 * 
 * Suma grubosci paskow statusu itd. okienka.
 * Potrzebne do liczenia pozycji srodka
 */
const int PASKI = 18;

#endif