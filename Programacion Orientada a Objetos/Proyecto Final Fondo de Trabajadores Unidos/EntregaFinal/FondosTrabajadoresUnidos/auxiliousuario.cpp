#include "auxiliousuario.h"
#include "ui_auxiliousuario.h"

auxilioUsuario::auxilioUsuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auxilioUsuario)
{
    ui->setupUi(this);
}

auxilioUsuario::~auxilioUsuario()
{
    delete ui;
}

void auxilioUsuario::on_pushButton_clicked()
{
    MenuUsuario *volverMenu = new(MenuUsuario);
    this->close();
    volverMenu->show();
}

void auxilioUsuario::on_pushButton_2_clicked()
{
    QString tipo = ui->tipoauxilio->currentText();
    int totalPago= ui->totalpago->text().toInt();

    if(tipo == "Seleccione..." || totalPago == 0){
        QMessageBox::warning(this,"Error!","Ingrese todos los datos.");
        return;
    }else{
        if(tipo == "Calamidad domestica"){
            int pagoCalamidad = totalPago*0.50;
            if(pagoCalamidad > constantes::misConstantes->getSalarioMinimoVigente()*2){
                QMessageBox::warning(this,"Error!","Auxilio no permitido, excede lo permitido");
            }else{
                auxilio nuevoAhorro = auxilio(*Usuario::usuarioActual,tipo,pagoCalamidad);
                nuevoAhorro.setEstado("Espera");
                auxilio::fondoAuxilios.append(nuevoAhorro);
                QMessageBox::information(this,"Completado!","Auxilio solicitado, entre 10 dias habilas se revisara su solicitud.");
                return;
            }
        }
        if(tipo == "Educativo"){
            float pagoEducativo = constantes::misConstantes->getSalarioMinimoVigente()*0.20;
            auxilio nuevoAhorro = auxilio(*Usuario::usuarioActual,tipo,pagoEducativo);
            nuevoAhorro.setEstado("Espera");
            auxilio::fondoAuxilios.append(nuevoAhorro);
            QMessageBox::information(this,"Completado!","Auxilio solicitado, entre 10 dias habilas se revisara su solicitud.");
            return;
        }
    }
}

void auxilioUsuario::on_pushButton_3_clicked()
{
    misAuxilios *nuevosAuxilios = new(misAuxilios);
    nuevosAuxilios->mostrarDatos();
    nuevosAuxilios->show();
}
