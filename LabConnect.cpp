#include "LabConnect.h"
#include "ui_LabConnect.h"
#include <QMessageBox>
#include "globals.h"
#include "libSgen-V0.1.h"

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
    int step[] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    Gstep = step[index];
}

void LabConnect::on_pushButton_clicked()
{
    QString Fpre;
    Fpre = ui->lineEdit->text();

    int multi[] = {1,1000,1000000};
    int Ffaktor = multi[ui->comboBox_2->currentIndex()];

    int Fges = Fpre.toDouble() * Ffaktor;

    ui->lcdNumber->display(Fges);
    Sgen::set_frequency(Fges);
}

void LabConnect::on_commit_button_clicked()
{
    Sgen::set_current_c(ui->form_out->currentIndex(), GFrequenz1);
    Sgen::commit_data();

}

void LabConnect::on_u_out_valueChanged(double arg1)
{
    Sgen::regwert_u_out(arg1);
}

void LabConnect::on_u_offset_valueChanged(double arg1)
{
    Sgen::regwert_offset(arg1);
}
