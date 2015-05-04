#ifndef CIECZ_HH
#define CIECZ_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <QPainter>

#include <list>
#include "kolor.hh"
#include "czasteczka.hh"

//////////////////////////////////////////////////////////
/*!
 * \file
 * \brief Klasa rysujaca zbiornik.
 * Dzieki tej klasie wyrysowywany jest zbiornik na ekranie.
 */
class Zbiornik: public QWidget 
{ 
    Q_OBJECT
  public:
    /*!
		 * \brief Konstruktor
		 * \param[in, out] wRodzic - wskaznik na rodzica 
		 */
    Zbiornik(QWidget *wRodzic = nullptr);
    virtual void paintEvent ( QPaintEvent * event );
    /*!
		 * \brief Wyrysowuje zbiornik.
		 * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
		 * \param[in] Podstawa - dlugosc podstawy zbiornika 
		 * \param[in] Wysokosc - wysokosc zbiornika
		 * \param[in] Grubosc - grubosc wyrysowywanego odcinka
		 */
    void RysujZbiornik( QPainter& Rysownik, 
                        const int Podstawa,
                        const int Wysokosc,
                        const int Grubosc,
                        const int x,
                        const int y);
    
    /*!
		 * \brief Wyrysowuje czasteczke.
		 * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
		 * \param[in] Promien - promien czasteczki 
		 * \param[in] x - polozenie x czasteczki
		 * \param[in] y - polozenie y czasteczki
		 */                    
    void RysujCzasteczke( QPainter&    Rysownik, 
                          const int    Promien,
                          const Kolor  RGB,
                          const double x,
                          const double y);
                          
    void RysujZbiornikZCzasteczkami( QPainter& Rysownik );

  public slots:
    void GdyOdpowiedniCzas(); 
  
  signals:  
    void ZglosNapis(const QString &);
    
  public:
    std::list<Czasteczka> Czasteczki;
    
  private:
    QTimer _Stoper;

}; 

//////////////////////////////////////////////////////////
/*!
 * \file
 * \brief Główne okno aplikacji.
 * Wyswietlane jest jako okno glowne aplikacji.
 */
class OknoGlowne: public QMainWindow 
{ 
   Q_OBJECT
  public:
    /*!
		 * \brief Konstruktor
		 * \param[in, out] wRodzic - wskaznik na rodzica 
		 */
   OknoGlowne(QWidget *wRodzic = nullptr);
  public slots:
    void GdyNapis(const QString &);
}; 


#endif
