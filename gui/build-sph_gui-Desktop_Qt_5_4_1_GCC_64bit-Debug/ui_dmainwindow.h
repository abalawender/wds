/********************************************************************************
** Form generated from reading UI file 'dmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMAINWINDOW_H
#define UI_DMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

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
    QCommandLinkButton *commandLinkButton;
    QToolButton *toolButton;
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
            DMainWindow->setObjectName(QStringLiteral("DMainWindow"));
        DMainWindow->setEnabled(true);
        DMainWindow->resize(516, 341);
        action_Save = new QAction(DMainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        action_Exit = new QAction(DMainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        actionExit = new QAction(DMainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionPlay = new QAction(DMainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        centralWidget = new QWidget(DMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(516, 0));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 240, 295, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        playButton = new QPushButton(horizontalLayoutWidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout->addWidget(playButton);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        pauseButton = new QPushButton(horizontalLayoutWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../prog/prj/res/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon);

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../prog/prj/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);

        horizontalLayout->addWidget(stopButton);

        sliderSzybkoscSym = new QSlider(centralWidget);
        sliderSzybkoscSym->setObjectName(QStringLiteral("sliderSzybkoscSym"));
        sliderSzybkoscSym->setGeometry(QRect(320, 80, 160, 29));
        sliderSzybkoscSym->setOrientation(Qt::Horizontal);
        lcdSzybkoscSym = new QLCDNumber(centralWidget);
        lcdSzybkoscSym->setObjectName(QStringLiteral("lcdSzybkoscSym"));
        lcdSzybkoscSym->setGeometry(QRect(250, 80, 64, 23));
        lineSzybkoscSym = new QLineEdit(centralWidget);
        lineSzybkoscSym->setObjectName(QStringLiteral("lineSzybkoscSym"));
        lineSzybkoscSym->setGeometry(QRect(120, 80, 113, 27));
        lineCzasSym = new QLineEdit(centralWidget);
        lineCzasSym->setObjectName(QStringLiteral("lineCzasSym"));
        lineCzasSym->setGeometry(QRect(120, 120, 113, 27));
        lcdCzasSym = new QLCDNumber(centralWidget);
        lcdCzasSym->setObjectName(QStringLiteral("lcdCzasSym"));
        lcdCzasSym->setGeometry(QRect(250, 120, 64, 23));
        lineLiczbaCzasteczek = new QLineEdit(centralWidget);
        lineLiczbaCzasteczek->setObjectName(QStringLiteral("lineLiczbaCzasteczek"));
        lineLiczbaCzasteczek->setGeometry(QRect(120, 150, 113, 27));
        lcdLiczbaCzasteczek = new QLCDNumber(centralWidget);
        lcdLiczbaCzasteczek->setObjectName(QStringLiteral("lcdLiczbaCzasteczek"));
        lcdLiczbaCzasteczek->setGeometry(QRect(250, 150, 64, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 67, 17));
        commandLinkButton = new QCommandLinkButton(centralWidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(340, 110, 187, 41));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(360, 170, 24, 25));
        DMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 516, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        DMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DMainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(DMainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
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
        DMainWindow->setWindowTitle(QApplication::translate("DMainWindow", "DMainWindow", 0));
        action_Save->setText(QApplication::translate("DMainWindow", "&Save", 0));
        action_Exit->setText(QApplication::translate("DMainWindow", "&Exit", 0));
        actionExit->setText(QApplication::translate("DMainWindow", "Exit", 0));
        actionPlay->setText(QApplication::translate("DMainWindow", "Play", 0));
        playButton->setText(QApplication::translate("DMainWindow", "Play", 0));
        pauseButton->setText(QString());
        stopButton->setText(QString());
        lineSzybkoscSym->setText(QApplication::translate("DMainWindow", "Szybkosc symulacji", 0));
        lineCzasSym->setText(QApplication::translate("DMainWindow", "Czas symulacji", 0));
        lineLiczbaCzasteczek->setText(QApplication::translate("DMainWindow", "Liczba cz\304\205steczek", 0));
        label->setText(QApplication::translate("DMainWindow", "TextLabel", 0));
        commandLinkButton->setText(QApplication::translate("DMainWindow", "CommandLinkButton", 0));
        toolButton->setText(QApplication::translate("DMainWindow", "...", 0));
        menu_File->setTitle(QApplication::translate("DMainWindow", "&File", 0));
        menu_Edit->setTitle(QApplication::translate("DMainWindow", "&Edit", 0));
        menu_Help->setTitle(QApplication::translate("DMainWindow", "&Help", 0));
        toolBar->setWindowTitle(QApplication::translate("DMainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class DMainWindow: public Ui_DMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMAINWINDOW_H
