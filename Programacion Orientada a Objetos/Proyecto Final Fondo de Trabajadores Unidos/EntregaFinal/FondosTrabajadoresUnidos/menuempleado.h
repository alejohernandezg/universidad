#ifndef MENUEMPLEADO_H
#define MENUEMPLEADO_H

#include <QWidget>
#include "mainwindow.h"
#include "creditoempleado.h"
#include "auxilioempleado.h"
#include "ahorroempleado.h"
#include "cambiarvalores.h"

namespace Ui {
class MenuEmpleado;
}

class MenuEmpleado : public QWidget
{
    Q_OBJECT

public:
    explicit MenuEmpleado(QWidget *parent = 0);
    ~MenuEmpleado();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MenuEmpleado *ui;
};

#endif // MENUEMPLEADO_H
