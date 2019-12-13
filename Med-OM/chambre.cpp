#include "chambre.h"

Chambre::Chambre()
{
    identifiant = 0;
    nom = "";
    prenom = "";
}
Chambre::Chambre( QString nom, QString prenom, int identifiant)
{
    this->identifiant = identifiant;
    this->nom = nom;
    this->prenom = prenom;
}
int Chambre::get_id(){return  identifiant;}
QString Chambre::get_nom(){return  nom;}
QString Chambre::get_prenom(){return prenom;}

bool Chambre::ajouterChambre()
{
    QSqlQuery query;
    QString res1 = QString::number(identifiant);
    query.prepare("INSERT INTO TABLE_CHAMBRE(PRENOM, NOM, IDENTIFIANT )" "VALUES (:prenom, :nom, :identifiant)");
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":identifiant", res1);

    return query.exec();
}

bool Chambre::modifierChambre(int idd)
{
    QSqlQuery query;
    QString res = QString::number(idd);
    QString res1 = QString::number(identifiant);
    query.prepare("UPDATE TABLE_CHAMBRE "" SET PRENOM = :prenom, NOM = :nom, IDENTIFIANT = :identifiant "" WHERE IDENTIFIANT = :idd");
    query.bindValue(":idd", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":identifiant", res1);
    return query.exec();
}

bool Chambre::supprimerChambre(int idd)
{
    QSqlQuery query;
    QString res = QString::number(idd);
    query.prepare("DELETE from TABLE_CHAMBRE WHERE IDENTIFIANT = :identifiant");
    query.bindValue(":identifiant", res);
    return  query.exec();
}

QSqlQueryModel * Chambre::afficherChambre()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE_CHAMBRE ORDER BY identifiant ASC");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("Identifiant"));
    return model;
}

