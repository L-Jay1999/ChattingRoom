#include "room.h"
#include "ui_room.h"

room::room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room)
{
    ui->setupUi(this);
    //roominfo="sfs";
    cout << "room:"<< roominfo.toStdString() << endl;
    ui->info->setText(roominfo);
}

room::~room()
{
    delete ui;
}


