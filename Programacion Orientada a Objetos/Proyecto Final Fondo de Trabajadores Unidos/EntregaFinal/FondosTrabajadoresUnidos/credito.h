#ifndef CREDITO_H
#define CREDITO_H
#include "usuario.h"
#include "constantes.h"

class credito
{
private:
    Usuario miUsuario;
    int ingresosMensuales;
    int ingresosFamiliares;
    QString nombreEmpresa;
    int telefono;
    int tiempoLaborando;
    int totalGastos;
    int valorPrestar;
    int plazoCreditos;
    int mesesFondo;
    float cuotaMensual;
    QString estado; // Solo pueden tener 3 estados, "Espera", "Rechazado","Aprobado"
public:
    credito();
    credito(Usuario nuevoUsuario,int nuevosIngresosMensuales,int nuevosIngresosFamiliares,QString nuevoNombreEmpresa,int nuevoTelefono,
            int nuevoTiempoLaborando, int nuevoTotalGastos,int nuevoValorPrestar, int nuevoPlazoCreditos,int nuevoMesesFondo);

    Usuario getMiUsuario();
    void setMiUsuario(Usuario value);

    int getIngresosMensuales();
    void setIngresosMensuales(int value);

    int getIngresosFamiliares();
    void setIngresosFamiliares(int value);

    QString getNombreEmpresa();
    void setNombreEmpresa(QString value);

    int getTelefono();
    void setTelefono(int value);

    int getTiempoLaborando();
    void setTiempoLaborando(int value);

    int getTotalGastos();
    void setTotalGastos(int value);

    int getValorPrestar();
    void setValorPrestar(int value);

    int getPlazoCreditos();
    void setPlazoCreditos(int value);

    int getMesesFondo();
    void setMesesFondo(int value);

    QString getEstado();
    void setEstado(QString value);

    static QVector<credito>fondoCreditos;
    float getCuotaMensual();
    void setCuotaMensual(float value);
};

#endif // CREDITO_H
