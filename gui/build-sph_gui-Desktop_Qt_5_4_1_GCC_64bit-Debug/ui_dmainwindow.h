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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DMainWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DMainWindow)
    {
        if (DMainWindow->objectName().isEmpty())
            DMainWindow->setObjectName(QStringLiteral("DMainWindow"));
        DMainWindow->resize(400, 300);
        menuBar = new QMenuBar(DMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DMainWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(DMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DMainWindow->setStatusBar(statusBar);

        retranslateUi(DMainWindow);

        QMetaObject::connectSlotsByName(DMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DMainWindow)
    {
        DMainWindow->setWindowTitle(QApplication::translate("DMainWindow", "DMainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class DMainWindow: public Ui_DMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMAINWINDOW_H
