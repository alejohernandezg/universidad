#ifndef AUXILIOUSUARIO_H
#define AUXILIOUSUARIO_H

#include <QWidget>
#include "QMessageBox"
#include "menuusuario.h"
#include "auxilio.h"
#include "misauxilios.h"

namespace Ui {
class auxilioUsuario;
}

class auxilioUsuario : public QWidget
{
    Q_OBJECT

public:
    explicit auxilioUsuario(QWidget *parent = 0);
    ~auxilioUsuario();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::auxilioUsuario *ui;
};

#endif // AUXILIOUSUARIO_H
