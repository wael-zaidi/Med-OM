#include "rendez_vous.h"
#include "ui_rendez_vous.h"
#include"QPixmap"
#include "rdv.h"
#include <QString>
#include <QMessageBox>
#include<QSqlQuery>
#include<QTimer>

//#include"ordonnance.h"
Rendez_Vous::Rendez_Vous(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rendez_Vous)
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






    ui->tableView->setModel(ajtmp.afficher());
    ui->tableView_2->setModel(ajt.afficher());
    ui->tableView->setModel(ajtmp.afficher_T());

    check_table();
    //QTimer::singleShot(2000, this, SLOT(rendez()));
    //A.close_arduino();



    QPixmap pix(":/Ressource/Background_color.png");
    int w = ui->fond->width();
    int h = ui->fond->height();
    ui->fond->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));

    QPixmap pix1(":/Ressource/Background_color.png");
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));

    QPixmap pixx(":/Ressource/Background_color.png");
    int wx = ui->label_3->width();
    int hx = ui->label_3->height();
    ui->label_3->setPixmap(pixx.scaled(wx,hx,Qt::IgnoreAspectRatio));

    QPixmap pix2(":/Ressource/checked.png");
    int w2 = ui->icon_valider->width();
    int h2 = ui->icon_valider->height();
    ui->icon_valider->setPixmap(pix2.scaled(w2,h2,Qt::IgnoreAspectRatio));

    QPixmap pix5(":/Ressource/checked.png");
    int w5 = ui->icon_valider_2->width();
    int h5 = ui->icon_valider_2->height();
    ui->icon_valider_2->setPixmap(pix5.scaled(w5,h5,Qt::IgnoreAspectRatio));

    QPixmap pix3(":/Ressource/cancel.png");
    int w3 = ui->icon_annuler->width();
    int h3 = ui->icon_annuler->height();
    ui->icon_annuler->setPixmap(pix3.scaled(w3,h3,Qt::IgnoreAspectRatio));

    QPixmap pix4(":/Ressource/cancel.png");
    int w4 = ui->icon_annuler_2->width();
    int h4 = ui->icon_annuler_2->height();
    ui->icon_annuler_2->setPixmap(pix4.scaled(w4,h4,Qt::IgnoreAspectRatio));

    QPixmap pix6(":/Ressource/cancel.png");
    int w6 = ui->label_5->width();
    int h6 = ui->label_5->height();
    ui->label_5->setPixmap(pix6.scaled(w6,h6,Qt::IgnoreAspectRatio));

    QPixmap pix7(":/Ressource/cancel.png");
    int w7 = ui->label_6->width();
    int h7 = ui->label_6->height();
    ui->label_6->setPixmap(pix7.scaled(w7,h7,Qt::IgnoreAspectRatio));

    QPixmap pix8(":/Ressource/Background_color.png");
    int w8 = ui->label_7->width();
    int h8 = ui->label_7->height();
    ui->label_7->setPixmap(pix8.scaled(w8,h8,Qt::IgnoreAspectRatio));

    QPixmap pix9(":/Ressource/Background_color.png");
    int w9 = ui->label_10->width();
    int h9 = ui->label_10->height();
    ui->label_10->setPixmap(pix9.scaled(w9,h9,Qt::IgnoreAspectRatio));

    QPixmap pix10(":/Ressource/Background_color.png");
    int w10 = ui->fond_2->width();
    int h10 = ui->fond_2->height();
    ui->fond_2->setPixmap(pix10.scaled(w10,h10,Qt::IgnoreAspectRatio));



    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
    ui->pb_supprimer->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->pushButton_3->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->pushButton_4->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
    ui->pb_supprimer_2->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");





}

Rendez_Vous::~Rendez_Vous()
{
    delete ui;
}

void Rendez_Vous::check_table()
{
    QSqlQuery qry;
    qry.prepare("select * from rendez_vous");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if (count==0)
        {
         //   A.connect_arduino();
            A.write_to_arduino("1");

          //  A.close_arduino();
        }
        }
}
void Rendez_Vous::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");

}

void Rendez_Vous::on_pushButton_released()
{
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int date=ui->le_date->text().toInt();
    int heure=ui->le_heure->text().toInt();
    int id=ui->le_id->text().toInt();
    rdv R(nom, prenom, date, heure, id);
    bool test=R.ajouter();
    ui->tableView->setModel(ajtmp.afficher());
    QMessageBox msgBox;
    if (test)
    {
        ui->tableView->setModel(ajtmp.afficher());
        ui->tableView->setModel(ajtmp.afficher_T());
        msgBox.setText("Ajout avec succés.");
        msgBox.exec();
    }

}

void Rendez_Vous::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
}

void Rendez_Vous::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");

}

void Rendez_Vous::on_pb_supprimer_pressed()
{
    ui->pb_supprimer->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");

}

void Rendez_Vous::on_pb_supprimer_released()
{
    ui->pb_supprimer->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=ajtmp.supprimer(id);
    if(test)
    {ui->tableView->setModel(ajtmp.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un rendez_vous"),
                    QObject::tr("Rendez_vous supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un rendez_vous"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Rendez_Vous::on_tabWidget_tabBarClicked(int index)
{
    A.close_arduino();
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    check_table();
}

void Rendez_Vous::on_tabWidget_currentChanged(int index)
{
    A.close_arduino();
}
