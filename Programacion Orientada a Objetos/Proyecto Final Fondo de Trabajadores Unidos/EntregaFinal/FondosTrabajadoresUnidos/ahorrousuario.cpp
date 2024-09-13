#include "ahorrousuario.h"
#include "ui_ahorrousuario.h"

AhorroUsuario::AhorroUsuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AhorroUsuario)
{
    ui->setupUi(this);
}

AhorroUsuario::~AhorroUsuario()
{
    delete ui;
}

void AhorroUsuario::on_pushButton_2_clicked()
{
    MenuUsuario *volverMenu = new(MenuUsuario);
    this->close();
    volverMenu->show();
}

void AhorroUsuario::on_pushButton_clicked()
{
    float porcentaje1 = ui->porcentaje->text().toFloat();
    QString porcentaje2 = ui->porcentaje->text();
    float ingresos = ui->ingresosMensuales->text().toFloat();

    if(ingresos == 0){
        QMessageBox::warning(this,"Error!","Digite sus ingresos.");
        return;
    }else{

        bool flag=true;
        if(ahorro::fondoAhorros.isEmpty()){

            ahorro nuevoAhorro = ahorro(* Usuario::usuarioActual,ui->fechaActual->date().day(),ui->fechaActual->date().month(),ui->fechaActual->date().year());
            nuevoAhorro.setMontoAhorrado(0);

            float sumador= nuevoAhorro.getMontoAhorrado() + (ingresos * porcentaje1/100);
            nuevoAhorro.setMontoAhorrado(sumador);
            ahorro::fondoAhorros.append(nuevoAhorro);
            flag = false;
            QMessageBox::information(this,"Felicidades!","Cuenta de ahorro creada!");

        }else{
            for(int i=0;i<ahorro::fondoAhorros.size();i++){
                if(ahorro::fondoAhorros[i].getMiUsuario().getNickname() == Usuario::usuarioActual->getNickname())
                {
                    if((ui->fechaActual->date().day() >= ahorro::fondoAhorros[i].getDiaAhorro() &&  ui->fechaActual->date().month() > ahorro::fondoAhorros[i].getMesAhorro())&&
                            (ui->fechaActual->date().year()>= ahorro::fondoAhorros[i].getYearAhorro()))
                    {
                        float sumador  = ahorro::fondoAhorros[i].getMontoAhorrado() + (ingresos *porcentaje1/100);
                        ahorro::fondoAhorros[i].setMontoAhorrado(sumador);
                        ahorro::fondoAhorros[i].setDiaAhorro(ui->fechaActual->date().day());
                        ahorro::fondoAhorros[i].setMesAhorro(ui->fechaActual->date().month());
                        ahorro::fondoAhorros[i].setYearAhorro(ui->fechaActual->date().year());

                        QMessageBox::information(this,"Felicidades!","Ahorro añadido.");
                        flag = false;
                        return;
                    }else{
                        QMessageBox::warning(this,"Error!","Aun no puede ahorrar!");
                        return;
                    }
                }
            }
            if(flag){
                float sumador;

                ahorro nuevoAhorro = ahorro(* Usuario::usuarioActual,ui->fechaActual->date().day(),ui->fechaActual->date().month(),ui->fechaActual->date().year());
                nuevoAhorro.setMontoAhorrado(0);
                sumador = nuevoAhorro.getMontoAhorrado() + (ingresos * porcentaje1/100);

                nuevoAhorro.setMontoAhorrado(sumador);
                ahorro::fondoAhorros.append(nuevoAhorro);
                QMessageBox::information(this,"Felicidades!","Cuenta de ahorro creada!");
            }
        }
    }


}

void AhorroUsuario::on_pushButton_3_clicked()
{
    misAhorros *nuevosAhorros=new(misAhorros);
    nuevosAhorros->mostrarDatos();
    nuevosAhorros->show();
}
