#include "login.h"
#include "ui_login.h"
#include "dashboard.h"
#include "connection_med_om.h"
#include"dashboard.h"
#include"ui_dashboard.h"
#include <QApplication>
#include <QMessageBox>
#include<QPixmap>
#include<QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include<QTime>
#include<QDate>
#include"arduino.h"


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)

{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
 /*
    // insere image background
    QPixmap pix(":/img/login/img/login/background.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    // insere logo
    QPixmap pix2(":/img/login/img/login/logologin.png");
    int w2 = ui->logo_login->width();
    int h2 = ui->logo_login->height();
    ui->logo_login->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
*/
    QString text = QTime::currentTime().toString();
    ui->timeanddate->setText(text);

}



Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{

}

void Login::on_login_pressed()
{

    ui->login->setStyleSheet("border-image: url(:/img/login/img/login/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");

}

void set_system_date()
{

}

void Login::on_login_released()
{
    Login w;
    QSqlQuery qry;
    QString id,password;
   // QTime time;
    QString date;
    id=ui->text_id->text();
    password=ui->text_password->text();

    ui->login->setStyleSheet("border-image: url(:/img/login/img/login/button_init.png)3 10 3 10; font: 24pt Bahnschrift; ");

    if( ui->text_id->text().isEmpty() || ui->text_password->text().isEmpty() )
    {
       // w.show();
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);

    }
    else
    {
        qry.prepare("select * from LOGIN where LOGIN='"+id+"' and PASSWORD='"+password+"' "); //and PASSWORD='"+password+"'"
        if(qry.exec())
        {
            int count=0;
            while(qry.next())
            {
                count++;
            }
            if (count==1)
            {


            // ajout de l'action au tab historique login
                QSqlQuery qry_hist;
                QString time = QTime::currentTime().toString();
                int date_day = QDate::currentDate().day();
                int date_mounth = QDate::currentDate().month();
                int date_year = QDate::currentDate().year();
                QString date = QString::number(date_day) +"/"+ QString::number(date_mounth)+"/"+QString::number(date_year);

                QString action = "login";

               qry_hist.prepare("insert into LOGIN_HISTORIQUE (LOGIN,DATE_LOGIN,HEURE_LOGIN,ACTION) values ('"+id+"','"+date+"','"+time+"','"+action+"')");
              if (qry_hist.exec())
              {

                dashboard dashboard;
                dashboard.temp_login(ui->text_id->text());
                ui->text_id->setText("");
                ui->text_password->setText("");
                A.write_to_arduino("1");
                dashboard.setModal(true);
                dashboard.exec();
                 A.write_to_arduino("0");
              }
              else
          {
            QMessageBox::critical(this,tr("SAVE"),qry_hist.lastError().text());
              }
            }
            if(count<1)
            {
                 A.write_to_arduino("1");
                  A.write_to_arduino("0");
                   A.write_to_arduino("1");
                    A.write_to_arduino("0");
                QMessageBox::critical(nullptr, QObject::tr("Attention"),
                            QObject::tr("Veuillez verifier votre login et mot de passe.\n"), QMessageBox::Ok);
            }
        }



    }



}

void Login::on_show_password_pressed()
{
    ui->text_password->setEchoMode(QLineEdit::Normal);
}

void Login::on_show_password_released()
{
   ui->text_password->setEchoMode(QLineEdit::Password);
}
