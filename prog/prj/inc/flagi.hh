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
const int PROMIEN  = 10;

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
 */
const int GRUBOSC  = 3;

#endif