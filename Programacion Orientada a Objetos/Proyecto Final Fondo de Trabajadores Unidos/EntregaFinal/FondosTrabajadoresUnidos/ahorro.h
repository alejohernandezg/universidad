#ifndef AHORRO_H
#define AHORRO_H
#include "usuario.h"
#include "QDateEdit"


class ahorro
{
private:
    Usuario miUsuario;
    float montoAhorrado;
    int diaAhorro;
    int mesAhorro;
    int yearAhorro;
public:
    ahorro();
    ahorro(Usuario nuevoUsuario,int dia,int mes,int year);
    Usuario getMiUsuario();
    void setMiUsuario(Usuario value);

    float getMontoAhorrado();
    void setMontoAhorrado(float value);

    void addAhorro(float value);

    static QVector<ahorro>fondoAhorros;
    int getDiaAhorro();
    void setDiaAhorro(int value);
    int getMesAhorro();
    void setMesAhorro(int value);
    int getYearAhorro();
    void setYearAhorro(int value);
};

#endif // AHORRO_H
