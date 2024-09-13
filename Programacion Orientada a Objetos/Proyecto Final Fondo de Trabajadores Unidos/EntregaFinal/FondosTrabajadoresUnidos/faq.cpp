#include "faq.h"
#include "ui_faq.h"

faq::faq(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::faq)
{
    ui->setupUi(this);
}

faq::~faq()
{
    delete ui;
}

void faq::on_pushButton_clicked()
{
    MenuUsuario *volverMenu = new(MenuUsuario);
    this->close();
    volverMenu->show();
}
