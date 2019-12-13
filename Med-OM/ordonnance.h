#ifndef ORDONNANCE_H
#define ORDONNANCE_H
#include <qstring.h>
#include <qsqlquerymodel.h>

class ordonnance
{
    int date,code;
   QString nom, prenom, ord;
public:
    ordonnance();
    ordonnance(QString ,QString,QString,int,int);
    int getdate(){return date;}
    void setdate(int date){this->date=date;}
    int getcode(){return code;}
    void setcode(int code){this->code=code;}
    bool ajouter();

        QSqlQueryModel * afficher();
        bool supprimer(int);
};


#endif // ORDONNANCE_H
