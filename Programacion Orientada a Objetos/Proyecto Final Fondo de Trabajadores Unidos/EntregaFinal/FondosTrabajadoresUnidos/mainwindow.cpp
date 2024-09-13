#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Usuario usuario1= Usuario("Alejandro","Hernandez",1197511509,11111,"alejandro202008@hotmail.com","Hombre","Soltero","Cra 123 # 1-2",3143918429,"hola","1234","20/08/1997");
    Usuario::personas.push_back(usuario1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user = ui->Usuario->text();
    QString contra = ui->Pass->text();

    //Valida de que el usuario haya escrito en ambos campos
    if(user == NULL || contra== NULL){
        QMessageBox::warning(this,"Error!","Ingrese un Usuario  y una contraseña.");
        return;
    }

    //Mira el empleado del fondo que quiere ingresar
    if(user == "alejo" && contra== "1234")
    {
        MenuEmpleado *miMenuEmpleado = new(MenuEmpleado);
        miMenuEmpleado->show();
        this->close();
    }else{
        if(Usuario::personas.isEmpty())
        {
            QMessageBox::warning(this,"Error!","Ningun usuario registrado.");
            return;
        }

        for(int i=0;i<Usuario::personas.size();i++)
        {
            if(Usuario::personas[i].getNickname()==user && Usuario::personas[i].getPassword()==contra)
            {
                Usuario::usuarioActual = &(Usuario::personas[i]);
                MenuUsuario *miMenuUsuario = new(MenuUsuario);
                miMenuUsuario->show();
                this->close();
                return;
            }
        }
        QMessageBox::warning(this,"Error!","Usuario y/o contraseña incorrectos");

    }
}


void MainWindow::on_pushButton_2_clicked()
{
    Registro *nuevoRegistro = new(Registro);
    nuevoRegistro->show();
    this->close();
}
