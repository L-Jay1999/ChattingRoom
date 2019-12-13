#include "instruction.h"
#include "ui_instruction.h"

instruction::instruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instruction)
{
    setAutoFillBackground(true);
    QPalette pal = this->palette();

    pal.setBrush(backgroundRole(), QPixmap(main_pic));
    setPalette(pal);                 //设置背景

    ui->setupUi(this);
    //RoundRect();
    QFont font("华文行楷",18);
    ui->textEdit->setFont(font);
}

instruction::~instruction()
{
    delete ui;
}

void instruction::RoundRect(){                  //将窗口设为圆角
    QBitmap bmp(this->size());
    bmp.fill(this,0,0);
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawRoundedRect(bmp.rect(),20,20,Qt::AbsoluteSize);
    setMask(bmp);
}

void instruction::on_pushButton_clicked()
{
    emit sendsignal();
    this->close();
}
