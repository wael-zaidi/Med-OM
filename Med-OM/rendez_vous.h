#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H

#include <QDialog>
#include "rdv.h"
#include "ordonnance.h"
#include"arduino.h"

namespace Ui {
class Rendez_Vous;
}

class Rendez_Vous : public QDialog
{
    Q_OBJECT

public:
    explicit Rendez_Vous(QWidget *parent = nullptr);
    ~Rendez_Vous();



private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pb_supprimer_pressed();

    void on_pb_supprimer_released();
    void check_table();

    void on_tabWidget_tabBarClicked(int index);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::Rendez_Vous *ui;
    rdv ajtmp;
    ordonnance ajt;

    Arduino A; // objet temporaire


};

#endif // RENDEZ_VOUS_H
