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
#include <QCheckBox>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>

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
 * - deklaracje konstruktorow oraz metod ww. klasy.
 */

/*!
 * \brief Klasa modelujaca głowne okno aplikacji.
 *
 * Dzieki tej klasie wyswietlane jest okno glowne aplikacji.
 */
class OknoGlowne: public QMainWindow
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

   /*!
    * \brief Wirtualna metoda paintEvent wyrysowujaca obiekty na ekranie.
    *
    * Odziedziczona wirtualna metoda paintEvent.
    * Rysuje zbiornik i przyciski w nowym miejscu.
    * \param[in, out] event - wskaznik obiekt klasy QPaintEvent
    */
   virtual void paintEvent( QPaintEvent * event);

   /*!
    * \brief Metoda zapisujaca aktualny stan symulacji do automatycznie generowanego pliku.
    *
    * Zapisuje aktualny stan symulacji (czas, liczba czasteczek,
    * dane czasteczek) do automatycznie generowanego pliku.
    */
   void ZapiszSymulacjeDoPliku();

   /*!
    * \brief Metoda wczytujaca z wybranego pliku stan symulacji.
    *
    * Wczytuje stan symulacji (czas, liczba czasteczek, dane czasteczek).
    */
   void WczytajSymulacjeZPliku(const std::string nazwa_pliku);

   /*!
    * \brief Metoda zapisujaca stan symulacji do wybranego pliku.
    *
    * Zapisuje stan symulacji (czas, liczba czasteczek, dane czasteczek).
    */
   void ZapiszSymulacjeDoPliku(const std::string nazwa_pliku);

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
     * \brief Slot odpowiadajacy za obsluge stanu gravTgl.
     *
     * Odpowiada za zmianę parametru symulacji po kliknięciu gravTgl.
     */
    void on_gravTglButton_clicked();

    /*!
     * \brief Slot odpowiadajacy za wczytanie danych z pliku.
     *
     * Odpowiada za wczytanie danych z pliku.
     */
    void on_loadButton_clicked();

    /*!
     * \brief Slot odpowiadajacy za wczytanie danych z pliku.
     *
     * Odpowiada za wczytanie danych z pliku.
     */
    void on_lineEdit_returnPressed();

    /*!
     * \brief Slot odpowiadajacy za zmiane wartosci slidera.
     *
     * Odpowiada za wykonanie odpowiednich czynnosci zwiazanych
     * z szybkoscia symulacji po zmianie wartosci slidera.
     */
    void on_sliderSzybkoscSym_valueChanged(int a);

    /*!
     * \brief Slot odpowiadajacy za zmiane wartosci slidera.
     *
     * Odpowiada za wykonanie odpowiednich czynnosci zwiazanych
     * z katem obrotu po zmianie wartosci slidera.
     */
    void on_sliderKatObrotu_valueChanged(int a);

    /*!
    * \brief Slot odpowiadajacy za przycisniecie przycisku Save.
    *
    * Odpowiada za wykonanie odpowiednich czynnosci po przycisnieciu Save.
    */
    void on_action_Save_triggered();

  signals:
    /*!
    * \brief Sygnal zglaszajacy napis.
    *
    * Sygnal zglaszajacy napis do odpowiedniego slotu.
    * \param[in] _t1 - napis do zgloszenia
    */
    void ZglosNapis(const QString &);

  private:
    /*!
     * \brief Sluzy do generowania unikatowych nazw plikow wyjsciowych.
     *
     * Sluzy do generowania unikatowych nazw plikow wyjsciowych.
     */
    int static licznik_plikow;

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
     * \brief Wskaznik na check box gravTgl.
     *
     * Wskaznik na check box gravTgl. Zeruje wektor grawitacji.
     */
    QCheckBox *gravTglButton;

    /*!
     * \brief Wskaznik na przycisk Wczytaj.
     *
     * Wskaznik na przycisk Wczytaj. Wczytuje symulacje.
     */
    QPushButton *loadButton;

    /*!
     * \brief Wskaznik na przycisk Zapisz.
     *
     * Wskaznik na przycisk Zapisz. Zapisuje symulacje.
     */
    QPushButton *saveButton;

    /*!
     * \brief Wskaznik na slider.
     *
     * Wskaznik na slider. Steruje katem obrotu.
     */
    QSlider *sliderKatObrotu;

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

    /*!
     * \brief Wskaznik na linijke do wpisywania tekstu.
     *
     * Wskazuje linijke do wpisywania tekstu.
     */
    QLineEdit *lineEdit;

private:
    /*!
    * \brief Miernik czasu.
    *
    * Miernik czasu.
    */
    QTimer _Stoper;

private:
  /*!
   * \brief Stara szerokosc okienka.
   *
   * Stara szerokosc okienka.
   * Potrzebne do umieszczania elementów w odpowiednich miejscach po zmianie wymiarów okienka.
   */
  double _old_width;
  /*!
   * \brief Stara wysokosc okienka.
   *
   * Stara wysokosc okienka.
   * Potrzebna do umieszczania elementów w odpowiednich miejscach po zmianie wymiarów okienka.
   */
  double _old_height;
};

#endif
