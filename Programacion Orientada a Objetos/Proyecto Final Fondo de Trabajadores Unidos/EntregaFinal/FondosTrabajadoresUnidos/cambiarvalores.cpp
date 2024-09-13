#include "cambiarvalores.h"
#include "ui_cambiarvalores.h"

cambiarValores::cambiarValores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cambiarValores)
{
    ui->setupUi(this);
}

cambiarValores::~cambiarValores()
{
    delete ui;
}

void cambiarValores::on_pushButton_clicked()
{
    float salario = ui->salarioMinimo->text().toFloat();
    float pago = ui->pagoAdmi->text().toFloat();
    float seguro= ui->SeguroVida->text().toFloat();
    float uso = ui->UsoPlataforma->text().toFloat();
    float iva = ui->iva->text().toFloat();
    int scoring = ui->scoring->text().toInt();
    int auxilio = ui->auxilio->text().toInt();
    if(salario != 0.00){
        constantes::misConstantes->setSalarioMinimoVigente(salario);
    }
    if(pago!=0.00){
        constantes::misConstantes->setPagoAdministracion(pago);
    }
    if(seguro!=0.00){
        constantes::misConstantes->setSeguroVida(seguro);
    }
    if(uso!=0.00){
        constantes::misConstantes->setUsoPlataforma(uso);
    }
    if(iva!=0.00){
        constantes::misConstantes->setIva(iva);
    }
    if(scoring != 0){
        constantes::misConstantes->setScoring(scoring);
    }
    if(auxilio != 0){
        constantes::misConstantes->setMaximoAuxilio(auxilio);
    }

}
