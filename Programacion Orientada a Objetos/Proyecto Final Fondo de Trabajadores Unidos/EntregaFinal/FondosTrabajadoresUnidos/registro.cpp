#include "registro.h"
#include "ui_registro.h"


Registro::Registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registro)
{

    ui->setupUi(this);
}

Registro::~Registro()
{
    delete ui;
}

void Registro::on_pushButton_clicked()
{
    MainWindow *miMenu = new(MainWindow);
    miMenu->show();
    this->close();
}

void Registro::on_pushButton_2_clicked()
{
    QString nombre = ui->nombre->text();
    QString apellido = ui->apellido->text();
    QString cedula = ui->cedula->text();
    int tarjetaCredito = ui->tarjetaCredito->text().toInt();
    QString correo = ui->correo->text();
    QString sexo = ui->sexo->currentText();
    QString estadoCivil = ui->estadoCivil->currentText();
    QString direccion = ui->direccion->text();
    QString celular = ui->celular->text();
    QString usuario = ui->usuario->text();
    QString password = ui->password->text();
    QString nacimiento = ui->fechaNacimiento->text();

    if(nombre == NULL || apellido == NULL || cedula == NULL || correo == NULL || sexo == NULL ||
            estadoCivil == NULL || direccion == NULL || celular == NULL || usuario == NULL || password == NULL ||
            sexo == "Seleccione..." || estadoCivil == "Seleccione..."){
        QMessageBox::warning(this,"Error!","Ingrese todos los datos.");
    }else{

        int pos=0;
        bool flag = true;

        QRegExp regexNombre("^([A-Za-z\\s]+$)");
        QRegExpValidator validacionNombre(regexNombre,0);

        QRegExp regexApellido("^([A-Za-z\\s]+$)");
        QRegExpValidator validacionApellido(regexApellido,0);

        QRegExp regexCedula("\\d{10}");
        QRegExpValidator validacionCedula(regexCedula,0);

        QRegExp regexCelular("\\d{10}");
        QRegExpValidator validacionCelular(regexCelular,0);

        QRegExp regexTarjeta("\\d{16}");
        QRegExpValidator validacionTarjeta(regexTarjeta,0);

        QRegExp regexCorreo("^[A-Za-z]+$");
        QRegExpValidator validacionCorreo(regexCorreo,0);

        QRegExp regexNickname("^[.]{4,}$");
        QRegExpValidator validacionNickname(regexNickname,0);

        QRegExp regexPassword("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[$@$!%*?&])[A-Za-z\\d$@$!%*?&]{8,15}$");
        QRegExpValidator validacionPassword(regexNickname,0);



        if(validacionNombre.validate(nombre,pos) == QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Nombre incorrecto(Ingrese solo sus 2 primeros nombres).");
            flag=false;
            return;
        }

        if(validacionApellido.validate(apellido,pos) == QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Apellido incorrecto");
            flag=false;
            return;
        }

        if(validacionCedula.validate(cedula,pos) != QValidator::Acceptable){
            QMessageBox::warning(this,"Error!","Numero de cedula invalido.");
            flag=false;
            return;
        }

        if(validacionCelular.validate(celular,pos) != QValidator::Acceptable){
            QMessageBox::warning(this,"Error!","Numero de celular invalido.");
            flag=false;
            return;
        }

        if(validacionCorreo.validate(correo,pos) == QValidator::Invalid){
            QMessageBox::warning(this,"Error!","Correo invalido.");
            flag=false;
            return;
        }

        if(validacionPassword.validate(password,pos) == QValidator::Intermediate){
            QMessageBox::warning(this,"Error!","La contraseña debe contar con mas de 4 caracteres.");
            flag=false;
            return;
        }
        if(validacionNickname.validate(password,pos) == QValidator::Invalid){
            QMessageBox::warning(this,"Error!","El usuario debe contar con mas de 4 caracteres.");
            flag=false;
            return;
        }

        for(int i=0;i<Usuario::personas.size();i++){
            if(Usuario::personas[i].getNickname() == usuario ){
                QMessageBox::warning(this,"Error!","Este usuario ya existe.");
                return;
                flag=false;
            }
        }
        if(flag){
            Usuario nuevoUsuario = Usuario(nombre,apellido,cedula.toInt(),tarjetaCredito,correo,sexo,estadoCivil,direccion,celular.toInt(),usuario,password,nacimiento);
            Usuario::personas.push_back(nuevoUsuario);

            QMessageBox::information(this,"Felicidades!","Ya puede disfrutar de todos los beneficios que ofrece el fondo.");
            this->close();

            MainWindow *menuPrincipal = new(MainWindow);
            menuPrincipal->show();
        }


    }
}
