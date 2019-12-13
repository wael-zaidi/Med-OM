#ifndef LOGIN_HISTORIQUE_H
#define LOGIN_HISTORIQUE_H
#include "login_ajouter.h"
#include <QDialog>

namespace Ui {
class login_historique;
}

class login_historique : public QDialog
{
    Q_OBJECT

public:

 

    explicit login_historique(QWidget *parent = nullptr);
    ~login_historique();

    void afficher_tab();
  //  void set_labels_login();
   // void qry_historique_login(QString id);


private slots:
    void on_text_id_textChanged(const QString &arg1);

    void on_text_id_2_textChanged(const QString &arg1);

    void on_text_date_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::login_historique *ui;
};

#endif // LOGIN_HISTORIQUE_H
