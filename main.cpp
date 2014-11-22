#include "LabConnect.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LabConnect w;
    w.show();

    return a.exec();
}
