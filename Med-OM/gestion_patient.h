#ifndef GESTION_PATIENT_H
#define GESTION_PATIENT_H

#include <QDialog>

namespace Ui {
class gestion_patient;
}

class gestion_patient : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_patient(QWidget *parent = nullptr);
    ~gestion_patient();

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_5_pressed();

    void on_pushButton_5_released();

    void on_pushButton_14_pressed();

    bool on_pushButton_14_released();

    void on_pushButton_12_pressed();

    void on_pushButton_12_released();

    void on_radioMale_clicked();

    void on_radioFemelle_clicked();

    void on_pushButton_10_pressed();

    void on_pushButton_10_released();

    void on_pushButton_13_pressed();

    void on_pushButton_13_released();

    void on_pushButton_16_pressed();

    void on_pushButton_16_released();

    void on_pushButton_15_pressed();

    void on_pushButton_15_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_17_pressed();

    bool on_pushButton_17_released();

    void on_pushButton_38_pressed();

    void on_pushButton_38_released();

    void on_pushButton_37_pressed();

    void on_pushButton_37_released();

    void on_pushButton_18_pressed();

    void on_pushButton_18_released();

    void on_pushButton_19_pressed();

    void on_pushButton_19_released();

    void on_pushButton_35_pressed();

    void on_pushButton_35_released();

    void on_pushButton_36_pressed();

    void on_pushButton_36_released();

private:
    Ui::gestion_patient *ui;
};

#endif // GESTION_PATIENT_H
