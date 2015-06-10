#ifndef ZBIORNIK_HH
#define ZBIORNIK_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QImage>
#include <QStatusBar>
#include <QTime>
#include <QTimer>
#include <QDate>
#include <QLocale>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QSpinBox>
#include <QProgressBar>
#include <QLCDNumber>
#include <QPushButton>

#include <iostream>
#include <sstream>

#include "flagi.hh"
#include "czasteczka.hh"
#include "simulation.hh"

/*!
 * \file
 * \brief Zawiera definicje klasy Zbiornik i deklaracje jej metod.
 *
 * W pliku znajduja sie:
 * - definicja klasy Zbiornik (modeluje pojecie Zbiornika),
 * - deklaracje konstruktorow, metod i przeciazen ww. klasy.
 */

/*!
 * \brief Klasa modelująca zbiornik.
 *
 * Dzieki tej klasie mozliwe jest wyrysowywanie na ekranie zbiornika.
 */
class Zbiornik: public QWidget
{
  Q_OBJECT
public:
  /*!
   * \brief Konstruktor parametryczny.
   *
   * Konstruktor parametryczny.
   * \param[in, out] wRodzic - wskaznik na rodzica
   * \param[in] lewa_gora_xy - polozenie lewego gornego rogu zbiornika
   * \param[in] podstawa - dlugosc podstawy zbiornika
   * \param[in] wysokosc - wysokosc zbiornika
   * \param[in] grubosc - grubosc sciany zbiornika
   */
  Zbiornik(QWidget *wRodzic, const Vector& lewa_gora_xy,
           const double podstawa, const double wysokosc, const double grubosc, const int kat_obrotu);

  /*!
   * \brief Wirtualna metoda paintEvent wyrysowujaca obiekt na ekranie.
   *
   * Odziedziczona wirtualna metoda paintEvent.
   * \param[in, out] event - wskaznik obiekt klasy QPaintEvent
   */
  virtual void paintEvent ( QPaintEvent * event );

  /*!
   * \brief Metoda rysujaca zbiornik.
   *
   * Rysuje zbiornik o zadanych parametrach.
   * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
   * \param[in] Podstawa - dlugosc podstawy zbiornika
   * \param[in] Wysokosc - wysokosc zbiornika
   * \param[in] Grubosc - grubosc wyrysowywanego odcinka
   * \param[in] x - polozenie lewego gornego punktu zbiornika na osi x
   * \param[in] y - polozenie lewego gornego punktu zbiornika na osi y
   */
  void RysujZbiornik( QPainter& Rysownik,
                      const int Podstawa,
                      const int Wysokosc,
                      const int Grubosc,
                      const int x,
                      const int y);


  /*!
   * \brief Metoda rysujaca zbiornik wraz z czasteczkami.
   *
   * Rysuje zbiornik oraz czasteczki.
   * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
   */
  void RysujZbiornikZCzasteczkami( QPainter& Rysownik );

  /*!
   * \brief Metoda sprawdzająca czy punkt znajduje sie wewnatrz zbiornika.
   *
   * Sprawdza, czy punkt znajduje sie wewnatrz zbiornika.
   * \param[in] x - polozenie punktu na osi X,
   * \param[in] y - polozenie punktu na osi Y,
   * \return    true - jesli znajduje sie wewnatrz zbiornika,
   * \return    false - jesli nie znajduje sie wewnatrz zbiornika.
   */
  bool CzyWewnatrzZbiornika(const double x, const double y) const;

  /*!
   * \brief Metoda sprawdzająca czy punkt znajduje sie wewnatrz zbiornika.
   *
   * Sprawdza, czy punkt znajduje sie wewnatrz zbiornika.
   * \param[in] xy - polozenie punktu
   * \return    true - jesli znajduje sie wewnatrz zbiornika,
   * \return    false - jesli nie znajduje sie wewnatrz zbiornika.
   */
  bool CzyWewnatrzZbiornika(const Vector& xy) const;

  /*!
   * \brief Metoda sprawdzająca czy czasteczka znajduje sie wewnatrz zbiornika.
   *
   * Sprawdza, czy czasteczka znajduje sie wewnatrz zbiornika.
   * \param[in] cz - czasteczka do sprawdzenia
   * \return    true - jesli znajduje sie wewnatrz zbiornika,
   * \return    false - jesli nie znajduje sie wewnatrz zbiornika.
   */
  bool CzyWewnatrzZbiornika(const Czasteczka& cz) const;

