#include "gestion_patient.h"
#include "ui_gestion_patient.h"
#include "qsound.h"
#include "patient.h"
#include "chambre.h"
#include "qmessagebox.h"
gestion_patient::gestion_patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_patient)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/Ressource/blue.jpeg"));

    QPixmap pix(":/Ressource/Background_color.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));

    QPixmap pix1(":/Ressource/icon_add.png");
    int w1 = ui->label_2->width();
    int h1 = ui->label_2->height();
    ui->label_2->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));

    QPixmap pix2(":/Ressource/checked.png");
    int w2 = ui->label_10->width();
    int h2 = ui->label_10->height();
    ui->label_10->setPixmap(pix2.scaled(w2,h2,Qt::IgnoreAspectRatio));

    QPixmap pix4(":/Ressource/Asset 2.png");
    int w4 = ui->label_9->width();
    int h4 = ui->label_9->height();
    ui->label_9->setPixmap(pix4.scaled(w4,h4,Qt::IgnoreAspectRatio));

    QPixmap pix3(":/Ressource/cancel.png");
    int w3 = ui->label_11->width();
    int h3 = ui->label_11->height();
    ui->label_11->setPixmap(pix3.scaled(w3,h3,Qt::IgnoreAspectRatio));

    QPixmap pix5(":/Ressource/Asset 3.png");
    int w5 = ui->label_12->width();
    int h5 = ui->label_12->height();
    ui->label_12->setPixmap(pix5.scaled(w5,h5,Qt::IgnoreAspectRatio));

    QPixmap pix6(":/Ressource/Asset 4.png");
    int w6 = ui->label_13->width();
    int h6 = ui->label_13->height();
    ui->label_13->setPixmap(pix6.scaled(w6,h6,Qt::IgnoreAspectRatio));

    QPixmap pix7(":/Ressource/icon_edit.png");
    int w7 = ui->label_44->width();
    int h7 = ui->label_44->height();
    ui->label_44->setPixmap(pix7.scaled(w7,h7,Qt::IgnoreAspectRatio));

    QPixmap pix8(":/Ressource/checked.png");
    int w8 = ui->label_43->width();
    int h8 = ui->label_43->height();
    ui->label_43->setPixmap(pix8.scaled(w8,h8,Qt::IgnoreAspectRatio));

    QPixmap pix9(":/Ressource/cancel.png");
    int w9 = ui->label_45->width();
    int h9 = ui->label_45->height();
    ui->label_45->setPixmap(pix9.scaled(w9,h9,Qt::IgnoreAspectRatio));

    QPixmap pix10(":/Ressource/Asset 2.png");
    int w10 = ui->label_46->width();
    int h10 = ui->label_46->height();
    ui->label_46->setPixmap(pix10.scaled(w10,h10,Qt::IgnoreAspectRatio));

    QPixmap pix11(":/Ressource/Background_color.png");
    int w11 = ui->label_47->width();
    int h11 = ui->label_47->height();
    ui->label_47->setPixmap(pix11.scaled(w11,h11,Qt::IgnoreAspectRatio));

    QPixmap pix12(":/Ressource/job.png");
    int w12 = ui->label_56->width();
    int h12 = ui->label_56->height();
    ui->label_56->setPixmap(pix12.scaled(w12,h12,Qt::IgnoreAspectRatio));

    QPixmap pix13(":/Ressource/dashboard.jpg");
    int w13 = ui->label_58->width();
    int h13 = ui->label_58->height();
    ui->label_58->setPixmap(pix13.scaled(w13,h13,Qt::IgnoreAspectRatio));

    QPixmap pix14(":/Ressource/checked.png");
    int w14 = ui->label_57->width();
    int h14 = ui->label_57->height();
    ui->label_57->setPixmap(pix14.scaled(w14,h14,Qt::IgnoreAspectRatio));

    QPixmap pix15(":/Ressource/Background_color.png");
    int w15 = ui->label_59->width();
    int h15 = ui->label_59->height();
    ui->label_59->setPixmap(pix15.scaled(w15,h15,Qt::IgnoreAspectRatio));

    QPixmap pix16(":/Ressource/prescription.png");
    int w16 = ui->label_60->width();
    int h16 = ui->label_60->height();
    ui->label_60->setPixmap(pix16.scaled(w16,h16,Qt::IgnoreAspectRatio));

    QPixmap pix17(":/Ressource/prescription.png");
    int w17 = ui->label_61->width();
    int h17 = ui->label_61->height();
    ui->label_61->setPixmap(pix17.scaled(w17,h17,Qt::IgnoreAspectRatio));

    QPixmap pix18(":/Ressource/Background_color.png");
    int w18 = ui->label_15->width();
    int h18 = ui->label_15->height();
    ui->label_15->setPixmap(pix18.scaled(w18,h18,Qt::IgnoreAspectRatio));

    QPixmap pix19(":/Ressource/dashboard.jpg");
    int w19 = ui->label_115->width();
    int h19 = ui->label_115->height();
    ui->label_115->setPixmap(pix19.scaled(w19,h19,Qt::IgnoreAspectRatio));

    QPixmap pix20(":/Ressource/icon_add.png");
    int w20 = ui->label_110->width();
    int h20 = ui->label_110->height();
    ui->label_110->setPixmap(pix20.scaled(w20,h20,Qt::IgnoreAspectRatio));

    QPixmap pix21(":/Ressource/checked.png");
    int w21 = ui->label_113->width();
    int h21 = ui->label_113->height();
    ui->label_113->setPixmap(pix21.scaled(w21,h21,Qt::IgnoreAspectRatio));

    QPixmap pix22(":/Ressource/cancel.png");
    int w22 = ui->label_114->width();
    int h22 = ui->label_114->height();
    ui->label_114->setPixmap(pix22.scaled(w22,h22,Qt::IgnoreAspectRatio));

    QPixmap pix23(":/Ressource/icon_edit.png");
    int w23 = ui->label_117->width();
    int h23 = ui->label_117->height();
    ui->label_117->setPixmap(pix23.scaled(w23,h23,Qt::IgnoreAspectRatio));

    QPixmap pix24(":/Ressource/checked.png");
    int w24 = ui->label_119->width();
    int h24 = ui->label_119->height();
    ui->label_119->setPixmap(pix24.scaled(w24,h24,Qt::IgnoreAspectRatio));

    QPixmap pix25(":/Ressource/cancel.png");
    int w25 = ui->label_118->width();
    int h25 = ui->label_118->height();
    ui->label_118->setPixmap(pix25.scaled(w25,h25,Qt::IgnoreAspectRatio));

    QPixmap pix26(":/Ressource/dashboard.jpg");
    int w26 = ui->label_121->width();
    int h26 = ui->label_121->height();
    ui->label_121->setPixmap(pix26.scaled(w26,h26,Qt::IgnoreAspectRatio));

    QPixmap pix27(":/Ressource/job.png");
    int w27 = ui->label_63->width();
    int h27 = ui->label_63->height();
    ui->label_63->setPixmap(pix27.scaled(w27,h27,Qt::IgnoreAspectRatio));

    QPixmap pix28(":/Ressource/dashboard.jpg");
    int w28 = ui->label_16->width();
    int h28 = ui->label_16->height();
    ui->label_16->setPixmap(pix28.scaled(w28,h28,Qt::IgnoreAspectRatio));

    QPixmap pix29(":/Ressource/checked.png");
    int w29 = ui->label_64->width();
    int h29 = ui->label_64->height();
    ui->label_64->setPixmap(pix29.scaled(w29,h29,Qt::IgnoreAspectRatio));

    QPixmap pix30(":/Ressource/prescription.png");
    int w30 = ui->label_66->width();
    int h30 = ui->label_66->height();
    ui->label_66->setPixmap(pix30.scaled(w30,h30,Qt::IgnoreAspectRatio));

    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_3->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_4->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_10->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_11->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_12->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_13->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_14->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_15->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_16->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");

    ui->pushButton_34->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_35->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_36->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_39->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_38->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_37->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_17->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    ui->pushButton_18->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");

    ui->pushButton_19->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");

    ui->pushButton_5->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

    QSound::play(":/Ressource/Apocalyptica_-_The Unforgiven.wav");

    ui->lineEdit->setText(QTime::currentTime().toString());

    ui->lineEdit_2->setText(QTime::currentTime().toString());

    ui->lineEdit_3->setText(QTime::currentTime().toString());

    ui->lineEdit_4->setText(QTime::currentTime().toString());

    ui->lineEdit_5->setText(QTime::currentTime().toString());

    ui->lineEdit->setStyleSheet(("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;"));

    ui->lineEdit_2->setStyleSheet(("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;"));

    ui->lineEdit_3->setStyleSheet(("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;"));

    ui->lineEdit_4->setStyleSheet(("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;"));

    ui->lineEdit_4->setStyleSheet(("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;"));

    ui->lineEdit_5->setStyleSheet(("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;"));
}

