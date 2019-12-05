/*1. 删除registerin界面，注册和登录的用户名密码输入都在mainwindow内输入，出错弹出警告框。
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
//添加头文件
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QFont>

QTcpSocket  *tcpClient;
string _name;
string _input_name;
string _roomName;
string _input_roomName;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("G:/back/main.jpg"));
    setPalette(pal);                 //设置背景

    ui->setupUi(this);
    //设置标签字体，第一个参数是字体（微软雅黑），第二个是字体大小(单位为pt)，第三个是加粗（50代表正常）
    QFont font( "Comic Sans MS",20);
    ui->lreg->setFont(font);
    ui->llog->setFont(font);
    ui->lcode->setFont(font);
    ui->luse->setFont(font);
    ui->lins->setFont(font);      //设置字体

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->dengLu->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");      //按钮设成圆角
    ui->pushButton->setFlat(true);
    ui->dengLu->setFlat(true);
    ui->pushButton_3->setFlat(true);                     //按钮设成透明
    ui->pushButton->setStyleSheet(tr("background-image: url(G:/back/button1.png);"));
    ui->pushButton_3->setStyleSheet(tr("background-image: url(G:/back/button2.png);"));
    ui->dengLu->setStyleSheet(tr("background-image: url(G:/back/button4.png);"));           //设置按钮图案

    ui->userPassword->setEchoMode(QLineEdit::Password);
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
    QString msg2 = ui->userPassword->text();
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
    QString msg2 = ui->userPassword->text();
    _input_name = msg.toStdString();
    string password=msg2.toStdString();
    if(_input_name==""||password==""){
         new_regerror=new   regerror;
         new_regerror->show();
    }                                                   //判断密码是否为空
    else{
        msg = "SZ" + msg + " " + msg2;
        QByteArray  str = msg.toUtf8();
        str.append('\n');
        string temp = str.toStdString();
        cout << "[out]" << temp << endl;
        tcpClient->write(str);}

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
            connect(new_client,SIGNAL(sendsignal()),new_login,SLOT(show()));
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


