#include "creditousuario.h"
#include "ui_creditousuario.h"

creditoUsuario::creditoUsuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creditoUsuario)
{
    ui->setupUi(this);
}

creditoUsuario::~creditoUsuario()
{
    delete ui;
}

void creditoUsuario::on_pushButton_clicked()
{
    MenuUsuario *volverMenu = new(MenuUsuario);
    this->close();
    volverMenu->show();
}

void creditoUsuario::on_pushButton_3_clicked()
{
    simulacionCredito *nuevaSimulacion = new(simulacionCredito);
    nuevaSimulacion->show();
}

void creditoUsuario::on_pushButton_4_clicked()
{
    QString ingresosMensuales = ui->ingresosMensuales->text();
    QString ingresosFamiliares = ui->IngresosFamiliares->text();
    QString nombreEmpresa = ui->NombrEmpresa->text();
    QString telefono = ui->telefono->text();
    QString tiempoLaborando = ui->tiempoLaborando->text();
    QString totalGastos= ui->totalGastos->text();
    QString valorPrestar= ui->totalPrestamo->text();
    QString plazoCreditos=ui->plazo->text();
    QString mesesFondo=ui->mesesFondo->text();

    if(ingresosMensuales == NULL || ingresosFamiliares == NULL || nombreEmpresa == NULL ||
            telefono == NULL || tiempoLaborando == "0" ||totalGastos == NULL || valorPrestar == NULL ||
            plazoCreditos == "0" || mesesFondo == "0")
    {
        QMessageBox::warning(this,"Error!","Ingrese todos los datos.");
    }else{
        int pos=0;
        bool flag = true;
        QRegExp regexIngresosMensuales("^\\d+$");
        QRegExpValidator validacionIngresosMensuales(regexIngresosMensuales,0);

        QRegExp regexIngresosFamiliares("^\\d+$");
        QRegExpValidator validacionIngresosFamiliares(regexIngresosFamiliares,0);

        QRegExp regexNombreEmpresa("^([A-Za-z\\s]+$)");
        QRegExpValidator validacionNombreEmpresa(regexNombreEmpresa);

        QRegExp regexTelefono("^\\d{7}$");
        QRegExpValidator validacionTelefono(regexTelefono,0);

        QRegExp regexTotalGastos("^\\d+$");
        QRegExpValidator validacionTotalGastos(regexTotalGastos,0);

        QRegExp regexValorPrestamo("^\\d+$");
        QRegExpValidator validacionValorPrestamo(regexValorPrestamo);

        if(validacionIngresosMensuales.validate(ingresosMensuales,pos)== QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Ingresos mensuales incorrectos.");
            flag=false;
            return;
        }
        if(validacionIngresosFamiliares.validate(ingresosFamiliares,pos)== QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Ingresos familiares incorrectos.");
            flag=false;
            return;
        }
        if(validacionIngresosMensuales.validate(ingresosMensuales,pos)== QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Ingresos mensuales incorrectos.");
            flag=false;
            return;
        }
        if(validacionNombreEmpresa.validate(nombreEmpresa,pos)== QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Nombre de la empresa incorrecto.");
            flag=false;
            return;
        }

        if(validacionTelefono.validate(telefono,pos)!= QValidator::Acceptable){
            QMessageBox::warning(this,"Error!","Telefono incorrecto(recuerde solo numero fijo).");
            flag=false;
            return;
        }
        if(validacionTotalGastos.validate(totalGastos,pos)== QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Total gastos incorrecto.");
            flag=false;
            return;
        }
        if(validacionValorPrestamo.validate(valorPrestar,pos)== QValidator::Invalid){
            QMessageBox::warning(this,"Error!","El valor a prestar esta incorrecto.");
            flag=false;
            return;
        }
        if(flag){
            credito nuevoCredito= credito(*Usuario::usuarioActual,ingresosMensuales.toInt(),ingresosFamiliares.toInt(),nombreEmpresa,telefono.toInt(),
                                          tiempoLaborando.toInt(),totalGastos.toInt(),valorPrestar.toInt(),plazoCreditos.toInt(),mesesFondo.toInt());

            credito::fondoCreditos.push_back(nuevoCredito);
            QMessageBox::information(this,"Credito generado!","Su credito esta en espera, en 10 dias habiles se revisara su solicitud.");
        }
    }





}

void creditoUsuario::on_pushButton_2_clicked()
{
    misCreditos *nuevosCreditos=new(misCreditos);
    nuevosCreditos->mostrarDatos();
    nuevosCreditos->show();
}
