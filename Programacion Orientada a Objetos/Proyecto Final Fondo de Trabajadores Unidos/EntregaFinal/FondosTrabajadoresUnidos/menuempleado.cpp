#include "menuempleado.h"
#include "ui_menuempleado.h"

MenuEmpleado::MenuEmpleado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuEmpleado)
{
    ui->setupUi(this);
}

MenuEmpleado::~MenuEmpleado()
{
    delete ui;
}

void MenuEmpleado::on_pushButton_clicked()
{
    MainWindow *menuPrincipal = new(MainWindow);
    this->close();
    menuPrincipal->show();

}

void MenuEmpleado::on_pushButton_5_clicked()
{
    creditoEmpleado *creditosFondo = new(creditoEmpleado);
    creditosFondo->mostrarDatos();
    creditosFondo->show();
    this->close();
}

void MenuEmpleado::on_pushButton_7_clicked()
{
    AuxilioEmpleado *auxiliosFondo = new(AuxilioEmpleado);
    auxiliosFondo->mostrarDatos();
    auxiliosFondo->show();
    this->close();
}

void MenuEmpleado::on_pushButton_6_clicked()
{
    ahorroEmpleado *ahorrosFondo = new(ahorroEmpleado);
    ahorrosFondo->mostrarDatos();
    ahorrosFondo->show();
    this->close();
}

void MenuEmpleado::on_pushButton_2_clicked()
{
    cambiarValores *nuevoCambiarValores=new(cambiarValores);
    nuevoCambiarValores->show();
}
