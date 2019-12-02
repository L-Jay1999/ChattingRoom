#include "clientdialog.h"
#include "ui_clientdialog.h"
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket>
#include <string>
#include <iostream>
using namespace std;


extern string _roomName;
extern string _name;
extern QTcpSocket  *tcpClient;



clientDialog::clientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientDialog)
{
    ui->setupUi(this);
}

clientDialog::~clientDialog()
{
    delete ui;
}

void clientDialog::on_pushButton_clicked()
{
    emit sendsignal();
    this->close();
}

void clientDialog::on_send_clicked()
{
    QString in = ui->input->toPlainText();
    ui->input->clear();
    ui->input->setFocus();
    string msg1 = "M" + _name + " " + _roomName + " " + in.toStdString();
    QString msg = QString::fromStdString(msg1);
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out Dialog]" << temp << endl;
    tcpClient->write(str);
}
