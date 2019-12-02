#include "login.h"


extern QTcpSocket* tcpClient;
extern string _name;
extern string _input_roomName;


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(MainWindow::onSocketReadyRead()));
}

login::~login()
{
    delete ui;
}

void login::on_exit_clicked()
{
    emit sendsignal();
    this->close();

}

void login::on_enter_clicked()
{
    QString msg = ui->roomName->toPlainText();
    QString msg2 = ui->roomPassword->toPlainText();
    _input_roomName = msg.toStdString();

    msg = "SE" + msg + " " + msg2;
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out]" << temp << endl;
    tcpClient->write(str);
}

void login::on_create_clicked()
{
    QString msg = ui->roomName->toPlainText();
    QString msg2 = ui->roomPassword->toPlainText();
    _input_roomName = msg.toStdString();

    msg = "SC" + msg + " " + msg2;
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out]" << temp << endl;
    tcpClient->write(str);
}

