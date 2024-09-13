#include "usuario.h"

QString Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(QString value)
{
    nombre = value;
}

QString Usuario::getApellido() const
{
    return apellido;
}

void Usuario::setApellido(QString value)
{
    apellido = value;
}


int Usuario::getCedula() const
{
    return cedula;
}

void Usuario::setCedula(int value)
{
    cedula = value;
}

int Usuario::getTarjetaCredito() const
{
    return tarjetaCredito;
}

void Usuario::setTarjetaCredito(int value)
{
    tarjetaCredito = value;
}

QString Usuario::getSexo() const
{
    return sexo;
}

void Usuario::setSexo(const QString &value)
{
    sexo = value;
}

QString Usuario::getDireccion() const
{
    return direccion;
}

void Usuario::setDireccion(QString value)
{
    direccion = value;
}

int Usuario::getCelular() const
{
    return celular;
}

void Usuario::setCelular(int value)
{
    celular = value;
}

QString Usuario::getNickname() const
{
    return nickname;
}

void Usuario::setNickname(QString value)
{
    nickname = value;
}

QString Usuario::getPassword() const
{
    return password;
}

void Usuario::setPassword(QString value)
{
    password = value;
}

QString Usuario::getEstadoCivil() const
{
    return estadoCivil;
}

void Usuario::setEstadoCivil(QString value)
{
    estadoCivil = value;
}

QString Usuario::getCorreo() const
{
    return correo;
}

void Usuario::setCorreo(QString value)
{
    correo = value;
}


QString Usuario::getFechaNacimiento()
{
    return fechaNacimiento;
}

void Usuario::setFechaNacimiento(QString value)
{
    fechaNacimiento = value;
}

Usuario::Usuario()
{

}

Usuario::Usuario(QString nuevoNombre, QString nuevoApellido, int nuevaCedula, int nuevaTarjeta, QString nuevoCorreo,
                 QString nuevoSexo, QString nuevoEstadoCivil, QString nuevaDireccion, int nuevoCelular,
                 QString nuevoNickname, QString nuevoPassword, QString NuevaFechaNacimiento)
{
    nombre = nuevoNombre;
    apellido = nuevoApellido;
    cedula = nuevaCedula;
    tarjetaCredito = nuevaTarjeta;
    correo = nuevoCorreo;
    sexo = nuevoSexo;
    estadoCivil = nuevoEstadoCivil;
    direccion = nuevaDireccion;
    celular = nuevoCelular;
    nickname = nuevoNickname;
    password = nuevoPassword;
    fechaNacimiento = NuevaFechaNacimiento;
}

QVector <Usuario> Usuario::personas = QVector <Usuario>();
Usuario * Usuario::usuarioActual= NULL;
