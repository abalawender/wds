#ifndef ZBIORNIK_HH
#define ZBIORNIK_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <QApplication>
#include <QColor>
#include <QPainter>
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

/*! 
 * \file
 * \brief Zawiera definicje klasy Zbiornik i deklaracje jej metod.
 * 
 * W pliku znajduja sie: 
 * - definicja klasy Zbiornik (modeluje pojecie Zbiornika),
 * - deklaracje konstruktorow, metod i przeciazen ww. klasy.
 */

// TODO
//extern bool PLAY;

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

/*!
 * \brief Interwal dla timeout'ow z timera [ms].
 * 
 * Interwal dla timeout'ow z timera [ms].
 */
const int ODPOWIEDNI_CZAS = 25; // [ms]

//////////////////////////////////////////////////////////
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
   * \brief Konstruktor.
   * 
   * Konstruktor parametryczny.
   * \param[in, out] wRodzic - wskaznik na rodzica 
   */
  Zbiornik(QWidget *wRodzic = NULL/*nullptr*/); 
  
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
   * \brief Metoda rysujaca czasteczke.
   * 
   * Rysuje czasteczke o zadanych parametrach
   * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
   * \param[in] Promien - promien czasteczki 
   * \param[in] RGB - kolor czasteczki w formacie RGB
   * \param[in] x - polozenie czasteczki na osi x 
   * \param[in] y - polozenie czasteczki na osi y 
   */                    
  void RysujCzasteczke( QPainter&    Rysownik, 
                        const int    Promien,
                        const Kolor  RGB,
                        const double x,
                        const double y);
  
  /*!
   * \brief Metoda rysujaca zbiornik wraz z czasteczkami.
   * 
   * Rysuje zbiornik oraz czasteczki.
   * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
   */        
  void RysujZbiornikZCzasteczkami( QPainter& Rysownik );
  
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
  
  void ZglosLiczbeCzasteczek(const int);
  
  void ZglosCzasSymulacji(const double);
  
public:
  /*!
   * \brief Lista wszystkich czasteczek.
   * 
   * Lista wszystkich czasteczek.
   */
  std::list<Czasteczka> Czasteczki;
  
private:
  /*!
   * \brief Miernik czasu.
   * 
   * Miernik czasu.
   */
  QTimer _Stoper; 
}; 

#endif