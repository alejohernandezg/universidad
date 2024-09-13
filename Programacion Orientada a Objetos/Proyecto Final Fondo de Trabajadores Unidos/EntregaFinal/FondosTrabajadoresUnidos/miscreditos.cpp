#include "miscreditos.h"
#include "ui_miscreditos.h"



misCreditos::misCreditos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::misCreditos)
{
    ui->setupUi(this);

}

misCreditos::~misCreditos()
{
    delete ui;
}

void misCreditos::mostrarDatos()
{
    QString creditosActuales;
    for(int i=0;i<credito::fondoCreditos.size();i++){
        if(Usuario::usuarioActual->getNickname()== credito::fondoCreditos[i].getMiUsuario().getNickname()){
            creditosActuales.append("---------------------------------------------------------------------");
            creditosActuales.append("\n");
            creditosActuales.append("Valor a prestar:");
            QString valor = QString::number(credito::fondoCreditos[i].getValorPrestar());
            creditosActuales.append(valor);
            creditosActuales.append("\n");
            creditosActuales.append("Plazo del credito:");
            QString plazo = QString::number(credito::fondoCreditos[i].getPlazoCreditos());
            creditosActuales.append(plazo);
            creditosActuales.append("\n");
            creditosActuales.append("Estado del credito:");
            creditosActuales.append(credito::fondoCreditos[i].getEstado());
            creditosActuales.append("\n");
        }
    }
    QLabel *ejemplo=new(QLabel);
    ejemplo->setText(creditosActuales);
    ui->misCreditos_2->setWidget(ejemplo);

}
