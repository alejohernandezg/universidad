#include "auxiliousuarios.h"
#include "ui_auxiliousuarios.h"

auxilioUsuarios::auxilioUsuarios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auxilioUsuarios)
{
    ui->setupUi(this);
}

auxilioUsuarios::~auxilioUsuarios()
{
    delete ui;
}
