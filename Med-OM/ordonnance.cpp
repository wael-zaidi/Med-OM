#include "ordonnance.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>
#include<QDate>

ordonnance::ordonnance()
{
    nom=""; prenom=""; ord=""; date=0; code=0;
}


ordonnance::ordonnance(QString nom, QString prenom, QString ord, int date, int code)

{
     this->nom=nom;
    this->prenom=prenom;
    this->ord=ord;
    this->date=date;
    this->code=code;
}

bool ordonnance::ajouter()
{
    int date_day = QDate::currentDate().day();
    int date_mounth = QDate::currentDate().month();
    int date_year = QDate::currentDate().year();
    QString date = QString::number(date_day) +"/"+ QString::number(date_mounth)+"/"+QString::number(date_year);
    QString res2= QString::number(code);
            QSqlQuery query;
          query.prepare("INSERT INTO "" ordonnance (nom, prenom, date_or,  ordonnance, code) "
                        "VALUES (:a, :b, :c, :d, :e)");
          query.bindValue(":a", nom);
          query.bindValue(":b", prenom);
          query.bindValue(":d", ord);
          query.bindValue(":c", date);
          query.bindValue(":e", res2);
          return query.exec();
}

QSqlQueryModel * ordonnance::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from ordonnance");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_or"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Ordonnance"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Code"));
          return model;
}

bool ordonnance::supprimer(int idd)
{
QSqlQuery query;
QString res3= QString::number(idd);
query.prepare("Delete from ordonnance where Code =?");
query.addBindValue(res3);
return    query.exec();
}
