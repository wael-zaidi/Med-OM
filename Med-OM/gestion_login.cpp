#include "gestion_login.h"
#include "ui_gestion_login.h"

gestion_login::gestion_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_login)
{
    ui->setupUi(this);
}

gestion_login::~gestion_login()
{
    delete ui;
}
