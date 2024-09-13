#ifndef USUARIO_H
#define USUARIO_H

#include <QString>
#include <QVector>

class Usuario
{
private:
    QString nombre;
    QString apellido;
    QString fechaNacimiento;
    int cedula;
    int tarjetaCredito;
    QString correo;
    QString sexo;
    QString estadoCivil;
    QString direccion;
    int celular;
    QString nickname;
    QString password;
public:
    Usuario();
    Usuario(QString nuevoNombre,QString nuevoApellido,int nuevaCedula,int nuevaTarjeta,
            QString nuevoCorreo,QString nuevoSexo,QString nuevoEstadoCivil, QString nuevaDireccion,
            int nuevoCelular, QString nuevoNickname,QString nuevoPassword, QString);

   QString getNombre() const;
    void setNombre(QString value);

    QString getApellido() const;
    void setApellido(QString value);

    int getCedula() const;
    void setCedula(int value);

    int getTarjetaCredito() const;
    void setTarjetaCredito(int value);

    QString getSexo() const;
    void setSexo(const QString &value);

    QString getDireccion() const;
    void setDireccion(QString value);

    int getCelular() const;
    void setCelular(int value);

    QString getNickname() const;
    void setNickname(QString value);

    QString getPassword() const;
    void setPassword(QString value);

    QString getEstadoCivil() const;
    void setEstadoCivil(QString value);

    QString getCorreo() const;
    void setCorreo(QString value);

    QString getFechaNacimiento();
    void setFechaNacimiento(QString value);

    static QVector<Usuario>personas;
    static Usuario *usuarioActual;
};



#endif // USUARIO_H
