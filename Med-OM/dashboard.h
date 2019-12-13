#ifndef DASHBOARD_H
#define DASHBOARD_H
#include"arduino.h"
#include"rendez_vous.h"
#include <QDialog>

namespace Ui {
class dashboard;
}

class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();
    // QString temp_login;
     void temp_login(QString n);

private slots:
    void on_btn_gestion_patient_pressed();

    void on_btn_gestion_patient_released();

    void on_btn_gestion_login_pressed();

    void on_btn_gestion_login_released();
    void closeEvent(QCloseEvent *event);

    void on_btn_gestion_login_2_released();

private:
    Ui::dashboard *ui;

    QByteArray data; // variable contenant les données reçues

    Arduino A;
   // Rendez_Vous *r;

protected:
  //  void closeEvent(QCloseEvent *event);

};

#endif // DASHBOARD_H
