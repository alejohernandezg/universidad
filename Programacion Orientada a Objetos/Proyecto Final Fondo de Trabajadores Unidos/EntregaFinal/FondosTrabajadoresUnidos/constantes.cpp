#include "constantes.h"

float constantes::getSalarioMinimoVigente()
{
    return salarioMinimoVigente;
}

void constantes::setSalarioMinimoVigente(float value)
{
    salarioMinimoVigente = value;
}

float constantes::getTasaInteres()
{
    return tasaInteres;
}

void constantes::setTasaInteres(float value)
{
    tasaInteres = value;
}

int constantes::getMaximoAuxilio()
{
    return maximoAuxilio;
}

void constantes::setMaximoAuxilio(int value)
{
    maximoAuxilio = value;
}

int constantes::getScoring()
{
    return scoring;
}

void constantes::setScoring(int value)
{
    scoring = value;
}

constantes::constantes()
{
    
}

float constantes::getSeguroVida()
{
    return seguroVida;
}

void constantes::setSeguroVida(float value)
{
    seguroVida = value;
}

float constantes::getUsoPlataforma()
{
    return usoPlataforma;
}

void constantes::setUsoPlataforma(float value)
{
    usoPlataforma = value;
}

float constantes::getIva()
{
    return iva;
}

void constantes::setIva(float value)
{
    iva = value;
}

float constantes::getPagoAdministracion()
{
    return pagoAdministracion;
}

void constantes::setPagoAdministracion(float value)
{
    pagoAdministracion = value;
}

constantes * constantes::misConstantes= new(constantes);
