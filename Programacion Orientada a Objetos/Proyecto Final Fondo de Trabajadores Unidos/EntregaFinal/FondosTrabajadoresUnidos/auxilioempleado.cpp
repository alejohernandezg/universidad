#include "auxilioempleado.h"
#include "ui_auxilioempleado.h"

AuxilioEmpleado::AuxilioEmpleado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuxilioEmpleado)
{
    ui->setupUi(this);
}

void AuxilioEmpleado::mostrarDatos()
{
    QString auxiliosActuales;
    int monto=0;
    float total=0;
    for(int i=0;i<auxilio::fondoAuxilios.size();i++){
        if(auxilio::fondoAuxilios[i].getEstado()=="Aprobado"){
            monto +=1;
            total += auxilio::fondoAuxilios[i].getTotalPago();
        }
        auxiliosActuales.append("---------------------------------------------------------------------");
        auxiliosActuales.append("\n");
        auxiliosActuales.append("Nombre del solicitante:");
        auxiliosActuales.append(auxilio::fondoAuxilios[i].getMiUsuario().getNombre());
        auxiliosActuales.append(" ");
        auxiliosActuales.append(auxilio::fondoAuxilios[i].getMiUsuario().getApellido());
        auxiliosActuales.append("\n");
        auxiliosActuales.append("Usuario del solicitante:");
        auxiliosActuales.append(auxilio::fondoAuxilios[i].getMiUsuario().getNickname());
        auxiliosActuales.append("\n");
        auxiliosActuales.append("Tipo del auxilio:");
        auxiliosActuales.append(auxilio::fondoAuxilios[i].getTipoAuxilio());
        auxiliosActuales.append("\n");
        auxiliosActuales.append("Solicitado:");
        QString solicitado = QString::number(auxilio::fondoAuxilios[i].getTotalPago());
        auxiliosActuales.append(solicitado);
        auxiliosActuales.append("\n");
        auxiliosActuales.append("Estado del auxilio:");
        auxiliosActuales.append(auxilio::fondoAuxilios[i].getEstado());
        auxiliosActuales.append("\n");

    }

    ui->totalAuxilios->setText(QString::number(monto));
    ui->montoAuxilios->setText(QString::number(total));
    QLabel *ejemplo=new(QLabel);
    ejemplo->setText(auxiliosActuales);
    ui->fondoAuxilios->setWidget(ejemplo);
}

AuxilioEmpleado::~AuxilioEmpleado()
{
    delete ui;
}

void AuxilioEmpleado::on_pushButton_2_clicked()
{
    MenuEmpleado *volverMenu = new(MenuEmpleado);
    volverMenu->show();
    this->close();
}

void AuxilioEmpleado::on_pushButton_clicked()
{
    if(auxilio::fondoAuxilios.isEmpty())
    {
        QMessageBox::warning(this,"Error!","No hay creditos disponibles");
    }else{
        int i=0;
        int contador=0;
        while(i < auxilio::fondoAuxilios.size() && contador < auxilio::fondoAuxilios.size()){
            int posRamdon = ((rand() % (auxilio::fondoAuxilios.size())) + 0);
            qDebug() << posRamdon;

            if(auxilio::fondoAuxilios[posRamdon].getEstado() == "Espera"){
                if(ui->montoAuxilios->text().toInt()+ auxilio::fondoAuxilios[posRamdon].getTotalPago() < constantes::misConstantes->getMaximoAuxilio()){
                    auxilio::fondoAuxilios[posRamdon].setEstado("Aprobado");
                    i +=1;
                }else{
                    QMessageBox::warning(this,"Error","Monto excedido!");
                    return;
                }
            }
            if(auxilio::fondoAuxilios[posRamdon].getEstado() == "Aprobado"){
                contador +=1;
            }
        }

        QMessageBox::information(this,"Listo!","Actualice a la pagina para ver que auxilios fueron aprobados");
        return;
    }

}
