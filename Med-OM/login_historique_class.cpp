#include "login_historique_class.h"
#include<QTime>
#include<QDate>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include<QSqlQuery>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QtPrintSupport>
#include <QMessageBox>

login_historique_class::login_historique_class()
{
    time="";
    date_day=0 ;
    date_mounth=0;
    date_year=0;
    date="";
    action="";

}


void login_historique_class::set_labels_login()
{
    this->time = QTime::currentTime().toString();
    this->date_day = QDate::currentDate().day();
    this->date_mounth = QDate::currentDate().month();
    this->date_year = QDate::currentDate().year();
    this->date = QString::number(date_day) +"/"+ QString::number(date_mounth)+"/"+QString::number(date_year);
    this->action = "login";

}

void login_historique_class::qry_historique_login(QString id)
{


   QSqlQuery qry_hist;

    qry_hist.prepare("insert into LOGIN_HISTORIQUE (LOGIN,DATE_LOGIN,HEURE_LOGIN,ACTION) values ('"+id+"','"+date+"','"+time+"','"+action+"')");
   qry_hist.exec();

}
