#include "LabConnect.h"
#include "ui_LabConnect.h"
#include <QtSerialPort/QtSerialPort>
#include "einstellungen.h"

QString Version_Number = "0.1";

LabConnect::LabConnect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LabConnect)
{
    ui->setupUi(this);
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
    Version.setText("LabConnect Version " + Version_Number);
    Version.exec();
}

void LabConnect::on_actionEinstellungen_triggered()
{
    Einstellungen settings;
    settings.setModal(true);
    settings.exec();
}
