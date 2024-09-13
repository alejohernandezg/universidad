#include "menuusuario.h"
#include "ui_menuusuario.h"
#include "mainwindow.h"

MenuUsuario::MenuUsuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuUsuario)
{
    ui->setupUi(this);
}

MenuUsuario::~MenuUsuario()
{
    delete ui;
}

void MenuUsuario::on_pushButton_clicked()
{
    Usuario::usuarioActual = NULL;
    MainWindow *menuPrincipal = new(MainWindow);
    this->close();
    menuPrincipal->show();
}

void MenuUsuario::on_pushButton_5_clicked()
{
    creditoUsuario *opcionesCredito = new(creditoUsuario);
    this->close();
    opcionesCredito->show();
}

void MenuUsuario::on_pushButton_6_clicked()
{
    AhorroUsuario *opcionesAhorro = new(AhorroUsuario);
    this->close();
    opcionesAhorro->show();
}

void MenuUsuario::on_pushButton_7_clicked()
{
    auxilioUsuario *opcionesAuxilio = new(auxilioUsuario);
    this->close();
    opcionesAuxilio->show();
}

void MenuUsuario::on_pushButton_2_clicked()
{
    faq *preguntas = new(faq);
    this->close();
    preguntas->show();
}
