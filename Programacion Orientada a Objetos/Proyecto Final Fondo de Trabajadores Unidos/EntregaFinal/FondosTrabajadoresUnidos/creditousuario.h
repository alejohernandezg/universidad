#ifndef CREDITOUSUARIO_H
#define CREDITOUSUARIO_H

#include <QWidget>
#include "menuusuario.h"
#include "mainwindow.h"
#include "credito.h"
#include "constantes.h"
#include "simulacioncredito.h"
#include "miscreditos.h"

namespace Ui {
class creditoUsuario;
}

class creditoUsuario : public QWidget
{
    Q_OBJECT

public:
    explicit creditoUsuario(QWidget *parent = 0);
    ~creditoUsuario();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::creditoUsuario *ui;
};

#endif // CREDITOUSUARIO_H
