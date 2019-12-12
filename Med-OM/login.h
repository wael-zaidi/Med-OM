#ifndef LOGIN_H
#define LOGIN_H
#include"arduino.h"

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();

private slots:
    void on_login_clicked();

    void on_login_pressed();

    void on_login_released();

    void on_show_password_pressed();

    void on_show_password_released();

private:
    Ui::Login *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // LOGIN_H
