#ifndef CONSTANTES_H
#define CONSTANTES_H


class constantes
{
    float salarioMinimoVigente = 737717;
    float pagoAdministracion = 20000;
    float seguroVida = 5;
    float usoPlataforma = 15000;
    float iva=16;
    float tasaInteres= 9;
    int scoring=200;
    int maximoAuxilio= 50000000;
public:

    constantes();

    float getPagoAdministracion();
    void setPagoAdministracion(float value);

    float getSeguroVida();
    void setSeguroVida(float value);

    float getUsoPlataforma();
    void setUsoPlataforma(float value);

    float getIva();
    void setIva(float value);

    static constantes *misConstantes;

    float getSalarioMinimoVigente();
    void setSalarioMinimoVigente(float value);
    float getTasaInteres();
    void setTasaInteres(float value);
    int getMaximoAuxilio();
    void setMaximoAuxilio(int value);
    int getScoring() ;
    void setScoring(int value);
};

#endif // CONSTANTES_H
