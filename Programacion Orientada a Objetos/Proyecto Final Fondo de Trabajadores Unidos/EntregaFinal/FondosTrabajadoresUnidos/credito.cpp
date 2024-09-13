#include "credito.h"

Usuario credito::getMiUsuario()
{
    return miUsuario;
}

void credito::setMiUsuario(Usuario value)
{
    miUsuario = value;
}

int credito::getIngresosMensuales()
{
    return ingresosMensuales;
}

void credito::setIngresosMensuales(int value)
{
    ingresosMensuales = value;
}

int credito::getIngresosFamiliares()
{
    return ingresosFamiliares;
}

void credito::setIngresosFamiliares(int value)
{
    ingresosFamiliares = value;
}

QString credito::getNombreEmpresa()
{
    return nombreEmpresa;
}

void credito::setNombreEmpresa(QString value)
{
    nombreEmpresa = value;
}

int credito::getTelefono()
{
    return telefono;
}

void credito::setTelefono(int value)
{
    telefono = value;
}

int credito::getTiempoLaborando()
{
    return tiempoLaborando;
}

void credito::setTiempoLaborando(int value)
{
    tiempoLaborando = value;
}

int credito::getTotalGastos()
{
    return totalGastos;
}

void credito::setTotalGastos(int value)
{
    totalGastos = value;
}

int credito::getValorPrestar()
{
    return valorPrestar;
}

void credito::setValorPrestar(int value)
{
    valorPrestar = value;
}

int credito::getPlazoCreditos()
{
    return plazoCreditos;
}

void credito::setPlazoCreditos(int value)
{
    plazoCreditos = value;
}

int credito::getMesesFondo()
{
    return mesesFondo;
}

void credito::setMesesFondo(int value)
{
    mesesFondo = value;
}

QString credito::getEstado()
{
    return estado;
}

void credito::setEstado(QString value)
{
    estado = value;
}

float credito::getCuotaMensual()
{
    return cuotaMensual;
}

void credito::setCuotaMensual(float value)
{
    cuotaMensual = value;
}

credito::credito()
{

}

credito::credito(Usuario nuevoUsuario, int nuevosIngresosMensuales, int nuevosIngresosFamiliares, QString nuevoNombreEmpresa,
                 int nuevoTelefono, int nuevoTiempoLaborando, int nuevoTotalGastos, int nuevoValorPrestar,
                 int nuevoPlazoCreditos, int nuevoMesesFondo)
{
    miUsuario = nuevoUsuario;
    ingresosMensuales = nuevosIngresosMensuales;
    ingresosFamiliares = nuevosIngresosFamiliares;
    nombreEmpresa = nuevoNombreEmpresa;
    telefono = nuevoTelefono;
    tiempoLaborando = nuevoTiempoLaborando;
    totalGastos = nuevoTotalGastos;
    valorPrestar = nuevoValorPrestar;
    plazoCreditos = nuevoPlazoCreditos;
    mesesFondo = nuevoMesesFondo;
    estado = "Espera";
    cuotaMensual = (nuevoValorPrestar/nuevoPlazoCreditos);
    float adicionales = (cuotaMensual * constantes::misConstantes->getSeguroVida()/100)+constantes::misConstantes->getPagoAdministracion()+constantes::misConstantes->getUsoPlataforma();
    float masIva= adicionales*(constantes::misConstantes->getIva()/100);
    cuotaMensual = cuotaMensual +(cuotaMensual *constantes::misConstantes->getTasaInteres()/100)+adicionales+masIva;
}

QVector <credito> credito::fondoCreditos = QVector <credito>();
