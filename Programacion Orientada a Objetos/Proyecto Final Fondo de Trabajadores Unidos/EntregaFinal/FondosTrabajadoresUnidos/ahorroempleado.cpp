#include "ahorroempleado.h"
#include "ui_ahorroempleado.h"

ahorroEmpleado::ahorroEmpleado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ahorroEmpleado)
{
    ui->setupUi(this);
}

void ahorroEmpleado::mostrarDatos()
{
    QString ahorrosActuales;
    int total=0;
    float monto=0;
    for(int i=0;i<ahorro::fondoAhorros.size();i++){
        total+=1;
        monto+= ahorro::fondoAhorros[i].getMontoAhorrado();
        ahorrosActuales.append("---------------------------------------------------------------------");
        ahorrosActuales.append("\n");
        ahorrosActuales.append("Nombre del solicitante:");
        ahorrosActuales.append(ahorro::fondoAhorros[i].getMiUsuario().getNombre());
        ahorrosActuales.append(" ");
        ahorrosActuales.append(ahorro::fondoAhorros[i].getMiUsuario().getApellido());
        ahorrosActuales.append("\n");
        ahorrosActuales.append("Usuario del solicitante:");
        ahorrosActuales.append(ahorro::fondoAhorros[i].getMiUsuario().getNickname());
        ahorrosActuales.append("\n");
        ahorrosActuales.append("Ultimo dia ahorrado:");
        ahorrosActuales.append(QString::number(ahorro::fondoAhorros[i].getDiaAhorro()));
        ahorrosActuales.append("/");
        ahorrosActuales.append(QString::number(ahorro::fondoAhorros[i].getMesAhorro()));
        ahorrosActuales.append("/");
        ahorrosActuales.append(QString::number(ahorro::fondoAhorros[i].getYearAhorro()));
        ahorrosActuales.append("\n");
        ahorrosActuales.append("Monto en la cuenta:");
        ahorrosActuales.append(QString::number(ahorro::fondoAhorros[i].getMontoAhorrado()));
        ahorrosActuales.append("\n");
    }

    ui->numeroCuentas->setText(QString::number(total));
    ui->montoTotal->setText(QString::number(monto));
    QLabel *ejemplo=new(QLabel);
    ejemplo->setText(ahorrosActuales);
    ui->ahorrosFondo->setWidget(ejemplo);
}

ahorroEmpleado::~ahorroEmpleado()
{
    delete ui;
}

void ahorroEmpleado::on_pushButton_clicked()
{
    MenuEmpleado * volverMenu=new(MenuEmpleado);
    volverMenu->show();
    this->close();
}
