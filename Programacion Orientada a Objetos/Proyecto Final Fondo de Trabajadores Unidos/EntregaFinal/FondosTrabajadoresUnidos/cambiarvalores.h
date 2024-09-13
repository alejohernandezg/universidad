#ifndef CAMBIARVALORES_H
#define CAMBIARVALORES_H

#include <QWidget>
#include "constantes.h"

namespace Ui {
class cambiarValores;
}

class cambiarValores : public QWidget
{
    Q_OBJECT

public:
    explicit cambiarValores(QWidget *parent = 0);
    ~cambiarValores();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cambiarValores *ui;
};

#endif // CAMBIARVALORES_H
