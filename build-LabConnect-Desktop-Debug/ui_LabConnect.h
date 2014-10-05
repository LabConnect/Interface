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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QAction *actionEinstellungen_2;
    QWidget *centralWidget;
    QDial *dial;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QLabel *creg;
    QLabel *freg;
    QMenuBar *menuBar;
    QMenu *menuLabConnect;
    QMenu *menu_ber;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *LabConnect)
    {
        if (LabConnect->objectName().isEmpty())
            LabConnect->setObjectName(QStringLiteral("LabConnect"));
        LabConnect->setEnabled(true);
        LabConnect->resize(669, 408);
        LabConnect->setAcceptDrops(false);
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
        actionEinstellungen_2 = new QAction(LabConnect);
        actionEinstellungen_2->setObjectName(QStringLiteral("actionEinstellungen_2"));
        centralWidget = new QWidget(LabConnect);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(510, 40, 151, 141));
        dial->setCursor(QCursor(Qt::OpenHandCursor));
        dial->setMouseTracking(false);
        dial->setMaximum(100);
        dial->setWrapping(true);
        dial->setNotchesVisible(true);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 50, 491, 121));
        lcdNumber->setAcceptDrops(false);
        lcdNumber->setFrameShape(QFrame::WinPanel);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(8);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber->setProperty("value", QVariant(100000));
        lcdNumber->setProperty("intValue", QVariant(100000));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 11, 90, 21));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(520, 0, 41, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(560, 0, 91, 27));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(368, 10, 121, 27));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 10, 90, 27));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(300, 10, 61, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(558, 326, 91, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 183, 101, 20));
        label_2->setFont(font);
        comboBox_3 = new QComboBox(centralWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(130, 180, 91, 27));
        creg = new QLabel(centralWidget);
        creg->setObjectName(QStringLiteral("creg"));
        creg->setGeometry(QRect(30, 250, 311, 17));
        freg = new QLabel(centralWidget);
        freg->setObjectName(QStringLiteral("freg"));
        freg->setGeometry(QRect(30, 270, 311, 17));
        LabConnect->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LabConnect);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 669, 25));
        menuLabConnect = new QMenu(menuBar);
        menuLabConnect->setObjectName(QStringLiteral("menuLabConnect"));
        menu_ber = new QMenu(menuBar);
        menu_ber->setObjectName(QStringLiteral("menu_ber"));
        LabConnect->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LabConnect);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setAcceptDrops(false);
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

        comboBox->setCurrentIndex(6);
        comboBox_2->setCurrentIndex(2);
        comboBox_3->setCurrentIndex(0);


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
        actionEinstellungen_2->setText(QApplication::translate("LabConnect", "Einstellungen", 0));
        label->setText(QApplication::translate("LabConnect", "Frequenz", 0));
        label_3->setText(QApplication::translate("LabConnect", "Step", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LabConnect", "1 Hz", 0)
         << QApplication::translate("LabConnect", "5 Hz", 0)
         << QApplication::translate("LabConnect", "10 Hz", 0)
         << QApplication::translate("LabConnect", "50 Hz", 0)
         << QApplication::translate("LabConnect", "100 Hz", 0)
         << QApplication::translate("LabConnect", "500 Hz", 0)
         << QApplication::translate("LabConnect", "1 kHz", 0)
         << QApplication::translate("LabConnect", "5 kHz", 0)
         << QApplication::translate("LabConnect", "10 kHz", 0)
         << QApplication::translate("LabConnect", "50 kHz", 0)
         << QApplication::translate("LabConnect", "100 kHz", 0)
         << QApplication::translate("LabConnect", "500 kHz", 0)
         << QApplication::translate("LabConnect", "1 MHz", 0)
        );
        pushButton->setText(QApplication::translate("LabConnect", "Manuell setzen", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("LabConnect", "Hz", 0)
         << QApplication::translate("LabConnect", "kHz", 0)
         << QApplication::translate("LabConnect", "MHz", 0)
        );
        pushButton_2->setText(QApplication::translate("LabConnect", "Ausgabe", 0));
        label_2->setText(QApplication::translate("LabConnect", "Signalform", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("LabConnect", "Sinus", 0)
         << QApplication::translate("LabConnect", "Dreieck", 0)
         << QApplication::translate("LabConnect", "Rechteck", 0)
        );
        creg->setText(QApplication::translate("LabConnect", "TextLabel", 0));
        freg->setText(QApplication::translate("LabConnect", "TextLabel", 0));
        menuLabConnect->setTitle(QApplication::translate("LabConnect", "LabConnect", 0));
        menu_ber->setTitle(QApplication::translate("LabConnect", "Hilfe", 0));
    } // retranslateUi

};

namespace Ui {
    class LabConnect: public Ui_LabConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABCONNECT_H
