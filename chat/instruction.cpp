#include "instruction.h"


instruction::instruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instruction)
{
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("main.jpg"));
    setPalette(pal);                 //设置背景
    ui->setupUi(this);
}

instruction::~instruction()
{
    delete ui;
}

void instruction::on_pushButton_clicked()
{
    emit sendsignal();
    this->close();
}
