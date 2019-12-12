#include "login_modifier.h"
#include "ui_login_modifier.h"
#include <QMessageBox>
#include<QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "connection_med_om.h"
#include "login_ajouter.h"


login_modifier::login_modifier(QWidget *parent) :

    QDialog(parent),

    ui(new Ui::login_modifier)
{
    ui->setupUi(this);


    login_modifier_afficher_tab();

}

login_modifier::~login_modifier()
{
    delete ui;
}

void login_modifier::login_modifier_afficher_tab()
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    qry->prepare("select * from LOGIN");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}
void login_modifier::on_btn_load_table_clicked()
{
    //connection_MED_OM c;
    //c.createconnect();
  //  qDebug() <<(modal->rowCount());

}

void login_modifier::login_modifier_qry()
{
   // login_ajouter login_ajouter;
    QSqlQuery qry;
    QString id_temp;
    id_temp=ui->text_temp_id->text();

    qry.prepare("update LOGIN set LOGIN='"+login_ajouter.id+"',PASSWORD='"+login_ajouter.password+"',AUTORISATION='"+login_ajouter.autorisation+"', ETAT='"+login_ajouter.etat+"' where LOGIN='"+id_temp+"' ");

       if (qry.exec())
   {
         QMessageBox::information(this,tr("Modifier Login"),tr("Ce Login est modifié avec success"));
         ui->text_id->setText("");
         ui->text_password->setText("");
         ui->text_etat->setText("");
         ui->text_autorisation->setText("");
         ui->text_temp_id->setText("");

      }
       else
   {
     QMessageBox::critical(this,tr("Modifier"),qry.lastError().text());
       }
}


void login_modifier::login_modifier_update()
{

    login_ajouter.id=ui->text_id->text();
    login_ajouter.password=ui->text_password->text();
    login_ajouter.autorisation=ui->text_autorisation->text();
    login_ajouter.etat=ui->text_etat->text();


}


void login_modifier::on_tableView_activated(const QModelIndex &index)
{


}

void login_modifier::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("select * from LOGIN where LOGIN='"+val+"' or PASSWORD='"+val+"' or AUTORISATION='"+val+"' or ETAT='"+val+"' " );

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->text_id->setText(qry.value(0).toString());
            ui->text_temp_id->setText(qry.value(0).toString());
            ui->text_password->setText(qry.value(1).toString());
            ui->text_autorisation->setText(qry.value(2).toString());
            ui->text_etat->setText(qry.value(3).toString());

        }
    }
    else {
        QMessageBox::critical(this,tr("ERROR"),qry.lastError().text());
    }

}

void login_modifier::on_btn_valider_pressed()
{


}

void login_modifier::on_btn_supprimer_pressed()
{
   ui->btn_supprimer->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient2.png)3 10 15 10; font: 18pt Bahnschrift;");


}



void login_modifier::on_text_autorisation_textChanged(const QString &arg1)
{
    if(arg1=="admin")
    {
       ui->radio_admin->setChecked(true);
    }
    if(arg1=="docteur")
    {
       ui->radio_docteur->setChecked(true);
    }
    if(arg1=="secretaire")
    {
       ui->radio_secretaire->setChecked(true);
    }

    if(arg1=="")
    {

       ui->radio_admin->setAutoExclusive(false);
       ui->radio_docteur->setAutoExclusive(false);
       ui->radio_secretaire->setAutoExclusive(false);

       ui->radio_admin->setChecked(false);
       ui->radio_docteur->setChecked(false);
       ui->radio_secretaire->setChecked(false);

       ui->radio_admin->setAutoExclusive(true);
       ui->radio_docteur->setAutoExclusive(true);
       ui->radio_secretaire->setAutoExclusive(true);

    }
}

void login_modifier::on_text_etat_textChanged(const QString &arg1)
{
    if(arg1=="actif")
    {
       ui->radio_actif->setChecked(true);
    }

    if(arg1=="suspendu")
    {
       ui->radio_suspendu->setChecked(true);
    }

    if(arg1=="")
    {
       ui->radio_actif->setAutoExclusive(false);
       ui->radio_suspendu->setAutoExclusive(false);

       ui->radio_actif->setChecked(false);
       ui->radio_suspendu->setChecked(false);

       ui->radio_actif->setAutoExclusive(true);
       ui->radio_suspendu->setAutoExclusive(true);
    }
}

void login_modifier::on_btn_valider_released()
{
    ui->btn_valider->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 22pt Bahnschrift;");


   // QString val=ui->tableView->model()->data(index).toString();

  /* QString id,id_temp,password,autorisation,etat;
   id=ui->text_id->text();
   id_temp=ui->text_temp_id->text();
   password=ui->text_password->text();
   autorisation=ui->text_autorisation->text();
   etat=ui->text_etat->text();
*/
 //  login_modifier_update();

   if( ui->text_id->text().isEmpty() || ui->text_password->text().isEmpty() || ui->text_autorisation->text().isEmpty() || ui->text_etat->text().isEmpty() )
   {
      // w.show();
           QMessageBox::warning(nullptr, QObject::tr("Attention"),
                       QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
   }
   else {
          // connection_MED_OM c;
           // c.createconnect();
       login_modifier_update();
       login_modifier_qry();

    }

       // mise a jour de l'affichage de tableau

  login_modifier_afficher_tab();

}

void login_modifier::on_btn_supprimer_released()
{
    ui->btn_supprimer->setStyleSheet("border-image: url(:/img/dashboard/btn_gestion_patient1.png)3 10 15 10; font: 18pt Bahnschrift;");

    QString id_temp;
    id_temp=ui->text_temp_id->text();

    QSqlQuery qry;
    qry.prepare("Delete from LOGIN where LOGIN='"+id_temp+"'");


       if (qry.exec())
   {
         QMessageBox::information(this,tr("Supprimer Login"),tr("Ce Login est supprimé avec success"));
         ui->radio_admin->setAutoExclusive(false);
         ui->radio_docteur->setAutoExclusive(false);
         ui->radio_secretaire->setAutoExclusive(false);

         ui->radio_admin->setChecked(false);
         ui->radio_docteur->setChecked(false);
         ui->radio_secretaire->setChecked(false);

         ui->radio_admin->setAutoExclusive(true);
         ui->radio_docteur->setAutoExclusive(true);
         ui->radio_secretaire->setAutoExclusive(true);
         ui->radio_actif->setAutoExclusive(false);
         ui->radio_suspendu->setAutoExclusive(false);

         ui->radio_actif->setChecked(false);
         ui->radio_suspendu->setChecked(false);

         ui->radio_actif->setAutoExclusive(true);
         ui->radio_suspendu->setAutoExclusive(true);
         ui->text_id->setText("");
         ui->text_temp_id->setText("");
         ui->text_password->setText("");
         ui->text_etat->setText("");
         ui->text_autorisation->setText("");

      }
       else
   {
     QMessageBox::critical(this,tr("Supprimer"),qry.lastError().text());
       }

       // mise a jour de l'affichage de tableau

       QSqlQueryModel * modal= new QSqlQueryModel ();
       QSqlQuery*qry2=new QSqlQuery();

       qry2->prepare("select * from LOGIN");
       qry2->exec();
       modal->setQuery(*qry2);
       ui->tableView->setModel(modal);
}
