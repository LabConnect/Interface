#include "LabConnect.h"
#include "ui_LabConnect.h"
#include "einstellungen.h"
#include "globals.h"

#include <QMessageBox>
//#include <QtSerialPort>
//#include <QSerialPortInfo>


LabConnect::LabConnect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LabConnect)
{
    ui->setupUi(this);
    ui->dial->setValue(GcurValue);
}

LabConnect::~LabConnect()
{
    delete ui;
}

void LabConnect::on_actionBeenden_triggered()
{
    close();
}

void LabConnect::on_actionVersion_triggered()
{
    QMessageBox Version;
    Version.setText("LabConnect Version " + GVersionNumber);
    Version.exec();
}

void LabConnect::on_actionEinstellungen_2_triggered()
{
    Einstellungen settings;
    LabConnect me;
    me.setEnabled(false);
    settings.exec();
}

void LabConnect::on_dial_valueChanged(int value)
{

    int newValue = value;
    int change = GcurValue - newValue;

    if (newValue == 0)
    {
        if (GcurValue == 100)
            GFrequenz1 = GFrequenz1 + Gstep;
        else
            GFrequenz1 = GFrequenz1 - Gstep;
    }
    else if (newValue == 100)
    {
        if (GcurValue == 0)
            GFrequenz1 = GFrequenz1 - Gstep;
        else
            GFrequenz1 = GFrequenz1 + Gstep;
    }
    else
    {
        if (change < 0)
            GFrequenz1 = GFrequenz1 + Gstep;
        else
            GFrequenz1 = GFrequenz1 - Gstep;
     }
    GcurValue = newValue;
    ui->lcdNumber->display(GFrequenz1);

/*
    if (GFrequenz1 <= 12500000 && 0 <= GFrequenz1)
    {
            ui->lcdNumber->display(GFrequenz1);
    }
    else
    {
           if (GFrequenz1 <= 12500000)
           {
            GFrequenz1 = 12500000;
            }
           else if (GFrequenz1 <= 12500000)
           {
             GFrequenz1 = 12500000;
            }
     } */
}

void LabConnect::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        Gstep = 1;
        break;
    case 1:
        Gstep = 5;
        break;
    case 2:
        Gstep = 10;
        break;
    case 3:
        Gstep = 50;
        break;
    case 4:
        Gstep = 100;
        break;
    case 5:
        Gstep = 500;
        break;
    case 6:
        Gstep = 1000;
        break;
    case 7:
        Gstep = 5000;
        break;
    case 8:
        Gstep = 10000;
        break;
    case 9:
        Gstep = 50000;
        break;
    case 10:
        Gstep = 100000;
        break;
    case 11:
        Gstep = 500000;
        break;
    case 12:
        Gstep = 1000000;
        break;
    default:
        break;
    }
}

void LabConnect::on_pushButton_clicked()
{
    QString Fpre;
    Fpre = ui->lineEdit->text();
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

    int Fges = Fpre.toDouble() * Ffaktor;

    GFrequenz1 =  Fges;
    ui->lcdNumber->display(GFrequenz1);
}

void LabConnect::on_pushButton_2_clicked()
{
    //deklarieren lokaler Variablen
    double lokalMCLK;
    int RegWert, nullen;
    QString RegWertBin, NullStr, MSB, LSB;
    lokalMCLK = MCLK;


    //Wert für das Frequenzregister berechnen
    RegWert = GFrequenz1 / (lokalMCLK / 268435456);

    //Umwandlung in Binär
    RegWertBin = QString::number(RegWert, 2);

    //Herausfinden, wie viele nullen angehängt werden müssen
    nullen = 28 - RegWertBin.length();
    NullStr = "";

    while (NullStr.length() != nullen) {
        NullStr = NullStr + "0";
    }


    RegWertBin = NullStr + RegWertBin;

    //Bitschubserei für Register
    QStringRef Teil1(&RegWertBin, 0, 14);
    QStringRef Teil2(&RegWertBin, 14, 14);

    //Adresse für FReg1 Anhängen
    MSB = "01" + Teil1.toString();
    LSB = "01" + Teil2.toString();

    //Für Bascom SPI vorbereiten
    QStringRef M1(&MSB, 0, 8);
    QStringRef M2(&MSB, 8, 8);
    QStringRef L1(&LSB, 0, 8);
    QStringRef L2(&LSB, 8, 8);

    MSB = M2.toString() + M1.toString();
    LSB = L2.toString() + L1.toString();
}

void LabConnect::on_actionGer_te_neu_laden_triggered()
{

}
