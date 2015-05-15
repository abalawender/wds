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

// TODO
//extern bool PLAY;

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
    
    // TODO
    /*!
     * \brief Slot odpowiadajacy za obsluge stanu play.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci w trakcie stanu play.
     */
    void on_playButton_clicked() { PLAY = 1; } ;
    void on_pauseButton_clicked() { std::cout << "pause" << std::endl; PLAY = 0; } ;
    void on_stopButton_clicked() { PLAY = 0; } ;
    /*!
     * \brief Slot odpowiadajacy za obsluge stanu pauzy.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci w trakcie stanu pauzy.
     */
    void GdyPauza();
    
    /*!
     * \brief Slot odpowiadajacy za obsluge stanu play.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci w trakcie stanu play.
     */
    void GdyPlay();
    
    /*!
     * \brief Slot odpowiadajacy za obsluge stanu stop.
     * 
     * Odpowiada za wykonanie odpowiednich czynnosci w trakcie stanu stop.
     */
    void GdyStop();
    
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
     * Wskaznik na przycisk play.
     */
    QPushButton *playButton;
    
    /*!
     * \brief Wskaznik na przycisk pause.
     * 
     * Wskaznik na przycisk pause.
     */
    QPushButton *pauseButton;
    
    /*!
     * \brief Wskaznik na przycisk stop.
     * 
     * Wskaznik na przycisk stop.
     */
    QPushButton *stopButton; 
    
    // TODO
    QSlider *sliderSzybkoscSym;
    QLCDNumber *lcdSzybkoscSym;
    QLabel *labelSzybkoscSym;
    QLabel *labelCzasSym;
    QLCDNumber *lcdCzasSym;
    QLabel *labelLiczbaCzasteczek;
    QLCDNumber *lcdLiczbaCzasteczek;

  private:
    /*!
    * \brief Miernik czasu.
    * 
    * Miernik czasu.
    */
    QTimer _Stoper; 
}; 

#endif
