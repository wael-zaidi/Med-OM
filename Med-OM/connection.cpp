#include "connection.h"
#include <QSqlError>

Connection::Connection(){
                      }
bool Connection::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Source_Projet2A");
                           db.setUserName("Wael");//inserer nom de l'utilisateur
                           db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else
    throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connection::fermerConnexion()
{
    db.close();
}
