#include "einstellungen.h"
#include "ui_einstellungen.h"
#include "LabConnect.h"
#include "globals.h"

#include <QMessageBox>
//#include <QtSerialPort>
//#include <QSerialPortInfo>


QString BaudRate;


Einstellungen::Einstellungen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Einstellungen)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentText(GBaudRate);
}

Einstellungen::~Einstellungen()
{
    delete ui;
}

void Einstellungen::on_pushButton_2_clicked()
{
    LabConnect mainGui;

    BaudRate = GBaudRate;

    mainGui.setEnabled(true);
    close();
}

void Einstellungen::on_comboBox_activated(const QString &arg1)
{
    BaudRate = arg1;
}

void Einstellungen::on_pushButton_3_clicked()
{
    ui->comboBox->setCurrentIndex(4);
    GBaudRate = ui->comboBox->currentText();
    BaudRate = GBaudRate;
    ui->comboBox_2->setCurrentIndex(2);
    ui->lineEdit->setText("25.00");
    MCLK = 25000000;
}

void Einstellungen::on_pushButton_clicked()
{
    GBaudRate = BaudRate;

    int Ffaktor;

    switch (ui->comboBox_2->currentIndex()) {
    case 0:
        Ffaktor = 1;
        break;
    case 1:
        Ffaktor = 1000;
        break;
    case 2:
        Ffaktor = 1000000;
        break;
    default:
        break;
    }

    double Fpre;
    Fpre = ui->lineEdit->text().toDouble();

    MCLK = Fpre * Ffaktor;

    LabConnect mainGui;
    mainGui.setEnabled(true);
    close();

}
