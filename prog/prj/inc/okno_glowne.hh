#ifndef OKNO_GLOWNE_HH
#define OKNO_GLOWNE_HH

#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>

#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QStatusBar>
#include <QTime>
#include <QDate>
#include <QLocale>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QSpinBox>
#include <QProgressBar>
#include <QLCDNumber>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include <iostream>
#include <sstream>
#include <list>
#include "flagi.hh"
#include "kolor.hh"
#include "czasteczka.hh"
#include "zbiornik.hh"
#include "dmainwindow.h"

/*! 
 * \file
 * \brief Zawiera definicje klasy OknoGlowne i deklaracje jej metod.
 * 
 * W pliku znajduja sie: 
 * - definicja klasy OknoGlowne (modeluje glowne okno aplikacji),
 * - deklaracje konstruktorow, metod i przeciazen ww. klasy.
 */

//////////////////////////////////////////////////////////
/*!
 * \brief Klasa modelujaca głowne okno aplikacji.
 *
 * Dzieki tej klasie wyswietlane jest okno glowne aplikacji.
 */
class OknoGlowne: public QMainWindow//, private Ui::DMainWindow
{
   Q_OBJECT
  public:
    /*!
     * \brief Konstruktor.
     * 
     * Konstruktor parametryczny.
     * \param[in, out] wRodzic - wskaznik na rodzica 
     */
   OknoGlowne(QWidget *wRodzic = NULL/*nullptr*/);
   
  public slots:
    /*!
     * \brief Slot odpowiadajacy za aktualizacje danych. .
     * 
     * Odpowiada za uaktualnienie okienka w odpowiednich momentach.
     */
    void GdyOdpowiedniCzas(); 
    
    /*!
     * \brief Slot odpowiadajacy za wyswietlenie napisu po otrzymaniu sygnalu.
     * 
     * Odpowiada za wyswietlenie napisu na belce statusowej.
     * \param[in] Napis - napis do wyswietlenia
     */
    void GdyNapis(const QString &);
    
    /*!
     * \brief Slot odpowiadajacy za obsluge stanu play.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci w trakcie stanu play.
     */
    void on_playButton_clicked();
    
    /*!
     * \brief Slot odpowiadajacy za obsluge stanu pauza.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci w trakcie stanu pauza.
     */
    void on_pauseButton_clicked();
    
    /*!
     * \brief Slot odpowiadajacy za obsluge stanu stop.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci w trakcie stanu stop.
     */
    void on_stopButton_clicked();
    
    /*!
     * \brief Slot odpowiadajacy za zmiane wartosci slidera.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci po zmianie wartosci slidera.
     */
    void on_sliderSzybkoscSym_valueChanged(int a);
    
    //TODO czy jest cos takiego?
    void on_OknoGlowne_resized();
    
  signals:
    /*!
    * \brief Sygnal zglaszajacy napis.
    * 
    * Sygnal zglaszajacy napis do odpowiedniego slotu.
    * \param[in] _t1 - napis do zgloszenia
    */
    void ZglosNapis(const QString &);

  public:
    /*!
     * \brief Wskaznik na zbiornik.
     * 
     * Wskaznik na zbiornik.
     */
    Zbiornik *wZbiornik;
    
    /*!
     * \brief Wskaznik na pasek menu.
     * 
     * Wskaznik na pasek menu.
     */
    QMenuBar *menuBar;
    
    /*!
     * \brief Wskaznik na akcje przycisku menu Save.
     * 
     * Wskaznik na akcje przycisku menu Save.
     */
    QAction *action_Save;
    
    /*!
     * \brief Wskaznik na akcje przycisku menu Exit.
     * 
     * Wskaznik na akcje przycisku menu Exit.
     */
    QAction *action_Exit;
    
    /*!
     * \brief Wskaznik na akcje przycisku menu File.
     * 
     * Wskaznik na akcje przycisku menu File.
     */
    QMenu *menu_File;
    
    /*!
     * \brief Wskaznik na akcje przycisku menu Edit.
     * 
     * Wskaznik na akcje przycisku menu Edit.
     */
    QMenu *menu_Edit;
    
    /*!
     * \brief Wskaznik na akcje przycisku menu Help.
     * 
     * Wskaznik na akcje przycisku menu Help.
     */
    QMenu *menu_Help;
    
    /*!
     * \brief Wskaznik na pasek statusowy.
     * 
     * Wskaznik na pasek statusowy.
     */
    QStatusBar *statusBar;
    
    /*!
     * \brief Wskaznik na pasek narzedziowy.
     * 
     * Wskaznik na pasek narzedziowy.
     */
    QToolBar *toolBar;
    
    /*!
     * \brief Wskaznik na obszar do horyzontalnego rozmieszczenia przyciskow.
     * 
     * Wskaznik na obszar do horyzontalnego rozmieszczenia przyciskow.
     */
    QHBoxLayout *horizontalLayout;
    
    /*!
     * \brief Wskaznik na widget odpowiedzialny za horyzontalne wyswietlenie przyciskow.
     * 
     * Wskaznik na widget odpowiedzialny za horyzontalne wyswietlenie przyciskow.
     */
    QWidget *horizontalLayoutWidget;
    
    /*!
     * \brief Wskaznik na przycisk play.
     * 
     * Wskaznik na przycisk play. Uruchamia symulacje.
     */
    QPushButton *playButton;
    
    /*!
     * \brief Wskaznik na przycisk pause.
     * 
     * Wskaznik na przycisk pause. Wstrzymuje symulacje.
     */
    QPushButton *pauseButton;
    
    /*!
     * \brief Wskaznik na przycisk stop.
     * 
     * Wskaznik na przycisk stop. Zatrzymuje symulacje.
     */
    QPushButton *stopButton; 
    
    /*!
     * \brief Wskaznik na slider.
     * 
     * Wskaznik na slider. Steruje szybkoscia symulacji.
     */
    QSlider *sliderSzybkoscSym;
    
    /*!
     * \brief Wskaznik na LCD z szybkoscia symulacji.
     * 
     * Wskaznik na LCD z szybkoscia symulacji. Wyswietla jej szybkosc.
     */
    QLCDNumber *lcdSzybkoscSym;
    
    /*!
     * \brief Wskaznik na etykiete z szybkoscia symulacji.
     * 
     * Etykieta dla szybkosci symulacji.
     */
    QLabel *labelSzybkoscSym;
    
    /*!
     * \brief Wskaznik na etykiete z czasem symulacji.
     * 
     * Etykieta dla czasu symulacji.
     */
    QLabel *labelCzasSym;
    
    /*!
     * \brief Wskaznik na LCD z czasem trwania symulacji.
     * 
     * Wskaznik na LCD z szybkoscia symulacji. Wyswietla jej czas trwania.
     */
    QLCDNumber *lcdCzasSym;
    
    /*!
     * \brief Wskaznik na etykiete z liczbe czasteczek.
     * 
     * Etykieta dla liczby symulowanych czasteczek.
     */
    QLabel *labelLiczbaCzasteczek;
    
    /*!
     * \brief Wskaznik na LCD z liczbe czasteczek.
     * 
     * Wyswietla liczbe symulowanych czasteczek.
     */
    QLCDNumber *lcdLiczbaCzasteczek;
    
public:
    /*!
    * \brief Miernik czasu.
    * 
    * Miernik czasu.
    */
    QTimer _Stoper; 
}; 

#endif
