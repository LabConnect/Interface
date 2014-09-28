#ifndef LabConnect_H
#define LabConnect_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <string>


namespace Ui {
class LabConnect;
}

class LabConnect : public QMainWindow
{
    Q_OBJECT

public:
    explicit LabConnect(QWidget *parent = 0);
    ~LabConnect();

private slots:
    void on_actionBeenden_triggered();

    void on_actionVersion_triggered();

    void on_actionEinstellungen_triggered();

private:
    Ui::LabConnect *ui;
};

#endif // LabConnect_H
