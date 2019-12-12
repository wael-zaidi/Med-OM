#ifndef GESTION_LOGIN2_H
#define GESTION_LOGIN2_H

#include <QDialog>

namespace Ui {
class gestion_login2;
}

class gestion_login2 : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_login2(QWidget *parent = nullptr);
    ~gestion_login2();

private slots:
    void on_btn_add_login_pressed();

    void on_btn_add_login_released();

    void on_btn_edit_login_pressed();

    void on_btn_edit_login_released();

    void on_btn_edit_login_2_pressed();

    void on_btn_edit_login_2_released();

    void on_btn_historique_login_pressed();

    void on_btn_historique_login_released();

private:
    Ui::gestion_login2 *ui;
};

#endif // GESTION_LOGIN2_H
