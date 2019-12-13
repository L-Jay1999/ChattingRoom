#include "error_nn.h"
#include "ui_error_nn.h"

error_NN::error_NN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error_NN)
{
    //this->setFixedSize(400,80);
    this->setWindowTitle("Error");
    ui->setupUi(this);
    QFont font("Comic Sans MS",15);
    ui->label->setFont(font);
}

error_NN::~error_NN()
{
    delete ui;
}