gestion_patient::~gestion_patient()
{
    delete ui;
}



void gestion_patient::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 19pt Bahnschrift;");

}

void gestion_patient::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");
    QString nom, prenom, adresse, lieu, sexe, email;
    int code = 0, cin = 0;
    QDate date;
    nom = ui->nomEdit->text();
    prenom = ui->prenomEdit->text();
    adresse = ui->adresseEdit->text();
    lieu = ui->LieuEdit->text();
    sexe = ui->SexeEdit->text();
    email = ui->EmailEdit->text();
    date = ui->dateEdit->date();
    code = ui->CodeEdit->text().toInt();
    cin = ui->CINEdit->text().toInt();

    Patient p(code, cin, date, nom, prenom, adresse, lieu, sexe, email);
    if (p.ajouterPatient())
    {
        QMessageBox::information(this, tr("Ajout Patient"), tr("Le nouveau Patient est ajouté avec success"));
    }
    else
    {
        QMessageBox::critical(this, tr("SAVE"), tr("Error"));
    }
}


void gestion_patient::on_pushButton_3_pressed()
{
    ui->pushButton_3->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 10pt Bahnschrift;");

}

void gestion_patient::on_pushButton_3_released()
{
    QDate d1(1998,01,01);
    ui->pushButton_3->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
    ui->nomEdit->setText("");
    ui->prenomEdit->setText("");
    ui->LieuEdit->setText("");
    ui->SexeEdit->setText("");
    ui->adresseEdit->setText("");
    ui->CodeEdit->setText("");
    ui->CINEdit->setText("");
    ui->dateEdit->setDate(d1);
}


