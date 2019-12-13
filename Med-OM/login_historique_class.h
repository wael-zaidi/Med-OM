#ifndef LOGIN_HISTORIQUE_CLASS_H
#define LOGIN_HISTORIQUE_CLASS_H
#include<QString>

class login_historique_class
{
    QString time ;
    int date_day ;
    int date_mounth ;
    int date_year ;
    QString date ;
    QString action ;

public:
    login_historique_class();

    void afficher_tab();
    void set_labels_login();
    void qry_historique_login(QString id);

};

#endif // LOGIN_HISTORIQUE_CLASS_H
