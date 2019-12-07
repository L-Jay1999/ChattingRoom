#include "error.h"


error::error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error)
{
    this->setFixedSize( 250,80);
    ui->setupUi(this);
    QFont font( "KaiTi",15);
    ui->warn->setFont(font);
}

error::~error()
{
    delete ui;
}