void gestion_patient::on_pushButton_5_pressed()
{
    ui->pushButton_5->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 10pt Bahnschrift;");

}

void gestion_patient::on_pushButton_5_released()
{
    ui->pushButton_5->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
    gestion_patient::close();
}

void gestion_patient::on_pushButton_14_pressed()
{
    ui->pushButton_14->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 10pt Bahnschrift;");

}

bool gestion_patient::on_pushButton_14_released()
{
    ui->pushButton_14->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
    QSqlQuery query;
    int cod = ui->CodeEdit_4->text().toInt();
    QString res = QString::number(cod);
    query.prepare("SELECT * FROM TABLE_PATIENT_FINAL WHERE CODE = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Patient"), tr("Le Patient est trouvé avec success, Veuillez entrer les nouvelles informations."));
        ui->nomEdit_4->setText(query.value(0).toString());
        ui->CodeEdit_4->setText(query.value(1).toString());
        ui->adresseEdit_4->setText(query.value(2).toString());
        ui->prenomEdit_4->setText(query.value(3).toString());
        ui->SexeEdit_4->setText(query.value(4).toString());
        ui->CINEdit_4->setText(query.value(5).toString());
        ui->dateEdit_4->setDate(query.value(6).toDate());
        ui->LieuEdit_4->setText(query.value(7).toString());
        ui->EmailEdit_4->setText(query.value(8).toString());
        return true;
    }
    else
    {
        QMessageBox::critical(this, tr("SAVE"), tr("Le patient n'est pas trouvé, Veuillez entrer un code deja existant."));
        return false;
    }
}

void gestion_patient::on_pushButton_12_pressed()
{
    ui->pushButton_12->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 19pt Bahnschrift;");

}

void gestion_patient::on_pushButton_12_released()
{
    QString nom, prenom, adresse, lieu, sexe, email;
    int code = 0, cin = 0;
    QDate date;
    QSqlQuery query;
    ui->pushButton_12->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");
    int cod = ui->CodeEdit_4->text().toInt();
    QString res = QString::number(cod);
    nom = ui->nomEdit_4->text();
    prenom = ui->prenomEdit_4->text();
    adresse = ui->adresseEdit_4->text();
    lieu = ui->LieuEdit_4->text();
    sexe = ui->SexeEdit_4->text();
    date = ui->dateEdit_4->date();
    email = ui->EmailEdit_4->text();
    code = ui->CodeEdit_4->text().toInt();
    cin = ui->CINEdit_4->text().toInt();
    Patient p(code, cin, date, nom, prenom, adresse, lieu, sexe, email);
    if(p.modifierPatient(cod))
    {
        QMessageBox::information(this, tr("Modifier Patient"), tr("Le Patient a été modifié avec success."));
    }
}

