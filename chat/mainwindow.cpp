/*1. 删除registerin界面，注册和登录的用户名密码输入都在mainwindow内输入，出错弹出警告框。
 *
 */

#include "mainwindow.h"

QTcpSocket  *tcpClient;
string _name;
string _input_name;
string _roomName;
string _input_roomName;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->dengLu->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    tcpClient = new QTcpSocket; //创建socket变量
    connect(tcpClient, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tcpClient, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    QString     addr = "127.0.0.1";
    quint16     port = 7777;
    tcpClient->connectToHost(addr, port);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dengLu_clicked()
{
    QString msg = ui->userName->toPlainText();
    QString msg2 = ui->userPassword->toPlainText();
    _input_name = msg.toStdString();
    msg = "SD" + msg + " " + msg2;
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out]" << temp << endl;
    tcpClient->write(str);
}

void MainWindow::on_pushButton_clicked()
{
    QString msg = ui->userName->toPlainText();
    QString msg2 = ui->userPassword->toPlainText();
    _input_name = msg.toStdString();
    msg = "SZ" + msg + " " + msg2;
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out]" << temp << endl;
    tcpClient->write(str);

}

void MainWindow::on_pushButton_3_clicked()
{
    this->hide();
    new_ins=new instruction;
    connect(new_ins,SIGNAL(sendsignal()),this,SLOT(show()));
    new_ins->show();
}

void MainWindow::onSocketReadyRead() {                 //聊天 收消息
    //readyRead()信号槽函数
    if(tcpClient->canReadLine()) {
        QByteArray input = tcpClient->readLine();
        QString str1 = input;
        string str2 = str1.toStdString();
        cout << "[in]" << str2 << endl;
        if(str2 == "YL\n"){
            _name = _input_name;
            this->hide();
            new_login=new login;
            connect(new_login,SIGNAL(sendsignal()),this,SLOT(show()));
            new_login->show();

        }
        else
        if(str2 == "YD\n"){
            _roomName = _input_roomName;
            this->hide();
            new_login->hide();
            new_client=new clientDialog;
            connect(new_client,SIGNAL(sendsignal()),this,SLOT(show()));
            new_client->show();
        }
        else
        if(str2[0] == '['){
            new_client->ui->output->appendPlainText(input);
        }
        else{
            new_error=new error;
            new_error->show();
        }
    }

}


/*
void MainWindow::closeEvent(QCloseEvent *event) {
    if (tcpClient->state() == QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    event->accept();
}
*/
void MainWindow::onConnected() {
    //connected()信号槽函数
    //ui->information->appendPlainText("**已连接到服务器");
    //ui->information->appendPlainText("**peer address:" +
    //                                 tcpClient->peerAddress().toString());
    //ui->information->appendPlainText("**peer port:" +
    //                                 QString::number(tcpClient->peerPort()));
    //ui->connect->setEnabled(false);
    //ui->disconnect->setEnabled(true);
}

void MainWindow::onDisconnected() {
    //disConnected()信号槽函数
    //ui->information->appendPlainText("**已断开与服务器的连接");
    //ui->connect->setEnabled(true);
    //ui->disconnect->setEnabled(false);
}


