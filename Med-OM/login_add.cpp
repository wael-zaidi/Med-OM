#include "login_add.h"
#include "ui_login_add.h"

login_add::login_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_add)
{
    ui->setupUi(this);
}

login_add::~login_add()
{
    delete ui;
}