void gestion_patient::on_radioMale_clicked()
{
    ui->SexeEdit->setText("Male");

}

void gestion_patient::on_radioFemelle_clicked()
{
    ui->SexeEdit->setText("Femelle");
}

void gestion_patient::on_pushButton_10_pressed()
{
    ui->pushButton_10->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 10pt Bahnschrift;");

}

void gestion_patient::on_pushButton_10_released()
{
    QDate d1(1998,01,01);
    ui->pushButton_10->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
    ui->nomEdit_4->setText("");
    ui->prenomEdit_4->setText("");
    ui->LieuEdit_4->setText("");
    ui->SexeEdit_4->setText("");
    ui->adresseEdit_4->setText("");
    ui->CodeEdit_4->setText("");
    ui->CINEdit_4->setText("");
    ui->EmailEdit_4->setText("");
    ui->dateEdit_4->setDate(d1);
}

void gestion_patient::on_pushButton_13_pressed()
{
    ui->pushButton_13->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 19pt Bahnschrift;");

}

void gestion_patient::on_pushButton_13_released()
{
    QSqlQuery query;
    Patient p;
    int cod = ui->CodeEdit_5->text().toInt();
    QString res = QString::number(cod);
    ui->pushButton_13->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");
    if (ui->CodeEdit_5->text() == "")
    {
        QMessageBox::critical(this, tr("Supprimer Patient"), tr("Veuillez entrer le code du patient à supprimer."));

    }
    query.prepare("SELECT * FROM TABLE_PATIENT_FINAL WHERE CODE = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        p.supprimerPatient(cod);
        QMessageBox::information(this, tr("Supprimer Patient"), tr("Le Patient a été supprimé avec success."));
        QMessageBox::information(this, tr("Supprimer Patient"), tr("Merci Pour Votre Visite!"));

    }
    else {
        QMessageBox::critical(this, tr("Supprimer Patient"), tr("Veuillez entrer un code de patient déja éxistant."));
    }
}

void gestion_patient::on_pushButton_16_pressed()
{
    ui->pushButton_16->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 12pt Bahnschrift;");

}

void gestion_patient::on_pushButton_16_released()
{
    ui->pushButton_16->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
    QSqlQuery query;
    Patient p;
    QSqlQueryModel * modal = p.afficherPatient();
    ui->tableView_2->setModel(modal);
    ui->tableView_2->show();
}

void gestion_patient::on_pushButton_15_pressed()
{
    ui->pushButton_15->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 19pt Bahnschrift;");

}

void gestion_patient::on_pushButton_15_released()
{
    QSqlQuery query;
    Patient p;
    ui->pushButton_15->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");
    QSqlQueryModel * modal = p.afficherPatient();
    ui->tableView->setModel(modal);
    ui->tableView->show();
}

void gestion_patient::on_pushButton_4_pressed()
{
    ui->pushButton_4->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 10pt Bahnschrift;");
}

