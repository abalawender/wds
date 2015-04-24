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

/*!
 * \file
 * \brief Kanwa dla pozostalych widgetow.
 * Jest miejscem dla umieszczania innych widgetow.
 */
class Kanwa: public QWidget {
 public:
  /*!
	 * \brief Konstruktor
	 * \param[in, out] wRodzic - wskaznik na rodzica 
	 */
  Kanwa(QWidget *wRodzic = 0L);
};

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
   OknoGlowne(QWidget *wRodzic = 0L);
  public slots:
   
}; 

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
    Zbiornik(QWidget *wRodzic = 0L);
    virtual void paintEvent ( QPaintEvent * event );
    /*!
		 * \brief Wyrysowuje zbiornik.
		 * \param[in, out] Rysownik - referencja na obiekt klasy QPainter
		 * \param[in] Podstawa - dlugosc podstawy zbiornika 
		 * \param[in] Wysokosc - wysokosc zbiornika
		 * \param[in] Grubosc - grubosc wyrysowywanego odcinka
		 */
    void RysujZbiornik( QPainter& Rysownik, 
                        int       Podstawa,
                        int       Wysokosc,
                        int       Grubosc);

  public slots:

  signals:  

  private:

}; 

#endif
