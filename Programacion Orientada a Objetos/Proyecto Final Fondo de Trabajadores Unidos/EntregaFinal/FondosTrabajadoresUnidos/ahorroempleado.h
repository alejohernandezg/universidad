#ifndef AHORROEMPLEADO_H
#define AHORROEMPLEADO_H

#include <QWidget>
#include "menuempleado.h"
#include "ahorro.h"


namespace Ui {
class ahorroEmpleado;
}

class ahorroEmpleado : public QWidget
{
    Q_OBJECT

public:
    explicit ahorroEmpleado(QWidget *parent = 0);
    void mostrarDatos();
    ~ahorroEmpleado();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ahorroEmpleado *ui;
};

#endif // AHORROEMPLEADO_H
