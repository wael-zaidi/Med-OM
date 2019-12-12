#include "login_historique.h"
#include "ui_login_historique.h"
#include <QMessageBox>
#include<QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QtPrintSupport>
#include "connection_med_om.h"


login_historique::login_historique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_historique)
{
    ui->setupUi(this);

    afficher_tab();
}

login_historique::~login_historique()
{
    delete ui;
}

void login_historique::afficher_tab()
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from LOGIN_HISTORIQUE");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
}

void login_historique::on_text_id_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->text_id->text();

    if(text.isEmpty())
    {
        afficher_tab();
    }
    else
    {
        qry->prepare("select * from LOGIN_HISTORIQUE where LOGIN='"+text+"'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }



}

void login_historique::on_text_id_2_textChanged(const QString &arg1)
{

}

void login_historique::on_text_date_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text_date=ui->text_date->text();
    QString text_id=ui->text_id->text();

    if(text_date.isEmpty())
    {
        afficher_tab();
    }
    else
    {
        if(text_id.isEmpty())
        {
            qry->prepare("select * from LOGIN_HISTORIQUE where DATE_LOGIN='"+text_date+"'");
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView->setModel(modal);
        }
        else
        {
            qry->prepare("select * from LOGIN_HISTORIQUE where DATE_LOGIN='"+text_date+"' and LOGIN='"+text_id+"'");
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView->setModel(modal);
        }

    }
}

void login_historique::on_pushButton_clicked()
{
  /*  QPrinter printer;
    QString doc;

    printer.setPrinterName("printer1");
    QPrintDialog print_dialog(&printer,this);
   if(print_dialog.exec()== QDialog::Rejected) return ;

     ui->text_id-> */


    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("col1")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView->isColumnHidden(column)) {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;
}
