#ifndef LOGIN_ADD_H
#define LOGIN_ADD_H

#include <QDialog>

namespace Ui {
class login_add;
}

class login_add : public QDialog
{
    Q_OBJECT

public:
    explicit login_add(QWidget *parent = nullptr);
    ~login_add();

private:
    Ui::login_add *ui;
};

#endif // LOGIN_ADD_H
