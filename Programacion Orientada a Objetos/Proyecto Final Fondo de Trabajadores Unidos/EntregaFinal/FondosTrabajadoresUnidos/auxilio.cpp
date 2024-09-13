#include "auxilio.h"

Usuario auxilio::getMiUsuario()
{
    return miUsuario;
}

void auxilio::setMiUsuario(Usuario value)
{
    miUsuario = value;
}

QString auxilio::getTipoAuxilio()
{
    return tipoAuxilio;
}

void auxilio::setTipoAuxilio(QString value)
{
    tipoAuxilio = value;
}


QString auxilio::getEstado()
{
    return estado;
}

void auxilio::setEstado(QString value)
{
    estado = value;
}

int auxilio::getTotalPago()
{
    return totalPago;
}

void auxilio::setTotalPago(int value)
{
    totalPago = value;
}

auxilio::auxilio()
{
    
}

auxilio::auxilio(Usuario nuevoUsuario, QString nuevoTipoAuxilio,int nuevoTotal)
{
    miUsuario = nuevoUsuario;
    tipoAuxilio = nuevoTipoAuxilio;
    totalPago = nuevoTotal;
}

QVector <auxilio> auxilio::fondoAuxilios = QVector <auxilio>();
