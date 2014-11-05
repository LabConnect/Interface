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

void Einstellungen::on_comboBox_activated(const QString &arg1)
{
    BaudRate = arg1;
}

void Einstellungen::on_setting_abort_clicked()
{
    LabConnect mainGui;

    BaudRate = GBaudRate;

    mainGui.setEnabled(true);
    close();
}

void Einstellungen::on_setting_std_clicked()
{
    ui->comboBox->setCurrentIndex(4);
    GBaudRate = ui->comboBox->currentText();
    BaudRate = GBaudRate;
}

void Einstellungen::on_setting_ok_clicked()
{
    GBaudRate = BaudRate;

    LabConnect mainGui;
    mainGui.setEnabled(true);
    close();
}
