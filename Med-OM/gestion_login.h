#ifndef GESTION_LOGIN_H
#define GESTION_LOGIN_H

#include <QDialog>

namespace Ui {
class gestion_login;
}

class gestion_login : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_login(QWidget *parent = nullptr);
    ~gestion_login();

private:
    Ui::gestion_login *ui;
};

#endif // GESTION_LOGIN_H
