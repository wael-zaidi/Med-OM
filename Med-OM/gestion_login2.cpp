#include "gestion_login2.h"
#include "ui_gestion_login2.h"
#include "login_ajouter.h"
#include "ui_login_ajouter.h"
#include "login_modifier.h"
#include "ui_login_modifier.h"
#include"login_historique.h"


gestion_login2::gestion_login2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_login2)
{
    ui->setupUi(this);
}

gestion_login2::~gestion_login2()
{
    delete ui;
}

void gestion_login2::on_btn_add_login_pressed()
{
    ui->btn_add_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 24pt Bahnschrift;");

}

void gestion_login2::on_btn_add_login_released()
{
    ui->btn_add_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 24pt Bahnschrift; ");


    login_ajouter login_ajouter;
    login_ajouter.setModal(true);
    login_ajouter.exec();
}

void gestion_login2::on_btn_edit_login_pressed()
{
     ui->btn_edit_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 24pt Bahnschrift;");


}



void gestion_login2::on_btn_edit_login_released()
{
    ui->btn_edit_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 24pt Bahnschrift; ");

    login_modifier login_modifier;
    login_modifier.setModal(true);
    login_modifier.exec();
}

/*void gestion_login2::on_btn_edit_login_2_pressed()
{
     ui->btn_edit_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 24pt Bahnschrift;");
}*/

/*void gestion_login2::on_btn_edit_login_2_released()
{
    login_historique login_historique;
    login_historique.setModal(true);
    login_historique.exec();
}*/

void gestion_login2::on_btn_historique_login_pressed()
{
    ui->btn_historique_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 24pt Bahnschrift;");

}

void gestion_login2::on_btn_historique_login_released()
{
    ui->btn_historique_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 24pt Bahnschrift; ");

    login_historique login_historique;
    login_historique.setModal(true);
    login_historique.exec();
}
