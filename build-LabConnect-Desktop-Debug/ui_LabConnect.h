/********************************************************************************
** Form generated from reading UI file 'LabConnect.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABCONNECT_H
#define UI_LABCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabConnect
{
public:
    QAction *actionGer_te_neu_laden;
    QAction *actionAlle_Verbindungen_trennen;
    QAction *actionBeenden;
    QAction *actionVersion;
    QAction *actionCredits;
    QAction *actionHilfe;
    QAction *actionEinstellungen;
    QAction *actionEinstellungen_2;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menuLabConnect;
    QMenu *menu_ber;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *LabConnect)
    {
        if (LabConnect->objectName().isEmpty())
            LabConnect->setObjectName(QStringLiteral("LabConnect"));
        LabConnect->setEnabled(true);
        LabConnect->resize(573, 403);
        actionGer_te_neu_laden = new QAction(LabConnect);
        actionGer_te_neu_laden->setObjectName(QStringLiteral("actionGer_te_neu_laden"));
        actionAlle_Verbindungen_trennen = new QAction(LabConnect);
        actionAlle_Verbindungen_trennen->setObjectName(QStringLiteral("actionAlle_Verbindungen_trennen"));
        actionBeenden = new QAction(LabConnect);
        actionBeenden->setObjectName(QStringLiteral("actionBeenden"));
        actionVersion = new QAction(LabConnect);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionCredits = new QAction(LabConnect);
        actionCredits->setObjectName(QStringLiteral("actionCredits"));
        actionHilfe = new QAction(LabConnect);
        actionHilfe->setObjectName(QStringLiteral("actionHilfe"));
        actionEinstellungen = new QAction(LabConnect);
        actionEinstellungen->setObjectName(QStringLiteral("actionEinstellungen"));
        actionEinstellungen_2 = new QAction(LabConnect);
        actionEinstellungen_2->setObjectName(QStringLiteral("actionEinstellungen_2"));
        centralWidget = new QWidget(LabConnect);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 170, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 120, 99, 27));
        LabConnect->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LabConnect);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 573, 25));
        menuLabConnect = new QMenu(menuBar);
        menuLabConnect->setObjectName(QStringLiteral("menuLabConnect"));
        menu_ber = new QMenu(menuBar);
        menu_ber->setObjectName(QStringLiteral("menu_ber"));
        LabConnect->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LabConnect);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LabConnect->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuLabConnect->menuAction());
        menuBar->addAction(menu_ber->menuAction());
        menuLabConnect->addAction(actionGer_te_neu_laden);
        menuLabConnect->addAction(actionEinstellungen_2);
        menuLabConnect->addSeparator();
        menuLabConnect->addAction(actionAlle_Verbindungen_trennen);
        menuLabConnect->addAction(actionBeenden);
        menu_ber->addAction(actionCredits);
        menu_ber->addAction(actionVersion);
        menu_ber->addSeparator();
        menu_ber->addAction(actionHilfe);

        retranslateUi(LabConnect);

        QMetaObject::connectSlotsByName(LabConnect);
    } // setupUi

    void retranslateUi(QMainWindow *LabConnect)
    {
        LabConnect->setWindowTitle(QApplication::translate("LabConnect", "LabConnect", 0));
        actionGer_te_neu_laden->setText(QApplication::translate("LabConnect", "Ger\303\244te neu laden", 0));
        actionAlle_Verbindungen_trennen->setText(QApplication::translate("LabConnect", "Alle Verbindungen trennen", 0));
        actionBeenden->setText(QApplication::translate("LabConnect", "Beenden", 0));
        actionVersion->setText(QApplication::translate("LabConnect", "Version", 0));
        actionCredits->setText(QApplication::translate("LabConnect", "Credits", 0));
        actionHilfe->setText(QApplication::translate("LabConnect", "Hilfe", 0));
        actionEinstellungen->setText(QApplication::translate("LabConnect", "Einstellungen", 0));
        actionEinstellungen_2->setText(QApplication::translate("LabConnect", "Einstellungen", 0));
        pushButton->setText(QApplication::translate("LabConnect", "Baud Rate", 0));
        pushButton_2->setText(QApplication::translate("LabConnect", "set 19200", 0));
        menuLabConnect->setTitle(QApplication::translate("LabConnect", "LabConnect", 0));
        menu_ber->setTitle(QApplication::translate("LabConnect", "Hilfe", 0));
    } // retranslateUi

};

namespace Ui {
    class LabConnect: public Ui_LabConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABCONNECT_H
