#include "ahorro.h"

Usuario ahorro::getMiUsuario()
{
    return miUsuario;
}

void ahorro::setMiUsuario(Usuario value)
{
    miUsuario = value;
}

float ahorro::getMontoAhorrado()
{
    return montoAhorrado;
}

void ahorro::setMontoAhorrado(float value)
{
    montoAhorrado = value;
}

void ahorro::addAhorro(float value)
{
    montoAhorrado = montoAhorrado + value;
}

int ahorro::getDiaAhorro()
{
    return diaAhorro;
}

void ahorro::setDiaAhorro(int value)
{
    diaAhorro = value;
}

int ahorro::getMesAhorro()
{
    return mesAhorro;
}

void ahorro::setMesAhorro(int value)
{
    mesAhorro = value;
}

int ahorro::getYearAhorro()
{
    return yearAhorro;
}

void ahorro::setYearAhorro(int value)
{
    yearAhorro = value;
}

ahorro::ahorro()
{

}

ahorro::ahorro(Usuario nuevoUsuario,int nuevoDia,int nuevoMes,int nuevoYear)
{
    miUsuario = nuevoUsuario;
    diaAhorro = nuevoDia;
    mesAhorro = nuevoMes;
    yearAhorro = nuevoYear;
}

QVector <ahorro> ahorro::fondoAhorros = QVector <ahorro>();
