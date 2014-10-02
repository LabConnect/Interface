#include "einstellungen.h"
#include "ui_einstellungen.h"
#include "LabConnect.h"
#include <QMessageBox>
#include "globals.h"



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
    mainGui.setEnabled(true);
    mainGui.setWindowTitle("LabConnect");
    close();
}

void Einstellungen::on_comboBox_activated(const QString &arg1)
{
    GBaudRate = arg1;
}

void Einstellungen::on_pushButton_3_clicked()
{
    ui->comboBox->setCurrentIndex(4);
    GBaudRate = ui->comboBox->currentText();
}
