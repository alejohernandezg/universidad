#ifndef MENUUSUARIO_H
#define MENUUSUARIO_H

#include <QWidget>
#include "mainwindow.h"
#include "ahorrousuario.h"
#include "auxiliousuario.h"
#include "faq.h"

namespace Ui {
class MenuUsuario;
}

class MenuUsuario : public QWidget
{
    Q_OBJECT

public:
    explicit MenuUsuario(QWidget *parent = 0);
    ~MenuUsuario();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MenuUsuario *ui;
};

#endif // MENUUSUARIO_H
