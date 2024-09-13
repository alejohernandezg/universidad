#include "simulacioncredito.h"
#include "ui_simulacioncredito.h"

simulacionCredito::simulacionCredito(QWidget *parent):
    QWidget(parent),
    ui(new Ui::simulacionCredito)
{
    ui->setupUi(this);

}

simulacionCredito::~simulacionCredito()
{
    delete ui;
}


void simulacionCredito::on_pushButton_2_clicked()
{
    float montoSimular = ui->montoSimular->text().toFloat();
    float plazo = ui->plazo->text().toFloat();

    float totalPago;
    float interes = (constantes::misConstantes->getSalarioMinimoVigente()*montoSimular)*(constantes::misConstantes->getTasaInteres()/100);

    float seguro = (constantes::misConstantes->getSalarioMinimoVigente()*montoSimular)* (constantes::misConstantes->getSeguroVida()/100);
    totalPago = (constantes::misConstantes->getSalarioMinimoVigente() *montoSimular)+seguro+(constantes::misConstantes->getUsoPlataforma());
    float miIva = (totalPago*(constantes::misConstantes->getIva())/100);
    totalPago = totalPago/plazo + interes;

    QString str = QString::number(totalPago);

    QString pagoAdmi = QString::number(constantes::misConstantes->getPagoAdministracion());
    QString uso = QString::number(constantes::misConstantes->getUsoPlataforma());

    ui->pago->setText(pagoAdmi);
    ui->seguro->setText(QString::number(seguro));
    ui->plataforma->setText(uso);
    ui->iva->setText(QString::number(miIva));
    ui->interes->setText(QString::number(interes));
    ui->cuota->setText(str);
}
