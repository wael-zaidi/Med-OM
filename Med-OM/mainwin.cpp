#include "mainwin.h"
#include "ui_mainwin.h"
#include "mainwindow.h"
#include "rendez_vous.h"
MAINWIN::MAINWIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MAINWIN)
{
    ui->setupUi(this);
    QPixmap pix(":/Ressource/dashboard.jpg");
    int w = ui->label_Background->width();
    int h = ui->label_Background->height();
    ui->label_Background->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));

    QPixmap pix1(":/Ressource/icon_edit.png");
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));

    QPixmap pix2(":/Ressource/prescription.png");
    int w2 = ui->label_2->width();
    int h2 = ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(w2,h2,Qt::IgnoreAspectRatio));

    QPixmap pix3("C:/Users/alaae/Downloads/menu.png");
    int w3 = ui->label_3->width();
    int h3 = ui->label_3->height();
    ui->label_3->setPixmap(pix3.scaled(w3,h3,Qt::IgnoreAspectRatio));

    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");

}

MAINWIN::~MAINWIN()
{
    delete ui;
}

void MAINWIN::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 18pt Bahnschrift;");

}

void MAINWIN::on_pushButton_released()
{
    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");

}

void MAINWIN::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 18pt Bahnschrift;");

}

void MAINWIN::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
    m = new MainWindow();
    m->show();
}

void MAINWIN::on_pushButton_3_pressed()
{
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 18pt Bahnschrift;");

}

void MAINWIN::on_pushButton_3_released()
{
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 18pt Bahnschrift;");
    r = new Rendez_Vous();
    r->show();

}

void MAINWIN::on_pushButton_3_clicked()
{

}
