#ifndef AUXILIOUSUARIOS_H
#define AUXILIOUSUARIOS_H

#include <QWidget>

namespace Ui {
class auxilioUsuarios;
}

class auxilioUsuarios : public QWidget
{
    Q_OBJECT

public:
    explicit auxilioUsuarios(QWidget *parent = 0);
    ~auxilioUsuarios();

private:
    Ui::auxilioUsuarios *ui;
};

#endif // AUXILIOUSUARIOS_H
