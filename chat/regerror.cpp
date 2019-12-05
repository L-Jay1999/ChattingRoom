#include "regerror.h"
#include "ui_regerror.h"

regerror::regerror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regerror)
{
    this->setFixedSize( 250,80);
    ui->setupUi(this);
    QFont font( "KaiTi",15);
    ui->warn->setFont(font);
}

regerror::~regerror()
{
    delete ui;
}
