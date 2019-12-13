#include "error.h"
#include "ui_error.h"

error::error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error)
{
    //this->setFixedSize(400,80);
    this->setWindowTitle("Error");
    ui->setupUi(this);
    QFont font("Comic Sans MS",15);
    ui->warn->setFont(font);
}

error::~error()
{
    delete ui;
}
