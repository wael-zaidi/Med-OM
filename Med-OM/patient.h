#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Patient
{
public:
    Patient();
    Patient(int, int, QDate, QString, QString, QString, QString, QString, QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_lieu();
    QString get_sexe();
    int get_code();
    int get_cin();
    QDate get_Date();
    bool ajouterPatient();
    bool modifierPatient(int);
    bool supprimerPatient(int);
    QSqlQueryModel * afficherPatient();
private:
    QString nom, prenom, adresse, lieu, sexe, email;
    int code, cin;
    QDate date;
};

#endif // PATIENT_H
