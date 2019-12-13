#include "regerror.h"
#include "ui_regerror.h"

regerror::regerror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regerror)
{
    this->setFixedSize(500,80);
    ui->setupUi(this);
    QFont font("Comic Sans MS",15);
    ui->warn->setFont(font);
}

regerror::~regerror()
{
    delete ui;
}
