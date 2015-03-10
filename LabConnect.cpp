#include "LabConnect.h"
#include "ui_LabConnect.h"
#include <QMessageBox>
#include "lib/libLabConnect.h"

QString VersionNumber = "V0.3";
int curValue = 1750;
int step = 1000;
int Frequenz1 = 1750;
LabConnect::LabConnect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LabConnect)
{
    ui->setupUi(this);
    //ui->dial->setValue(curValue);
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
    Version.setText("LabConnect Version " + VersionNumber);
    Version.exec();
}

void LabConnect::on_dial_valueChanged(int value)
{

    float newValue = value;
    float change = curValue - newValue;

    if (newValue == 0)
    {
        if (curValue == 100)
            Frequenz1 = Frequenz1 + step;
        else
            Frequenz1 = Frequenz1 - step;
    }
    else if (newValue == 100)
    {
        if (curValue == 0)
            Frequenz1 = Frequenz1 - step;
        else
            Frequenz1 = Frequenz1 + step;
    }
    else
    {
        if (change < 0)
            Frequenz1 = Frequenz1 + step;
        else
            Frequenz1 = Frequenz1 - step;
     }
    curValue = newValue;
    ui->lcdNumber->display(Frequenz1);
    Sgen::SetFrequency(Frequenz1);
}

void LabConnect::on_comboBox_activated(int index)
{
    int step_local[] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    step = step_local[index];
}

void LabConnect::on_pushButton_clicked()
{
    QString Fpre;
    Fpre = ui->lineEdit->text();

    int multi[] = {1,1000,1000000};
    int Ffaktor = multi[ui->comboBox_2->currentIndex()];

    int Fges = Fpre.toDouble() * Ffaktor;

    ui->lcdNumber->display(Fges);
    Sgen::SetFrequency(Fges);
}

void LabConnect::on_commit_button_clicked()
{
    Sgen::SetWaveform(ui->form_out->currentIndex());
    Sgen::CommitData();

}

void LabConnect::on_u_out_valueChanged(double arg1)
{
    Sgen::RegwertUout(arg1 * 1000);
}

void LabConnect::on_u_offset_valueChanged(double arg1)
{
    Sgen::RegwertOffset(arg1);
}

void LabConnect::on_actionGer_te_neu_laden_triggered()
{
    int DeviceFound;
    //DeviceFound = USB::Open();
    if (DeviceFound == 0)
    {
        ui->commit_button->setEnabled(true);
    }
    else if (DeviceFound == 1)
    {
        QMessageBox notfound;
        notfound.setText("Es wurden keine LabConnect Geräte gefunden! Bitte stelle sicher, dass alle Geräte korrekt angeschlossen sind und überprüfe gegebenenfalls die Verbindung.");
        notfound.exec();
    }
}

void LabConnect::on_pushButton_2_clicked()
{
    close();
}
void LabConnect::on_dial_voltage_valueChanged(int value)
{

}

void LabConnect::on_verticalSlider_valueChanged(int value)
{
    ui->current_bar->setValue(value);
}
