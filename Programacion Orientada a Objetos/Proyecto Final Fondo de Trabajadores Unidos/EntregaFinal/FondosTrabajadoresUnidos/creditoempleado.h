#ifndef CREDITOEMPLEADO_H
#define CREDITOEMPLEADO_H

#include <QWidget>
#include "creditousuario.h"
#include "constantes.h"


namespace Ui {
class creditoEmpleado;
}

class creditoEmpleado : public QWidget
{
    Q_OBJECT

public:
    explicit creditoEmpleado(QWidget *parent = 0);
    void mostrarDatos();
    ~creditoEmpleado();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::creditoEmpleado *ui;
};

#endif // CREDITOEMPLEADO_H
