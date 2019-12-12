#include "room.h"
#include "ui_room.h"

extern QString roominfo;

room::room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room)
{
    ui->setupUi(this);
  //  roominfo="sfs";
    ui->info->setText(roominfo);
}

room::~room()
{
    delete ui;
}


