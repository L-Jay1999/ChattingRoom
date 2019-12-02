#include "error.h"


error::error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error)
{
    ui->setupUi(this);
}

error::~error()
{
    delete ui;
}
