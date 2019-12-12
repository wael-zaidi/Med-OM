#include "dashboard.h"
#include "ui_dashboard.h"
#include"gestion_login2.h"
#include"ui_gestion_login2.h"
#include"login_add.h"
#include"ui_login_add.h"
#include "connection_med_om.h"
#include"arduino.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QCloseEvent>
#include<QMessageBox>
#include<QTime>
#include<QDate>

#include<QPixmap>

dashboard::dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
  //  ui->login_active->setText("temp_login");




}

dashboard::~dashboard()
{
    delete ui;
}




void dashboard::closeEvent(QCloseEvent *event)
{

    QSqlQuery qry_hist;
    QString time = QTime::currentTime().toString();
    int date_day = QDate::currentDate().day();
    int date_mounth = QDate::currentDate().month();
    int date_year = QDate::currentDate().year();
    QString date = QString::number(date_day) +"/"+ QString::number(date_mounth)+"/"+QString::number(date_year);
    QString action = "logout";
     QString id=ui->login_active->text();

    /*
    QMessageBox::StandardButton dialog;
    dialog = QMessageBox::warning(this, "Veuillez se déconnecter ? ",
    "Veuillez se déconnecter ?",
    QMessageBox::Ok | QMessageBox::Cancel);
    if( dialog == QMessageBox::Ok) {

    close();
    } else {
    event->ignore();
    } */




   qry_hist.prepare("insert into LOGIN_HISTORIQUE (LOGIN,DATE_LOGIN,HEURE_LOGIN,ACTION) values ('"+id+"','"+date+"','"+time+"','"+action+"')");
    qry_hist.exec();
}


void dashboard::temp_login(QString n)
{
    ui->login_active->setText(n);
}

void dashboard::on_btn_gestion_patient_pressed()
{
    ui->btn_gestion_patient->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 24pt Bahnschrift;");

}

void dashboard::on_btn_gestion_patient_released()
{
    ui->btn_gestion_patient->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 24pt Bahnschrift; ");

}



void dashboard::on_btn_gestion_login_pressed()
{

     ui->btn_gestion_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 24pt Bahnschrift;");


}

void dashboard::on_btn_gestion_login_released()
{
    ui->btn_gestion_login->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 24pt Bahnschrift; ");

    gestion_login2 gestion_login2;
    gestion_login2.setModal(true);
    gestion_login2.exec();
}
