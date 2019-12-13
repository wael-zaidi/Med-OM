#ifndef MAINWIN_H
#define MAINWIN_H

#include <QDialog>
#include "mainwindow.h"
#include "rendez_vous.h"
namespace Ui {
class MAINWIN;
}

class MAINWIN : public QDialog
{
    Q_OBJECT

public:
    explicit MAINWIN(QWidget *parent = nullptr);

    ~MAINWIN();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_3_clicked();

private:
    Ui::MAINWIN *ui;
    MainWindow *m;
    Rendez_Vous *r;
};

#endif // MAINWIN_H
