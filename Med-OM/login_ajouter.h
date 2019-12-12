#ifndef LOGIN_AJOUTER_H
#define LOGIN_AJOUTER_H

#include <QDialog>

namespace Ui {
class login_ajouter;

}

class login_ajouter : public QDialog
{
    Q_OBJECT




public:
     QString id,password,autorisation,etat;
    explicit login_ajouter(QWidget *parent = nullptr);
    ~login_ajouter();

    void login_set_labels();
    void login_qry_ajouter();


private slots:
    void on_btn_ajouter_pressed();

    void on_radio_admin_clicked();

    void on_radio_docteur_clicked();

    void on_radio_secretaire_clicked();

    void on_radio_actif_clicked();

    void on_radio_suspendu_clicked();

    void on_btn_ajouter_released();

private:
    Ui::login_ajouter *ui;
};



#endif // LOGIN_AJOUTER_H
