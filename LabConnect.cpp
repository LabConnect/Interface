#include "LabConnect.h"
#include "ui_LabConnect.h"
#include <QtSerialPort/QtSerialPort>
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

    float newValue = value;
    float change = GcurValue - newValue;

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

void LabConnect::on_commit_button_clicked()
{
    QMessageBox Ausgabe;
    float MCLK = 25000000, Register = 268435456;

    float teiler = MCLK / Register;
    int FRegWert = GFrequenz1 / teiler;

    //block1=lsb --> block4=msb
    unsigned char block1, block2, block3, block4;

    block1 = FRegWert;
    FRegWert = FRegWert >> 8;
    block2 = FRegWert;
    block2 = (block2 | 0x40) & (~0x80);
    FRegWert = FRegWert >> 6;
    block3 = FRegWert;
    FRegWert = FRegWert >> 8;
    block4 = FRegWert;
    block4 = (block4 | 0x40) & (~0x80);

    Ausgabe.setText("<Block1> " + QString::number(block1,2));
    Ausgabe.exec();

    Ausgabe.setText("<Block2> " + QString::number(block2,2));
    Ausgabe.exec();

    Ausgabe.setText("<Block3> " + QString::number(block3,2));
    Ausgabe.exec();

    Ausgabe.setText("<Block4> " + QString::number(block4,2));
    Ausgabe.exec();



    LabConnect::set_current_c();
    LabConnect::regwert_u_out();
    LabConnect::regwert_offset();

    Ausgabe.setText("<Signalform> " + ui->form_out->currentText());
    Ausgabe.exec();
}

void LabConnect::on_u_out_valueChanged(double arg1)
{
    GuAusgang = arg1;
}

void LabConnect::on_u_offset_valueChanged(double arg1)
{
    GuOffset = arg1;
}

void LabConnect::regwert_u_out()
{
    float umax = 12, bits = 510;
    int Register1, Register2;

    int ergebnis = (GuAusgang / (umax / bits));

    if (ergebnis%2==0)
    {
        Register1 = 255 - ergebnis / 2;
        Register2 = 255 - ergebnis / 2;
    }
    else
    {
        ergebnis = ergebnis- 1;
        Register1 = 255-((ergebnis / 2) + 1);
        Register2 = 255 - ergebnis / 2;
    }

    //hier kommt dann die serielle Ausgabe hin
    QMessageBox Debug;
    Debug.setText("<UOut-Reg1> " + QString::number(Register1));
    Debug.exec();

    Debug.setText("<UOut-Reg2> " + QString::number(Register2));
    Debug.exec();

    return;
}

void LabConnect::regwert_offset()
{
    float uges = 12, bits = 510;
    int Register1, Register2;

    int ergebnis = ((GuOffset + 6) / (uges / bits));

    if (ergebnis%2==0)
    {
        Register1 = ergebnis / 2;
        Register2 = ergebnis / 2;
    }
    else
    {
        ergebnis = ergebnis- 1;
        Register1 = (ergebnis / 2) + 1;
        Register2 = ergebnis / 2;
    }

    //hier kommt dann die serielle Ausgabe hin
    QMessageBox Debug;
    Debug.setText("<Offset-Reg1> " + QString::number(Register1));
    Debug.exec();

    Debug.setText("<Offset-Reg2> " + QString::number(Register2));
    Debug.exec();

    return;
}

void LabConnect::set_current_c()
{
    QMessageBox Debug;

    switch (ui->form_out->currentIndex()) {
    case 0:
        if (GFrequenz1 <= 10)
        {
            Debug.setText("<Sinus> Stellung1");
        }
        else if (GFrequenz1 <= 1000)
        {
            Debug.setText("<Sinus> Stellung2");
        }
        else
        {
            Debug.setText("<Sinus> Stellung3");
        }
        break;
    case 1:
        if (GFrequenz1 <= 10)
        {
            Debug.setText("<Dreieck> Stellung1");
        }
        else if (GFrequenz1 <= 1000)
        {
            Debug.setText("<Dreieck> Stellung2");
        }
        else
        {
            Debug.setText("<Dreieck> Stellung3");
        }
        break;
    case 2:
        Debug.setText("<Rechteck> Stellung4");
        break;
    default:
        break;
    }
    Debug.exec();
}
