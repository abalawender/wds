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
 * - definicje konstruktorow oraz metod klasy OknoGlowne.
 */

OknoGlowne::OknoGlowne(QWidget *wRodzic): QMainWindow(wRodzic)
{
    STAN = eSTOP;

    /* Okno glowne */
    setWindowOpacity( 0.9 );
    setObjectName("OknoGlowne");
    resize(2.5*PODSTAWA, 2.5*WYSOKOSC);
    setMinimumSize(QSize(PODSTAWA*2.5, WYSOKOSC*2.5));
    _old_width = width();
    _old_height = height();

    /* Zbiornik */
    wZbiornik = new Zbiornik(this, Vector(width()/2-PODSTAWA/2, height()/2-WYSOKOSC/2),
            PODSTAWA, WYSOKOSC, GRUBOSC, 0);
    wZbiornik->setObjectName("Zbiornik");
    setCentralWidget(wZbiornik);

    /* Stoper */
    _Stoper.setInterval(wZbiornik->odpowiedni_czas());
    _Stoper.setSingleShot(false);
    _Stoper.start();

    /* Menu Bar*/
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 516, 25));

    menu_File = new QMenu(tr("&File"), menuBar);
    //menu_Edit = new QMenu(tr("&Edit"), menuBar);
    //menu_Help = new QMenu(tr("&Help"), menuBar);

    action_Save = new QAction(tr("&Save"), this);
    action_Save->setObjectName("action_Save"); // on_action
    action_Exit = new QAction(tr("&Exit"), this);
    action_Exit->setObjectName("action_Exit"); // on_action

    menuBar->addAction(menu_File->menuAction());
    //menu_File->addAction(action_Save);
    menu_File->addAction(action_Exit);
    //menuBar->addAction(menu_Edit->menuAction());
    //menuBar->addAction(menu_Help->menuAction());

    setMenuBar(menuBar);

    /* Status Bar */
    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    /* Tool Bar */
    //toolBar = new QToolBar(this);
    //addToolBar(Qt::TopToolBarArea, toolBar);

    /* Przyciski */
    /* Horizontal layout */
    horizontalLayoutWidget = new QWidget(this);
    horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
    horizontalLayoutWidget->setGeometry(QRect(120, 240, 270, 30));
    horizontalLayoutWidget->move(width()/2 - 270/2, height()-100);

    horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
    horizontalLayout->setSpacing(6);
    horizontalLayout->setContentsMargins(11, 11, 11, 11);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    /* Przyciski */
    playButton = new QPushButton(horizontalLayoutWidget);
    playButton->setObjectName("playButton"); // on_action
    pauseButton = new QPushButton(horizontalLayoutWidget);
    pauseButton->setObjectName("pauseButton"); // on_action
    stopButton = new QPushButton(horizontalLayoutWidget);
    stopButton->setObjectName("stopButton"); // on_action
    
    QIcon icon;
    icon.addFile(QString::fromUtf8("../../prog/prj/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
    stopButton->setIcon(icon);
    icon.addFile(QString::fromUtf8("../../prog/prj/res/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
    pauseButton->setIcon(icon);
    icon.addFile(QString::fromUtf8("../../prog/prj/res/play.png"), QSize(), QIcon::Normal, QIcon::Off);
    playButton->setIcon(icon);
    

    horizontalLayout->addWidget(playButton);
    horizontalLayout->addWidget(pauseButton);
    horizontalLayout->addWidget(stopButton);

    /* Slider kat obrotu */
    sliderKatObrotu = new QSlider(Qt::Horizontal, this);
    sliderKatObrotu->setObjectName("sliderKatObrotu");
    sliderKatObrotu->setGeometry(QRect(width()/2 - 270/2, height()-130, 270, 25));
    sliderKatObrotu->setMinimum(-180); // [stopnie]
    sliderKatObrotu->setMaximum(180);
    sliderKatObrotu->setValue(0);

    /* Czas symulacji */
    labelCzasSym = new QLabel(tr("Czas symulacji [s]"), this);
    labelCzasSym->setObjectName("labelCzasSym");
    labelCzasSym->setGeometry(QRect(20, 20, 140, 25));

    lcdCzasSym = new QLCDNumber(3, this);
    lcdCzasSym->setObjectName("lcdCzasSym");
    lcdCzasSym->setGeometry(QRect(200, 20, 64, 25));

    /* Liczba czasteczek */
    labelLiczbaCzasteczek = new QLabel(tr("Liczba czasteczek"), this);
    labelLiczbaCzasteczek->setObjectName("labelLiczbaCzasteczek");
    labelLiczbaCzasteczek->setGeometry(QRect(20, 20+30, 120, 25));

    lcdLiczbaCzasteczek = new QLCDNumber(4, this);
    lcdLiczbaCzasteczek->setObjectName(QString::fromUtf8("lcdLiczbaCzasteczek"));
    lcdLiczbaCzasteczek->setGeometry(QRect(200, 20+30, 64, 25));

    /* Szybkosc symulacji */
    labelSzybkoscSym = new QLabel(tr("Szybkosc symulacji [Hz]"), this);
    labelSzybkoscSym->setObjectName("labelSzybkoscSym");
    labelSzybkoscSym->setGeometry(QRect(20, 20+60, 180, 25));

    lcdSzybkoscSym = new QLCDNumber(3, this); // [Hz] 1/ODPOWIEDNI_CZAS
    lcdSzybkoscSym->setObjectName("lcdSzybkoscSym");
    lcdSzybkoscSym->setGeometry(QRect(200, 20+60, 64, 25));
    lcdSzybkoscSym->display(25);

    sliderSzybkoscSym = new QSlider(Qt::Horizontal, this);
    sliderSzybkoscSym->setObjectName("sliderSzybkoscSym");
    sliderSzybkoscSym->setGeometry(320, 80, 160, 25);
    sliderSzybkoscSym->setMinimum(1); // [Hz]
    sliderSzybkoscSym->setMaximum(40);
    sliderSzybkoscSym->setValue(25);

    /* CheckBox */
    gravTglButton = new QCheckBox(this);
    gravTglButton->setObjectName("gravTglButton"); // on_action
    gravTglButton->setText("Pionowa skladowa wektora grawitacji");
    gravTglButton->setGeometry(QRect(320, 50, 297, 22));
    gravTglButton->setChecked(true);
    
    /* Lepkosc */
    labelLepkosc = new QLabel(tr("Lepkosc [mPa*s]"), this);
    labelLepkosc->setObjectName("labelLepkosc");
    labelLepkosc->setGeometry(QRect(20, 20+90, 180, 25));
    
    lcdLepkosc = new QLCDNumber(4, this); // 
    lcdLepkosc->setObjectName("lcdLepkosc");
    lcdLepkosc->setGeometry(QRect(200, 20+90, 64, 25));
    lcdLepkosc->display(0.1);
    
    sliderLepkosc = new QSlider(Qt::Horizontal, this);
    sliderLepkosc->setObjectName("sliderLepkosc");
    sliderLepkosc->setGeometry(320, 110, 160, 25);
    sliderLepkosc->setMinimum(-20);
    sliderLepkosc->setMaximum(100);
    sliderLepkosc->setValue(1.0);

    /* Wczytywanie, Zapis*/
    lineEdit = new QLineEdit(this);
    //lineEdit->setGeometry(QRect(320, 20, 160, 25));
    lineEdit->setGeometry(QRect(-500, -500, 160, 25));
    lineEdit->setObjectName("lineEdit");
    lineEdit->setPlaceholderText(QString("Nazwa pliku"));

    loadButton = new QPushButton(tr("Wczytaj"), this);
    //loadButton->setGeometry(QRect(320+80, 20+30, 80, 25));
    loadButton->setGeometry(QRect(-500, -500, 80, 25));
    //loadButton->setObjectName("loadButton");

    saveButton = new QPushButton(tr("Zapisz"), this);
    //saveButton->setGeometry(QRect(320, 20+30, 80, 25));
    saveButton->setGeometry(QRect(-500, -500, 80, 25));
    saveButton->setObjectName("saveButton");

    /* connect */
    connect(wZbiornik, SIGNAL(ZglosLiczbeCzasteczek(const int)),
            lcdLiczbaCzasteczek, SLOT(display(int)));
    connect(wZbiornik, SIGNAL(ZglosCzasSymulacji(const double)),
            lcdCzasSym, SLOT(display(double)));
    connect(&_Stoper, SIGNAL(timeout()),
            this, SLOT(GdyOdpowiedniCzas()));
    connect(this, SIGNAL(ZglosNapis(const QString &)),
            this, SLOT(GdyNapis(const QString &)));
    connect(action_Exit, SIGNAL(triggered()),
            QApplication::instance(), SLOT(quit()));
    connect(sliderSzybkoscSym, SIGNAL(valueChanged(int)),
            lcdSzybkoscSym, SLOT(display(int)));

    QMetaObject::connectSlotsByName(this);
}

void OknoGlowne::on_playButton_clicked() {
    if (STAN == eSTOP) { // Start od nowa
    }
    else if (STAN == ePAUSE) {
    }
    STAN = ePLAY;
}

void OknoGlowne::on_pauseButton_clicked() {
    STAN = ePAUSE;
}

void OknoGlowne::on_stopButton_clicked() {
    STAN = eSTOP;
    wZbiornik->czas_sym() = 0.0;
    wZbiornik->Czasteczki.clear();
    wZbiornik->_Symulacja.init();
}

void OknoGlowne::on_gravTglButton_clicked() {
    wZbiornik->useGravity = !wZbiornik->useGravity;
}

/*
void OknoGlowne::on_loadButton_clicked() {
    std::string nazwa_pliku = "saved/";
    nazwa_pliku += lineEdit->text().toUtf8().constData();
    WczytajSymulacjeZPliku(nazwa_pliku);
}

void OknoGlowne::on_lineEdit_returnPressed() {
    std::string nazwa_pliku = "saved/";
    nazwa_pliku += lineEdit->text().toUtf8().constData();

    // Na razie nie robi nic.
    //WczytajSymulacjeZPliku(nazwa_pliku);
}
*/

void OknoGlowne::on_sliderKatObrotu_valueChanged(int a) {
    wZbiornik->kat_obrotu() = a;
}

void OknoGlowne::on_sliderSzybkoscSym_valueChanged(int a) {
    wZbiornik->odpowiedni_czas() = 1000.0/a; // Hz -> ms
    wZbiornik->_Stoper.setInterval(wZbiornik->odpowiedni_czas());
}

void OknoGlowne::on_sliderLepkosc_valueChanged(int a) {
  double aa = static_cast<double>(a)/10.0; //int->float
  wZbiornik->_Symulacja.params->mu = aa;
  lcdLepkosc->display(aa);
}


int OknoGlowne::licznik_plikow;

void OknoGlowne::on_action_Save_triggered() {
    if (!((STAN == eSTOP) || (STAN == ePAUSE))) {
        STAN = ePAUSE; // Zatrzymujemy do zapisu.
        ZapiszSymulacjeDoPliku();
        STAN = ePLAY; // Wznawiamy.
    }
    else {
        ZapiszSymulacjeDoPliku();
    }
}

void OknoGlowne::GdyOdpowiedniCzas() {
    QDate Data = QDate::currentDate();
    QLocale Lokalizacja(QLocale::Polish);
    QString NapisDaty = Lokalizacja.toString(Data);
    emit ZglosNapis(NapisDaty);
    
    if( wZbiornik->czas_sym() >= 10.0 ) {
      lcdCzasSym->setDigitCount(4);
    }
    else if( wZbiornik->czas_sym() >= 100.0 ) {
      lcdCzasSym->setDigitCount(5);
    }
    else if( wZbiornik->czas_sym() >= 1000.0 ) {
      lcdCzasSym->setDigitCount(6);
    }
}

void OknoGlowne::GdyNapis(const QString &Napis) {
    statusBar->showMessage(Napis);
}

void OknoGlowne::paintEvent( QPaintEvent * ) {
    horizontalLayoutWidget->move(width()/2 - 270/2, height()-100);
    wZbiornik->lewa_gora_xy() = Vector(width()/2-PODSTAWA/2, height()/2-WYSOKOSC/2);
    sliderKatObrotu->move(width()/2 - 270/2, height()-130);

    double diff_w = width() - _old_width;
    double diff_h = height() - _old_height;
    _old_width = width();
    _old_height = height();
    for (std::list<Czasteczka>::iterator it = wZbiornik->Czasteczki.begin();
            it != wZbiornik->Czasteczki.end(); it++)
    {
        (*it).xy().getX() += diff_w/2; // /2, poniewaz szerokosc zmienia sie symetrycznie
        (*it).xy().getY() += diff_h/2;
    }
}

void OknoGlowne::ZapiszSymulacjeDoPliku() {
    std::fstream plik;
    std::string nazwa_pliku = static_cast<std::string>("saved/zapis") +
        std::to_string(licznik_plikow) +
        static_cast<std::string>(".txt");
    plik.open(nazwa_pliku.c_str(), std::ios::out);
    if(plik.good()){
        licznik_plikow++;
        plik << wZbiornik->czas_sym() << " " << wZbiornik->Czasteczki.size() 
            << wZbiornik->kat_obrotu() << std::endl;
        for (std::list<Czasteczka>::iterator it = wZbiornik->Czasteczki.begin();
                it != wZbiornik->Czasteczki.end(); it++)
        {
            // TODO Co jest potrzebne do sph?
            plik << (*it).xy().getX() << " " << (*it).xy().getY() << std::endl;
        }
        plik.close();
    }
    else {
        std::cerr << "Plik nie został utworzony." << std::endl;
    }
}

void OknoGlowne::ZapiszSymulacjeDoPliku(const std::string nazwa_pliku) {
    std::fstream plik;
    plik.open(nazwa_pliku.c_str(), std::ios::out);
    if(plik.good()){
        plik << wZbiornik->czas_sym() << wZbiornik->Czasteczki.size() 
            << wZbiornik->kat_obrotu() << std::endl;
        for (std::list<Czasteczka>::iterator it = wZbiornik->Czasteczki.begin();
                it != wZbiornik->Czasteczki.end(); it++)
        {
            // TODO Co jest potrzebne do sph?
            plik << (*it).xy().getX() << " " << (*it).xy().getY() << std::endl;
        }
        plik.close();
    }
    else {
        std::cerr << "Plik nie został utworzony." << std::endl;
    }
}

void OknoGlowne::WczytajSymulacjeZPliku(const std::string nazwa_pliku) {
    std::fstream plik;
    int liczba_czasteczek;
    plik.open(nazwa_pliku.c_str(), std::ios::in);
    if(plik.good()){
        wZbiornik->Czasteczki.clear();
        plik >> wZbiornik->czas_sym() >> liczba_czasteczek >> wZbiornik->kat_obrotu();
        for (int i=0; i<liczba_czasteczek; i++)
        {
            // TODO Co jest potrzebne do sph?
            double x, y;
            plik >> x >> y;
            wZbiornik->Czasteczki.push_back(Czasteczka(
                        Vector(x, y), PROMIEN, Kolor(rand()%255, rand()%255, rand()%255)));
        }
        plik.close();
    }
    else {
        std::cerr << "Nie wczytano danych z pliku." << std::endl;
    }
}
