#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H

#include <QDialog>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Einstellungen *ui;
};

#endif // EINSTELLUNGEN_H
