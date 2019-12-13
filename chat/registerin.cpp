#include "registerin.h"
#include "ui_registerin.h"

registerin::registerin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerin)
{
    ui->setupUi(this);
}

registerin::~registerin()
{
    delete ui;
}

void registerin::on_pushButton_clicked()
{
    emit sendsignal();
    this->close();
}

void registerin::on_pushButton_2_clicked()
{
    emit sendsignal();
    this->close();
}
