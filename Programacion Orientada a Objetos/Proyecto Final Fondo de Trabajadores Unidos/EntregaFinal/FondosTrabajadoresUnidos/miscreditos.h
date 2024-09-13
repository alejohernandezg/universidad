#ifndef MISCREDITOS_H
#define MISCREDITOS_H

#include <QWidget>
#include "QLabel"
#include "usuario.h"
#include "credito.h"
#include "qmessagebox.h"




namespace Ui {
class misCreditos;
}

class misCreditos : public QWidget
{
    Q_OBJECT

public:
    explicit misCreditos(QWidget *parent = 0);
    void mostrarDatos();
    ~misCreditos();

private:
    Ui::misCreditos *ui;
};

#endif // MISCREDITOS_H
