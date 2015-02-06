#ifndef LabConnect_H
#define LabConnect_H

#include <QMainWindow>
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

    void on_dial_valueChanged(int value);

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_commit_button_clicked();

    void on_u_out_valueChanged(double arg1);

    void on_u_offset_valueChanged(double arg1);

    void on_actionGer_te_neu_laden_triggered();

private:
    Ui::LabConnect *ui;
};


#endif // LabConnect_H
