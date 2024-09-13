#include "misahorros.h"
#include "ui_misahorros.h"

misAhorros::misAhorros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::misAhorros)
{
    ui->setupUi(this);
}

void misAhorros::mostrarDatos()
{
    QString AhorrosActuales;
    for(int i=0;i<ahorro::fondoAhorros.size();i++){
        if(Usuario::usuarioActual->getNickname()== ahorro::fondoAhorros[i].getMiUsuario().getNickname()){
            AhorrosActuales.append("---------------------------------------------------------------");
            AhorrosActuales.append("\n");
            AhorrosActuales.append("Total en la cuenta:");
            QString valor = QString::number(ahorro::fondoAhorros[i].getMontoAhorrado());
            AhorrosActuales.append(valor);
            AhorrosActuales.append("\n");
            AhorrosActuales.append("Ultima fecha ahorrada:");
            QString fecha = QString::number(ahorro::fondoAhorros[i].getDiaAhorro());
            fecha.append("/");
            fecha.append(QString::number(ahorro::fondoAhorros[i].getMesAhorro()));
            fecha.append("/");
            fecha.append(QString::number(ahorro::fondoAhorros[i].getYearAhorro()));
            AhorrosActuales.append(fecha);
            AhorrosActuales.append("\n");
        }
    }
    QLabel *ejemplo=new(QLabel);
    ejemplo->setText(AhorrosActuales);
    ui->listaAhorros->setWidget(ejemplo);

}

misAhorros::~misAhorros()
{
    delete ui;
}