  /*!
   * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
   *
   * Interfejs pozwalajacy na odczyt prywatnych danych.
   * \return _lewa_gora_xy - prywatny atrybut opisujacy wektor polozenia lewego gornego punktu zbiornika
   */
  Vector lewa_gora_xy() const { return _lewa_gora_xy; };
  /*!
   * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
   *
   * Interfejs pozwalajacy na zmiane prywatnych danych.
   * \return _podstawa - referencja na prywatny atrybut opisujacy wektor polozenia lewego gornego punktu zbiornika
   */
  Vector& lewa_gora_xy() { return _lewa_gora_xy; };
  /*!
   * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
   *
   * Interfejs pozwalajacy na odczyt prywatnych danych.
   * \return _podstawa - prywatny atrybut opisujacy dlugosc podstaw
   */
  double podstawa() const { return _podstawa; };
  /*!
   * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
   *
   * Interfejs pozwalajacy na zmiane prywatnych danych.
   * \return _podstawa - referencja na prywatny atrybut opisujacy dlugosc podstawy
   */
  double& podstawa() { return _podstawa; };
  /*!
   * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
   *
   * Interfejs pozwalajacy na odczyt prywatnych danych.
   * \return _podstawa - prywatny atrybut opisujacy wysokosc
   */
  double wysokosc() const { return _wysokosc; };
  /*!
   * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
   *
   * Interfejs pozwalajacy na zmiane prywatnych danych.
   * \return _podstawa - referencja na prywatny atrybut opisujacy wysokosc
   */
  double& wysokosc() { return _wysokosc; };
  /*!
   * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
   *
   * Interfejs pozwalajacy na odczyt prywatnych danych.
   * \return _grubosc - prywatny atrybut opisujacy grubosc sciany
   */
  double grubosc() const { return _grubosc; };
  /*!
   * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
   *
   * Interfejs pozwalajacy na zmiane prywatnych danych.
   * \return _grubosc - referencja na prywatny atrybut opisujacy grubosc sciany
   */
  double& grubosc() { return _grubosc; };
  /*!
   * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
   *
   * Interfejs pozwalajacy na odczyt prywatnych danych.
   * \return _kat_obrotu - prywatny atrybut opisujacy kat obrotu zbiornika
   */
  int kat_obrotu() const { return _kat_obrotu; };
  /*!
   * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
   *
   * Interfejs pozwalajacy na zmiane prywatnych danych.
   * \return _kat_obrotu - referencja na prywatny atrybut opisujacy kat obrotu zbiornika
   */
  int& kat_obrotu() { return _kat_obrotu; };

  /*!
   * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
   *
   * Interfejs pozwalajacy na odczyt prywatnych danych.
   * \return _czas_sym - prywatny atrybut opisujacy pomiar czasu
   */
  double czas_sym() const { return _czas_sym; };
  /*!
   * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
   *
   * Interfejs pozwalajacy na zmiane prywatnych danych.
   * \return _czas_sym - referencja na prywatny atrybut opisujacy pomiar czasu
   */
  double& czas_sym() { return _czas_sym; };

  /*!
   * \brief Interfejs pozwalajacy na odczyt prywatnych danych.
   *
   * Interfejs pozwalajacy na odczyt prywatnych danych.
   * \return odpowiedni_czas - prywatny atrybut opisujacy czas trwania symulacji
   */
  int odpowiedni_czas() const { return _odpowiedni_czas; };
  /*!
   * \brief Interfejs pozwalajacy na zmiane prywatnych danych.
   *
   * Interfejs pozwalajacy na zmiane prywatnych danych.
   * \return odpowiedni_czas - referencja na prywatny atrybut opisujacy czas trwania symulacji
   */
  int& odpowiedni_czas() { return _odpowiedni_czas; };

public slots:
  /*!
   * \brief Slot odpowiadajacy za aktualizacje danych. .
   *
   * Odpowiada za uaktualnienie zbiornika w odpowiednich momentach.
   */
  void GdyOdpowiedniCzas();

signals:
  /*!
   * \brief Sygnal zglaszajacy napis.
   *
   * Sygnal zglaszajacy napis do odpowiedniego slotu.
   * \param[in] _t1 - napis do zgloszenia
   */
  void ZglosNapis(const QString &);

  /*!
   * \brief Sygnal zglaszajacy liczbe czasteczek.
   *
   * Sygnal zglaszajacy liczbe czasteczek do odpowiedniego slotu.
   * \param[in] _t1 - liczba czasteczek do zgloszenia
   */
  void ZglosLiczbeCzasteczek(const int);

  /*!
   * \brief Sygnal zglaszajacy czas trwania symulacji.
   *
   * Sygnal zglaszajacy czas trwania symulacji do odpowiedniego slotu.
   * \param[in] _t1 - czas do zgloszenia
   */
  void ZglosCzasSymulacji(const double);

public:
  /*!
   * \brief Lista wszystkich czasteczek.
   *
   * Lista wszystkich czasteczek.
   */
  std::list<Czasteczka> Czasteczki;

  /*!
   * \brief Miernik czasu dla zbiornika.
   *
   * Miernik czasu zbiornika. Sluzy do odswiezania ekranu.
   */
  QTimer _Stoper;
  /*!
   * \brief Symulacja cieczy.
   *
   * Pozwala wykonać krok symulacji metodą SPH.
   */
  simulation _Symulacja;

private:
  /*!
   * \brief Wektor polozenia lewego gornego punktu zbiornika.
   *
   * Wektor polozenia lewego gornego punktu zbiornika.
   */
  Vector _lewa_gora_xy;
  /*!
   * \brief Dlugosc podstawy zbiornika.
   *
   * Dlugosc podstawy zbiornika.
   */
  double _podstawa;
  /*!
   * \brief Wysokosc zbiornika.
   *
   * Wysokosc zbiornika.
   */
  double _wysokosc;
  /*!
   * \brief Grubosc sciany zbiornika.
   *
   * Grubosc sciany zbiornika.
   */
  double _grubosc;
  /*!
   * \brief Kat obrotu zbiornika.
   *
   * Kat obrotu zbiornika zbiornika.
   */
  int _kat_obrotu;

  /*!
   * \brief Miernik czasu dla zbiornika.
   *
   * Miernik czasu zbiornika. Sluzy do mierzenia i wyswietlania czasu.
   */
  double _czas_sym;
  /*!
   * \brief Interwal dla timeout'ow z timera [ms].
   *
   * Interwal dla timeout'ow z timera [ms].
   */
  int _odpowiedni_czas; // [ms]
};

#endif
