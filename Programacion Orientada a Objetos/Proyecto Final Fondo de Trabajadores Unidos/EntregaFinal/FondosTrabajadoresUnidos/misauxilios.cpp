#include "misauxilios.h"
#include "ui_misauxilios.h"

misAuxilios::misAuxilios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::misAuxilios)
{
    ui->setupUi(this);
}

misAuxilios::~misAuxilios()
{
    delete ui;
}

void misAuxilios::mostrarDatos()
{
    QString auxiliosActuales;
    for(int i=0;i<auxilio::fondoAuxilios.size();i++){
        if(Usuario::usuarioActual->getNickname()== auxilio::fondoAuxilios[i].getMiUsuario().getNickname()){
            auxiliosActuales.append("---------------------------------------------------------------------");
            auxiliosActuales.append("\n");
            auxiliosActuales.append("Tipo de auxilio:");
            QString tipo = auxilio::fondoAuxilios[i].getTipoAuxilio();
            auxiliosActuales.append(tipo);
            auxiliosActuales.append("\n");
            auxiliosActuales.append("Total factura/matricula:");
            QString total = QString::number(auxilio::fondoAuxilios[i].getTotalPago());
            auxiliosActuales.append(total);
            auxiliosActuales.append("\n");
            auxiliosActuales.append("Estado del auxilio:");
            auxiliosActuales.append(auxilio::fondoAuxilios[i].getEstado());
            auxiliosActuales.append("\n");
        }
    }
    QLabel *ejemplo=new(QLabel);
    ejemplo->setText(auxiliosActuales);
    ui->auxiliosUsuario->setWidget(ejemplo);

}
