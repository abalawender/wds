/********************************************************************************
** Form generated from reading UI file 'dmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMAINWINDOW_H
#define UI_DMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DMainWindow
{
public:
    QAction *action_Save;
    QAction *action_Exit;
    QAction *actionExit;
    QAction *actionPlay;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QSlider *sliderSzybkoscSym;
    QLCDNumber *lcdSzybkoscSym;
    QLineEdit *lineSzybkoscSym;
    QLineEdit *lineCzasSym;
    QLCDNumber *lcdCzasSym;
    QLineEdit *lineLiczbaCzasteczek;
    QLCDNumber *lcdLiczbaCzasteczek;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DMainWindow)
    {
        if (DMainWindow->objectName().isEmpty())
            DMainWindow->setObjectName(QString::fromUtf8("DMainWindow"));
        DMainWindow->setEnabled(true);
        DMainWindow->resize(516, 341);
        action_Save = new QAction(DMainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_Exit = new QAction(DMainWindow);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        actionExit = new QAction(DMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPlay = new QAction(DMainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        centralWidget = new QWidget(DMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(516, 0));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 240, 295, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        playButton = new QPushButton(horizontalLayoutWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        horizontalLayout->addWidget(playButton);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        pauseButton = new QPushButton(horizontalLayoutWidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../prog/prj/res/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon);

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../prog/prj/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);

        horizontalLayout->addWidget(stopButton);

        sliderSzybkoscSym = new QSlider(centralWidget);
        sliderSzybkoscSym->setObjectName(QString::fromUtf8("sliderSzybkoscSym"));
        sliderSzybkoscSym->setGeometry(QRect(320, 80, 160, 29));
        sliderSzybkoscSym->setOrientation(Qt::Horizontal);
        lcdSzybkoscSym = new QLCDNumber(centralWidget);
        lcdSzybkoscSym->setObjectName(QString::fromUtf8("lcdSzybkoscSym"));
        lcdSzybkoscSym->setGeometry(QRect(250, 80, 64, 23));
        lineSzybkoscSym = new QLineEdit(centralWidget);
        lineSzybkoscSym->setObjectName(QString::fromUtf8("lineSzybkoscSym"));
        lineSzybkoscSym->setGeometry(QRect(120, 80, 113, 27));
        lineCzasSym = new QLineEdit(centralWidget);
        lineCzasSym->setObjectName(QString::fromUtf8("lineCzasSym"));
        lineCzasSym->setGeometry(QRect(120, 120, 113, 27));
        lcdCzasSym = new QLCDNumber(centralWidget);
        lcdCzasSym->setObjectName(QString::fromUtf8("lcdCzasSym"));
        lcdCzasSym->setGeometry(QRect(250, 120, 64, 23));
        lineLiczbaCzasteczek = new QLineEdit(centralWidget);
        lineLiczbaCzasteczek->setObjectName(QString::fromUtf8("lineLiczbaCzasteczek"));
        lineLiczbaCzasteczek->setGeometry(QRect(120, 150, 113, 27));
        lcdLiczbaCzasteczek = new QLCDNumber(centralWidget);
        lcdLiczbaCzasteczek->setObjectName(QString::fromUtf8("lcdLiczbaCzasteczek"));
        lcdLiczbaCzasteczek->setGeometry(QRect(250, 150, 64, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 80, 67, 17));
        DMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 516, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        DMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DMainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(DMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        DMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Save);
        menu_File->addAction(actionExit);

        retranslateUi(DMainWindow);

        QMetaObject::connectSlotsByName(DMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DMainWindow)
    {
        DMainWindow->setWindowTitle(QApplication::translate("DMainWindow", "DMainWindow", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("DMainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        action_Exit->setText(QApplication::translate("DMainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("DMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("DMainWindow", "Play", 0, QApplication::UnicodeUTF8));
        playButton->setText(QApplication::translate("DMainWindow", "Play", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QString());
        stopButton->setText(QString());
        lineSzybkoscSym->setText(QApplication::translate("DMainWindow", "Szybkosc symulacji", 0, QApplication::UnicodeUTF8));
        lineCzasSym->setText(QApplication::translate("DMainWindow", "Czas symulacji", 0, QApplication::UnicodeUTF8));
        lineLiczbaCzasteczek->setText(QApplication::translate("DMainWindow", "Liczba cz\304\205steczek", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DMainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("DMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("DMainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("DMainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("DMainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DMainWindow: public Ui_DMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMAINWINDOW_H
