#ifndef AUXILIOEMPLEADO_H
#define AUXILIOEMPLEADO_H

#include <QWidget>
#include "menuempleado.h"

namespace Ui {
class AuxilioEmpleado;
}

class AuxilioEmpleado : public QWidget
{
    Q_OBJECT

public:
    explicit AuxilioEmpleado(QWidget *parent = 0);
    void mostrarDatos();
    ~AuxilioEmpleado();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AuxilioEmpleado *ui;
};

#endif // AUXILIOEMPLEADO_H
