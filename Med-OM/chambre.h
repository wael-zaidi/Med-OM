#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <QString>
#include <QSqlQueryModel>
#include "patient.h"
class Chambre
{
public:
    Chambre();
    Chambre(QString, QString, int);
    int get_id();
    QString get_nom();
    QString get_prenom();
    bool ajouterChambre();
    bool modifierChambre(int);
    bool supprimerChambre(int);
    QSqlQueryModel * afficherChambre();


private:
    QString nom, prenom;
    int identifiant;
};

#endif // CHAMBRE_H
