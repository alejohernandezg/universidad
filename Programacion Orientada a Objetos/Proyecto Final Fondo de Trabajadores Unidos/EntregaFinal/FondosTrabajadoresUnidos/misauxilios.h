#ifndef MISAUXILIOS_H
#define MISAUXILIOS_H

#include <QWidget>
#include "QLabel"
#include "usuario.h"
#include "auxilio.h"
#include "qmessagebox.h"

namespace Ui {
class misAuxilios;
}

class misAuxilios : public QWidget
{
    Q_OBJECT

public:
    explicit misAuxilios(QWidget *parent = 0);
    void mostrarDatos();
    ~misAuxilios();

private:
    Ui::misAuxilios *ui;
};

#endif // MISAUXILIOS_H
