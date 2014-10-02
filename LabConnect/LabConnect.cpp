#include "LabConnect.h"
#include "ui_LabConnect.h"
// #include <QtSerialPort/QtSerialPort>
#include "einstellungen.h"
#include <QMessageBox>
#include "globals.h"


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
        Gstep = 1000;
        break;
    }
}
