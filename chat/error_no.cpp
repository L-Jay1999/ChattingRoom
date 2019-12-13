#include "error_no.h"
#include "ui_error_no.h"

error_No::error_No(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error_No)
{
    //this->setFixedSize(400,80);
    this->setWindowTitle("Error");
    ui->setupUi(this);
    QFont font("Comic Sans MS",15);
    ui->label->setFont(font);
}

error_No::~error_No()
{
    delete ui;
}
