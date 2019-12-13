#ifndef RDV_H
#define RDV_H

#include<QString>
#include <QtSql/QSqlQueryModel>


class rdv
{
    int date,heure,id;
    QString nom, prenom;

 public:
    rdv();
    rdv(QString ,QString,int,int,int);
    int getdate(){return date;}
    void setdate(int date){this->date=date;}
    int getheure(){return heure;}
    void setheure(int heure){this->heure=heure;}
    int getmontant(){return id;}
    void setmontant(int id){this->id=id;}
    bool ajouter();
        QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(QString, QString, QString, QString, QString);
     QSqlQueryModel * afficher_T();
        ~ rdv(){}

private:
     // objet temporaire
};
#endif // RDV_H
