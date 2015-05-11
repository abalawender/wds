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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DMainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
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
        DMainWindow->resize(516, 341);
        centralWidget = new QWidget(DMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 240, 269, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        playButton = new QPushButton(horizontalLayoutWidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout->addWidget(playButton);

        pauseButton = new QPushButton(horizontalLayoutWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(horizontalLayoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout->addWidget(stopButton);

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

        retranslateUi(DMainWindow);

        QMetaObject::connectSlotsByName(DMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DMainWindow)
    {
        DMainWindow->setWindowTitle(QApplication::translate("DMainWindow", "DMainWindow", 0));
        playButton->setText(QApplication::translate("DMainWindow", "Play", 0));
        pauseButton->setText(QApplication::translate("DMainWindow", "Pause", 0));
        stopButton->setText(QApplication::translate("DMainWindow", "Stop", 0));
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
