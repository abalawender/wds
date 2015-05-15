#ifdef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "okno_glowne.hh"

/*! 
 * \file
 * \brief Zawiera definicje metod klasy OknoGlowne.
 * 
 * W pliku znajduja sie: 
 * - definicje konstruktorow, metod i przeciazen klasy OknoGlowne.
 */

//extern bool PLAY;

OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
  // Ui
  // TODO
  //setupUi(this);

  /* Okno glowne */
  setObjectName("OknoGlowne");
  resize(3*PODSTAWA, 3*WYSOKOSC);
    
  /* Zbiornik */
  wZbiornik = new Zbiornik(this);
  setCentralWidget(wZbiornik);
  
  /* Menu Bar*/
  menuBar = new QMenuBar(this);
  action_Save = new QAction(tr("&Save"), this);
  action_Exit = new QAction(tr("Exit"), this);
  
  menuBar->setGeometry(QRect(0, 0, 516, 25));
  
  menu_File = new QMenu(tr("&File"), menuBar);
  menu_Edit = new QMenu(tr("&Edit"), menuBar);
  menu_Help = new QMenu(tr("&Help"), menuBar);

  setMenuBar(menuBar);
  
  menuBar->addAction(menu_File->menuAction());
  menu_File->addAction(action_Save);
  menu_File->addAction(action_Exit);
  menuBar->addAction(menu_Edit->menuAction());
  menuBar->addAction(menu_Help->menuAction());
  
  /* Status Bar */
  statusBar = new QStatusBar(this);
  setStatusBar(statusBar);

  connect(&_Stoper, SIGNAL(timeout()),
          this, SLOT(GdyOdpowiedniCzas()));
  _Stoper.setInterval(ODPOWIEDNI_CZAS);
  _Stoper.setSingleShot(false);
  _Stoper.start();
  
  connect(this, SIGNAL(ZglosNapis(const QString &)),
          this, SLOT(GdyNapis(const QString &)));
  
  /* Tool Bar */
  toolBar = new QToolBar(this);
  addToolBar(Qt::TopToolBarArea, toolBar);
  
  /* Przyciski */
  /* Horizontal layout */
  horizontalLayoutWidget = new QWidget(this);
  horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
  horizontalLayoutWidget->setGeometry(QRect(120, 240, 270, 30));
  horizontalLayoutWidget
    ->move(width()/2 - 270/2, 
           height()-100);
  
  horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
  horizontalLayout->setSpacing(6);
  horizontalLayout->setContentsMargins(11, 11, 11, 11);
  horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
  horizontalLayout->setContentsMargins(0, 0, 0, 0);
  
  /* Przyciski */
  //TODO Zmienic na obrazki?
  playButton = new QPushButton(tr("Play"), horizontalLayoutWidget);
  playButton->setObjectName("playButton"); // on_action
  pauseButton = new QPushButton(tr("Pause"), horizontalLayoutWidget);
  pauseButton->setObjectName("pauseButton"); // on_action
  stopButton = new QPushButton(tr("Stop"), horizontalLayoutWidget);
  stopButton->setObjectName("stopButton"); // on_action
  // 
  connect(playButton,SIGNAL(pressed()),
          this,SLOT(GdyPlay()));
  connect(pauseButton,SIGNAL(pressed()),
          this,SLOT(GdyPauza()));
  connect(stopButton,SIGNAL(pressed()),
          this,SLOT(GdyStop()));
  
  horizontalLayout->addWidget(playButton);
  horizontalLayout->addWidget(pauseButton);
  horizontalLayout->addWidget(stopButton);
  
  // TODO
  /* Czas symulacji */
  labelCzasSym = new QLabel(tr("Czas symulacji [s]"), this);
  labelCzasSym->setObjectName("labelCzasSym");
  labelCzasSym->setGeometry(QRect(20, 20, 140, 25));
  
  lcdCzasSym = new QLCDNumber(3, this); 
  lcdCzasSym->setObjectName("lcdCzasSym");
  lcdCzasSym->setGeometry(QRect(200, 20, 64, 25));
  lcdCzasSym->display(17);
  
  //TODO
  //connect(Zbiornik, SIGNAL(valueChanged(int)),
  //        lcdSzybkoscSym, SLOT(display(int)));
  
  
  /* Liczba czasteczek */
  labelLiczbaCzasteczek = new QLabel(tr("Liczba czasteczek"), this);
  labelLiczbaCzasteczek->setObjectName("labelLiczbaCzasteczek");
  labelLiczbaCzasteczek->setGeometry(QRect(20, 20+30, 120, 25));
  
  lcdLiczbaCzasteczek = new QLCDNumber(3, this);
  lcdLiczbaCzasteczek->setObjectName(QString::fromUtf8("lcdLiczbaCzasteczek"));
  lcdLiczbaCzasteczek->setGeometry(QRect(200, 20+30, 64, 25));
  lcdLiczbaCzasteczek->display(200);
  
  //TODO
  //connect(Zbiornik, SIGNAL(valueChanged(int)),
  //        lcdSzybkoscSym, SLOT(display(int)));
  
  /* Szybkosc symulacji */
  labelSzybkoscSym = new QLabel(tr("Szybkosc symulacji [Hz]"), this);
  labelSzybkoscSym->setObjectName("labelSzybkoscSym");
  labelSzybkoscSym->setGeometry(QRect(20, 20+60, 180, 25));
  
  lcdSzybkoscSym = new QLCDNumber(3, this); // [Hz] 1/ODPOWIEDNI_CZAS
  lcdSzybkoscSym->setObjectName("lcdSzybkoscSym");
  lcdSzybkoscSym->setGeometry(QRect(200, 20+60, 64, 25));
  
  sliderSzybkoscSym = new QSlider(Qt::Horizontal, this);
  sliderSzybkoscSym->setObjectName("sliderSzybkoscSym");
  sliderSzybkoscSym->setGeometry(320, 80, 160, 25);
  sliderSzybkoscSym->setMinimum(0);
  sliderSzybkoscSym->setMaximum(50);
  
  connect(sliderSzybkoscSym, SIGNAL(valueChanged(int)),
          lcdSzybkoscSym, SLOT(display(int)));
    
  /* */
  QMetaObject::connectSlotsByName(this);
}

void OknoGlowne::GdyPlay()
{
  PLAY = true;
  std::cout << "Play " << PLAY << std::endl; 
}

void OknoGlowne::GdyPauza()
{
  PLAY = false;
  std::cout << "Pauza " << PLAY << std::endl; 
}

void OknoGlowne::GdyStop()
{
  PLAY = false;
  std::cout << "Stop " << PLAY << std::endl; 
}

void OknoGlowne::GdyOdpowiedniCzas()
{
  QDate Data = QDate::currentDate();
  QLocale Lokalizacja(QLocale::Polish);
  QString NapisDaty = Lokalizacja.toString(Data);

  emit ZglosNapis(NapisDaty);
}

void OknoGlowne::GdyNapis(const QString &Napis)
{
  statusBar->showMessage(Napis);
}
