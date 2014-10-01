#include "einstellungen.h"
#include "ui_einstellungen.h"
#include "LabConnect.h"
#include <QMessageBox>

Einstellungen::Einstellungen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Einstellungen)
{
    ui->setupUi(this);
}

Einstellungen::~Einstellungen()
{
    delete ui;
}

void Einstellungen::on_pushButton_clicked()
{

}

void Einstellungen::on_pushButton_2_clicked()
{
    LabConnect mainGui;
    mainGui.setEnabled(true);
    close();
}

void Einstellungen::on_pushButton_4_clicked()
{

}
