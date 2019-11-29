#include "mainwindow.h"
#include  <QDialog>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> pushButton ->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit_2->text()=="wrong"){
        new_error=new error;
        new_error->show();
    }

    else{
      this->hide();
       new_login=new login;
       connect(new_login,SIGNAL(sendsignal()),this,SLOT(show()));
       new_login->show();}
}

void MainWindow::on_pushButton_clicked()
{
       this->hide();
       new_reg=new registerin;
       connect(new_reg,SIGNAL(sendsignal()),this,SLOT(show()));
       new_reg->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    this->hide();
    new_ins=new instruction;
    connect(new_ins,SIGNAL(sendsignal()),this,SLOT(show()));
    new_ins->show();
}
