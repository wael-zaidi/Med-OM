#include "login_ajouter.h"
#include "ui_login_ajouter.h"
#include <QMessageBox>
#include<QPixmap>
#include<QString>
#include <QSqlDatabase>
#include "connection_med_om.h"



login_ajouter::login_ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_ajouter)
{
    ui->setupUi(this);
    id="";
    password="";
    autorisation="";
    etat="";

}

login_ajouter::~login_ajouter()
{
    delete ui;
}




void login_ajouter::login_set_labels()
{

    this->id=ui->text_id->text();
    this->password=ui->text_password->text();
    this->autorisation=ui->text_autorisation->text();
    this->etat=ui->text_etat->text();

}

void login_ajouter::login_qry_ajouter()
{

    QSqlQuery qry;
    qry.prepare("insert into LOGIN (LOGIN,PASSWORD,AUTORISATION,ETAT) values ('"+id+"','"+password+"','"+autorisation+"','"+etat+"')");

       if (qry.exec())
   {

         QMessageBox::information(this,tr("Ajout Login"),tr("Le nouveau Login est ajouté avec success"));

         // reinitialiser tt les champs a vide
         ui->text_id->setText("");
         ui->text_password->setText("");
         ui->text_etat->setText("");
         ui->text_autorisation->setText("");

         ui->radio_admin->setAutoExclusive(false);
         ui->radio_docteur->setAutoExclusive(false);
         ui->radio_secretaire->setAutoExclusive(false);
         ui->radio_actif->setAutoExclusive(false);
         ui->radio_suspendu->setAutoExclusive(false);

         ui->radio_actif->setChecked(false);
         ui->radio_admin->setChecked(false);
         ui->radio_docteur->setChecked(false);
         ui->radio_suspendu->setChecked(false);
         ui->radio_secretaire->setChecked(false);

         ui->radio_admin->setAutoExclusive(true);
         ui->radio_docteur->setAutoExclusive(true);
         ui->radio_secretaire->setAutoExclusive(true);
         ui->radio_actif->setAutoExclusive(true);
         ui->radio_suspendu->setAutoExclusive(true);

      }
       else
   {
     QMessageBox::critical(this,tr("SAVE"),qry.lastError().text());
       }

}







void login_ajouter::on_btn_ajouter_pressed()
{
     ui->btn_ajouter->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 22pt Bahnschrift;");

    if( ui->text_id->text().isEmpty() || ui->text_password->text().isEmpty() || ui->text_autorisation->text().isEmpty() || ui->text_etat->text().isEmpty() )
    {
       // w.show();
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }

    else {
            login_set_labels();
            login_qry_ajouter();
          }




}

void login_ajouter::on_btn_ajouter_released()
{
    ui->btn_ajouter->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 22pt Bahnschrift; ");
}

void login_ajouter::on_radio_admin_clicked()
{
    ui->text_autorisation->setText("admin");
}

void login_ajouter::on_radio_docteur_clicked()
{
    ui->text_autorisation->setText("docteur");
}

void login_ajouter::on_radio_secretaire_clicked()
{
    ui->text_autorisation->setText("secretaire");
}

void login_ajouter::on_radio_actif_clicked()
{
    ui->text_etat->setText("actif");
}

void login_ajouter::on_radio_suspendu_clicked()
{
    ui->text_etat->setText("suspendu");

}


