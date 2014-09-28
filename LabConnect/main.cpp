#include "LabConnect.h"
#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LabConnect w;
    w.show();

    return a.exec();
}
