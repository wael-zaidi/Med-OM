#ifndef LOGIN_MODIFIER_H
#define LOGIN_MODIFIER_H

#include <QDialog>
#include"login_ajouter.h"

namespace Ui {
class login_modifier;
}

class login_modifier : public QDialog
{
    Q_OBJECT

public:
    login_ajouter login_ajouter;
    explicit login_modifier(QWidget *parent = nullptr);
    ~login_modifier();
    void login_modifier_qry();
    void login_modifier_update();
    void login_modifier_afficher_tab();

private slots:
    void on_btn_load_table_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_btn_valider_pressed();

    void on_btn_supprimer_pressed();

    void on_text_autorisation_textChanged(const QString &arg1);

    void on_text_etat_textChanged(const QString &arg1);

    void on_btn_valider_released();

    void on_btn_supprimer_released();

private:
    Ui::login_modifier *ui;
};

#endif // LOGIN_MODIFIER_H
