#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H

#include <QDialog>

//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class Einstellungen;
}

class Einstellungen : public QDialog
{
    Q_OBJECT

public:
    explicit Einstellungen(QWidget *parent = 0);
    ~Einstellungen();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_setting_abort_clicked();

    void on_setting_std_clicked();

    void on_setting_ok_clicked();

private:
    Ui::Einstellungen *ui;
};

#endif // EINSTELLUNGEN_H
