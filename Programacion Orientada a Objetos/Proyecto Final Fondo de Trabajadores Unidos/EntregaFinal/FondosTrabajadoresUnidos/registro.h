#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include "mainwindow.h"
#include "registro.h"
#include "QMessageBox"
#include "usuario.h"
#include "QValidator"
#include "QRegExp"


namespace Ui {
class Registro;
}

class Registro : public QWidget
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = 0);
    ~Registro();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Registro *ui;
};

#endif // REGISTRO_H
