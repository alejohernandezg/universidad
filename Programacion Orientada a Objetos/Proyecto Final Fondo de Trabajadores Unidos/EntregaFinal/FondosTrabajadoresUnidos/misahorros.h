#ifndef MISAHORROS_H
#define MISAHORROS_H

#include <QWidget>
#include "ahorro.h"
#include <QLabel>

namespace Ui {
class misAhorros;
}

class misAhorros : public QWidget
{
    Q_OBJECT

public:
    explicit misAhorros(QWidget *parent = 0);
    void mostrarDatos();
    ~misAhorros();

private:
    Ui::misAhorros *ui;
};

#endif // MISAHORROS_H
