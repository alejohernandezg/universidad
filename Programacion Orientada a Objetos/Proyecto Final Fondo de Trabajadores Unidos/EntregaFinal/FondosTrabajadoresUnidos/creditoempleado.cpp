#include "creditoempleado.h"
#include "ui_creditoempleado.h"

creditoEmpleado::creditoEmpleado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creditoEmpleado)
{
    ui->setupUi(this);
}

void creditoEmpleado::mostrarDatos()
{
    QString creditosActuales;
    int monto=0;
    float total=0;
    for(int i=0;i<credito::fondoCreditos.size();i++){
        if(credito::fondoCreditos[i].getEstado()=="Aprobado"){
            monto +=1;
            total += credito::fondoCreditos[i].getValorPrestar();
        }
        creditosActuales.append("---------------------------------------------------------------------");
        creditosActuales.append("\n");
        creditosActuales.append("Nombre del solicitante:");
        creditosActuales.append(credito::fondoCreditos[i].getMiUsuario().getNombre());
        creditosActuales.append(" ");
        creditosActuales.append(credito::fondoCreditos[i].getMiUsuario().getApellido());
        creditosActuales.append("\n");
        creditosActuales.append("Usuario del solicitante:");
        creditosActuales.append(credito::fondoCreditos[i].getMiUsuario().getNickname());
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

    ui->totalMonto->setText(QString::number(total));
    ui->creditosAprobados->setText(QString::number(monto));
    QLabel *ejemplo=new(QLabel);
    ejemplo->setText(creditosActuales);
    ui->fondoCreditos->setWidget(ejemplo);
}

creditoEmpleado::~creditoEmpleado()
{
    delete ui;
}

void creditoEmpleado::on_pushButton_2_clicked()
{
    MenuEmpleado *volverMenu = new(MenuEmpleado);
    volverMenu->show();
    this->close();
}

void creditoEmpleado::on_pushButton_clicked()
{
    for(int i=0;i<credito::fondoCreditos.size();i++){
        int scoringCredito=0;
        float disponible = (credito::fondoCreditos[i].getIngresosMensuales() - credito::fondoCreditos[i].getTotalGastos())*0.25;
        int mesesInclusion = ((rand() % (35)) + 0);
        int mesesRegistros = ((rand() % (60)) + 0);
        int numeroConsultas = ((rand() % (5)) + 0);
        if(disponible < credito::fondoCreditos[i].getCuotaMensual()){
            scoringCredito += 0;
        }
        if(disponible > credito::fondoCreditos[i].getCuotaMensual()){
            scoringCredito += 50;
        }
        if(disponible > (credito::fondoCreditos[i].getCuotaMensual())*1.5){
            scoringCredito += 75;
        }

        if(mesesInclusion == 0){
            scoringCredito +=75;
        }
        if(mesesInclusion <= 5 && mesesInclusion >= 1){
            scoringCredito +=10;
        }
        if(mesesInclusion <= 11 && mesesInclusion >= 6){
            scoringCredito += 10;
        }
        if(mesesInclusion == 12){
            scoringCredito += 25;
        }
        if(mesesInclusion <= 23 && mesesInclusion >= 13){
            scoringCredito += 30;
        }
        if(mesesInclusion >= 24){
            scoringCredito += 55;
        }

        if(mesesRegistros <= 12){
            scoringCredito += 12;
        }
        if(mesesRegistros >= 13 && mesesRegistros <= 23){
            scoringCredito += 35;
        }
        if(mesesRegistros >= 24 && mesesRegistros <= 47){
            scoringCredito += 60;
        }
        if(mesesRegistros >= 48){
            scoringCredito += 75;
        }

        if(numeroConsultas == 0){
            scoringCredito += 75;
        }
        if(numeroConsultas == 1){
            scoringCredito += 65;
        }
        if(numeroConsultas == 2){
            scoringCredito += 45;
        }
        if(numeroConsultas == 3){
            scoringCredito += 25;
        }
        if(numeroConsultas == 4){
            scoringCredito += 20;
        }
        if(scoringCredito >= 200){
            credito::fondoCreditos[i].setEstado("Aprobado");
        }else{
            credito::fondoCreditos[i].setEstado("Rechazado");
        }
    }
    QMessageBox::information(this,"Exitoso!","Actualice la pagina para ver los estados de los creditos.");
}
