#include "rdv.h"
#include"rendez_vous.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>
#include<QDate>
#include <QMessageBox>
#include"arduino.h"

rdv::rdv()
{
    nom=""; prenom=""; date=0; heure=0; id=0;

}

rdv::rdv(QString nom, QString prenom, int date, int heure, int id)

{
     this->nom=nom;
    this->prenom=prenom;
    this->date=date;
    this->heure=heure;
    this->id=id;
}

bool rdv::ajouter()
{
    QString time = QTime::currentTime().toString();
                    int date_day = QDate::currentDate().day();
                    int date_mounth = QDate::currentDate().month();
                    int date_year = QDate::currentDate().year();
                    QString date = QString::number(date_day) +"/"+ QString::number(date_mounth)+"/"+QString::number(date_year);

    QString res2= QString::number(heure);
    QString res3= QString::number(id);
            QSqlQuery query;
          query.prepare("INSERT INTO "" rendez_vous (nom, prenom, date_rdv, heure, identifiant) "
                        "VALUES (:a, :b, :c, :d, :e)");
          query.bindValue(":a", nom);
          query.bindValue(":b", prenom);
          query.bindValue(":c", date);
          query.bindValue(":d", time);
          query.bindValue(":e", res3);
          return query.exec();
}

QSqlQueryModel * rdv::afficher()
{
    QSqlQuery qry;
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from rendez_vous");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_rdv"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
          return model;




}

bool rdv::supprimer(int idd)
{
QSqlQuery query;
QString res3= QString::number(idd);
query.prepare("Delete from rendez_vous where Identifiant =?");
query.addBindValue(res3);
return    query.exec();
}

bool rdv::modifier(QString id, QString nom, QString prenom, QString date, QString heure)
{

    QSqlQuery query;
          query.prepare("UPDATE rendez_vous  SET nom='"+nom+"', prenom= '"+prenom+"', date_rdv = '"+date+"', heure= '"+heure+"' WHERE identifiant='"+id+"' " );
          /*query.bindValue(":id", id);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":date", date);
          query.bindValue(":heure", heure);*/
          return query.exec();
}

QSqlQueryModel * rdv::afficher_T()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from rendez_vous order by Nom");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_rdv"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Identifiant"));
          return model;
}
