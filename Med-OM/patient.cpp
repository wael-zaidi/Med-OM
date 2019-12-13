#include "patient.h"
#include <iostream>
#include <QString>
using namespace std;
Patient::Patient()
{
    nom = "";
    prenom = "";
    adresse = "";
    lieu = "";
    sexe = "";
    code = 0;
    cin = 0;
    date = {0,0,0};
}

Patient::Patient(int code, int cin, QDate date, QString nom, QString prenom, QString adresse, QString lieu, QString sexe, QString email)
{
    this->code = code;
    this->cin = cin;
    this->date = date;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->lieu = lieu;
    this->sexe = sexe;
    this->email = email;
}

int Patient::get_code(){return  code;}
int Patient::get_cin(){return  cin;}
QDate Patient::get_Date(){return date;}
QString Patient::get_nom(){return  nom;}
QString Patient::get_prenom(){return  prenom;}
QString Patient::get_adresse(){return  adresse;}
QString Patient::get_lieu(){return  lieu;}
QString Patient::get_sexe(){return  sexe;}

bool Patient::ajouterPatient()
{
    QSqlQuery query;
    QString res1 = QString::number(code);
    QString res2 = QString::number(cin);
    query.prepare("INSERT INTO TABLE_PATIENT_FINAL(NOM, CODE, ADRESSE, PRENOM, SEXE, CIN, DATE_DE_NAISSANCE, LIEU, MAIL)" "VALUES (:nom, :code, :adresse, :prenom, :sexe, :cin, :date, :lieu, :email)");
    query.bindValue(":nom", nom);
    query.bindValue(":code", res1);
    query.bindValue(":cin", res2);
    query.bindValue(":adresse", adresse);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":date", date);
    query.bindValue(":lieu", lieu);
    query.bindValue(":email", email);
    return query.exec();

}

bool Patient::modifierPatient(int cod)
{
    QSqlQuery query;
    QString res = QString::number(cod);
    QString res1 = QString::number(code);
    QString res2 = QString::number(cin);
    query.prepare("UPDATE TABLE_PATIENT_FINAL "" SET NOM = :nom, CODE = :code, ADRESSE = :adresse, PRENOM = :prenom, SEXE = :sexe, CIN = :cin, DATE_DE_NAISSANCE = :date, LIEU = :lieu, MAIL = :email ""WHERE CODE = :cod");
    query.bindValue(":cod", res);
    query.bindValue(":nom", nom);
    query.bindValue(":code", res1);
    query.bindValue(":cin", res2);
    query.bindValue(":adresse", adresse);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":date", date);
    query.bindValue(":lieu", lieu);
    query.bindValue(":email", email);
    return query.exec();
}

bool Patient::supprimerPatient(int codee)
{
    QSqlQuery query;
    QString res = QString::number(codee);
    query.prepare("DELETE from TABLE_PATIENT_FINAL WHERE CODE = :code");
    query.bindValue(":code", res);
    return query.exec();
}

QSqlQueryModel * Patient::afficherPatient()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_PATIENT_FINAL");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("Sexe"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Vertical, QObject::tr("Date_De_Naissance"));
    model->setHeaderData(6, Qt::Vertical, QObject::tr("Lieu"));
    model->setHeaderData(7, Qt::Vertical, QObject::tr("Adresse"));
    model->setHeaderData(8, Qt::Vertical, QObject::tr("Email"));
    return model;
}
