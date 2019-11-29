#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    emit sendsignal();
    this->close();
}

void login::on_pushButton_clicked()
{
    if(ui->lineEdit_2->text()=="wrong"){
        new_error=new error;
        new_error->show();
    }
    else{
        this->hide();
        new_client=new clientDialog;
        connect(new_client,SIGNAL(sendsignal()),this,SLOT(show()));
        new_client->show();}
}


