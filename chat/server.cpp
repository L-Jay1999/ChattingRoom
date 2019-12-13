#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
}

server::~server()
{
    delete ui;
}