void gestion_patient::on_pushButton_4_released()
{
    ui->pushButton_4->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_PATIENT_FINAL ORDER BY code ASC");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("Sexe"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Vertical, QObject::tr("Date_De_Naissance"));
    model->setHeaderData(6, Qt::Vertical, QObject::tr("Lieu"));
    model->setHeaderData(7, Qt::Vertical, QObject::tr("Adresse"));
    model->setHeaderData(8, Qt::Vertical, QObject::tr("Email"));
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void gestion_patient::on_pushButton_17_pressed()
{
    ui->pushButton_17->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 10pt Bahnschrift;");

}

bool gestion_patient::on_pushButton_17_released()
{
    ui->pushButton_17->setStyleSheet("border-image: url(!/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
    QSqlQuery query;
    int idd = ui->idEdit_10->text().toInt();
    QString res = QString::number(idd);
    query.prepare("SELECT * FROM TABLE_CHAMBRE WHERE IDENTIFIANT = :idd");
    query.bindValue(":idd", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Chambre"), tr("La chambre est trouvée avec success, Veuillez entrer les nouvelles informations."));
        ui->prenomEdit_9->setText(query.value(0).toString());
        ui->nomEdit_9->setText(query.value(1).toString());
        ui->idEdit_9->setText(query.value(2).toString());
        return true;
    }
    else
    {
        QMessageBox::critical(this, tr("SAVE"), tr("La chambre n'est pas trouvé, Veuillez entrer un identifiant deja existant."));
        return false;
    }

}

void gestion_patient::on_pushButton_38_pressed()
{
    ui->pushButton_38->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 19pt Bahnschrift;");

}

void gestion_patient::on_pushButton_38_released()
{
    ui->pushButton_38->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");
    QString nom, prenom;
    int identifiant = 0;
    QSqlQuery query;
    int idd = ui->idEdit_10->text().toInt();
    nom = ui->nomEdit_9->text();
    prenom = ui->prenomEdit_9->text();
    identifiant = ui->idEdit_9->text().toInt();
    Chambre c(nom, prenom, identifiant);
    if(c.modifierChambre(idd))
    {
        QMessageBox::information(this, tr("Modifier Patient"), tr("Le Patient a été modifié avec success."));
    }
    else {
        QMessageBox::information(this, tr("Modifier Patient"), tr("ERROR"));
    }
}

void gestion_patient::on_pushButton_37_pressed()
{
    ui->pushButton_17->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 10pt Bahnschrift;");

}

void gestion_patient::on_pushButton_37_released()
{
    ui->pushButton_17->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");

}

void gestion_patient::on_pushButton_18_pressed()
{
    ui->pushButton_18->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 19pt Bahnschrift;");

}

void gestion_patient::on_pushButton_18_released()
{
    ui->pushButton_18->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 19pt Bahnschrift;");
    QSqlQuery query;
    Chambre c;
    int idd = ui->IdEdit_6->text().toInt();
    QString res = QString::number(idd);
    if (ui->IdEdit_6->text() == "")
    {
        QMessageBox::critical(this, tr("Supprimer Chambre"), tr("Veuillez entrer l identifiant de la chambre à supprimer."));
    }
    query.prepare("SELECT * FROM TABLE_CHAMBRE WHERE IDENTIFIANT = :idd");
    query.bindValue(":idd", res);
    query.exec();
    if(query.first())
    {
        c.supprimerChambre(idd);
        QMessageBox::information(this, tr("Supprimer Chambre"), tr("La chambre a été supprimé avec success."));
        QMessageBox::information(this, tr("Supprimer Chambre"), tr("Merci Pour Votre Visite!"));

    }
    else {
        QMessageBox::critical(this, tr("Supprimer Chambre"), tr("Veuillez entrer un identifiant valide."));
    }
}

void gestion_patient::on_pushButton_19_pressed()
{
    ui->pushButton_19->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 12pt Bahnschrift;");

}

void gestion_patient::on_pushButton_19_released()
{
    ui->pushButton_19->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
    QSqlQuery query;
    Chambre c;
    QSqlQueryModel * modal = c.afficherChambre();
    ui->tableView_3->setModel(modal);
    ui->tableView_3->show();
}

void gestion_patient::on_pushButton_35_pressed()
{
    ui->pushButton_35->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
}

void gestion_patient::on_pushButton_35_released()
{
    ui->pushButton_35->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    QString nom, prenom;
    int identifiant = 0;
    nom = ui->nomEdit_8->text();
    prenom = ui->prenomEdit_8->text();
    identifiant = ui->idEdit_8->text().toInt();
    Chambre c(nom, prenom, identifiant);
    if (c.ajouterChambre())
    {
        QMessageBox::information(this, tr("Ajout Chambre"), tr("La chambre a est ajouté avec success"));
    }
    else
    {
        QMessageBox::critical(this, tr("SAVE"), tr("Error"));
    }
}

void gestion_patient::on_pushButton_36_pressed()
{
    ui->pushButton_36->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");

}

void gestion_patient::on_pushButton_36_released()
{
    ui->pushButton_36->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->nomEdit_8->setText("");
    ui->prenomEdit_8->setText("");
    ui->idEdit_8->setText("");
}
