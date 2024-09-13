#ifndef AUXILIO_H
#define AUXILIO_H
#include "usuario.h"

class auxilio
{
    Usuario miUsuario;
    QString tipoAuxilio; //Solo puede tener 2 tipos "Calamidad domestica" o "Educativo"
    int totalPago;
    QString estado; // Solo pueden tener 3 estados, "Espera", "Rechazado","Aprobado"
public:
    auxilio();
    auxilio(Usuario nuevoUsuario,QString nuevoTipoAuxilio,int totalPago);
    Usuario getMiUsuario();
    void setMiUsuario(Usuario value);

    QString getTipoAuxilio();
    void setTipoAuxilio(QString value);

    QString getEstado();
    void setEstado(QString value);

    static QVector<auxilio>fondoAuxilios;

    int getTotalPago();
    void setTotalPago(int value);
};

#endif // AUXILIO_H
