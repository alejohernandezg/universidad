#ifndef AHORROUSUARIO_H
#define AHORROUSUARIO_H

#include <QWidget>
#include "menuusuario.h"
#include <QDateEdit>
#include "ahorro.h"
#include "misahorros.h"
#include "QDebug"
#include "QRegExp"

namespace Ui {
class AhorroUsuario;
}

class AhorroUsuario : public QWidget
{
    Q_OBJECT

public:
    explicit AhorroUsuario(QWidget *parent = 0);
    ~AhorroUsuario();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AhorroUsuario *ui;
};

#endif // AHORROUSUARIO_H
