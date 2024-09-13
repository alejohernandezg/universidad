#ifndef SIMULACIONCREDITO_H
#define SIMULACIONCREDITO_H

#include <QWidget>
#include "constantes.h"
#include "QString"
#include "constantes.h"

namespace Ui {
class simulacionCredito;
}

class simulacionCredito : public QWidget
{
    Q_OBJECT

public:
    explicit simulacionCredito(QWidget *parent = 0);
    ~simulacionCredito();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::simulacionCredito *ui;
};

#endif // SIMULACIONCREDITO_H
