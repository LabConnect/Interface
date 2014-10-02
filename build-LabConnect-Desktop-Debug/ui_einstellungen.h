/********************************************************************************
** Form generated from reading UI file 'einstellungen.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EINSTELLUNGEN_H
#define UI_EINSTELLUNGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Einstellungen
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;

    void setupUi(QDialog *Einstellungen)
    {
        if (Einstellungen->objectName().isEmpty())
            Einstellungen->setObjectName(QStringLiteral("Einstellungen"));
        Einstellungen->resize(469, 417);
        pushButton = new QPushButton(Einstellungen);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 380, 99, 27));
        pushButton_2 = new QPushButton(Einstellungen);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 380, 99, 27));
        pushButton_3 = new QPushButton(Einstellungen);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 380, 201, 27));
        label = new QLabel(Einstellungen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 131, 31));
        QFont font;
        font.setPointSize(16);
        font.setUnderline(false);
        label->setFont(font);
        comboBox = new QComboBox(Einstellungen);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 60, 111, 27));
        label_2 = new QLabel(Einstellungen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 71, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        retranslateUi(Einstellungen);

        QMetaObject::connectSlotsByName(Einstellungen);
    } // setupUi

    void retranslateUi(QDialog *Einstellungen)
    {
        Einstellungen->setWindowTitle(QApplication::translate("Einstellungen", "Einstellungen", 0));
        pushButton->setText(QApplication::translate("Einstellungen", "OK", 0));
        pushButton_2->setText(QApplication::translate("Einstellungen", "Abbrechen", 0));
        pushButton_3->setText(QApplication::translate("Einstellungen", "Standardwerte \303\274bernehmen", 0));
        label->setText(QApplication::translate("Einstellungen", "Einstellungen", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Einstellungen", "1200", 0)
         << QApplication::translate("Einstellungen", "2400", 0)
         << QApplication::translate("Einstellungen", "4800", 0)
         << QApplication::translate("Einstellungen", "9600", 0)
         << QApplication::translate("Einstellungen", "19200", 0)
         << QApplication::translate("Einstellungen", "38400", 0)
         << QApplication::translate("Einstellungen", "57600", 0)
         << QApplication::translate("Einstellungen", "115200", 0)
        );
        comboBox->setCurrentText(QApplication::translate("Einstellungen", "1200", 0));
        label_2->setText(QApplication::translate("Einstellungen", "Baudrate", 0));
    } // retranslateUi

};

namespace Ui {
    class Einstellungen: public Ui_Einstellungen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNGEN_H
