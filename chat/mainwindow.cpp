/*1. 删除registerin界面，注册和登录的用户名密码输入都在mainwindow内输入，出错弹出警告框。
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_clientdialog.h"

QTcpSocket *tcpClient;
string _name;
string _input_name;
string _roomName;
string _input_roomName;
QString roominfo;
QString clientinfo;

const QString button1_pic = "./source/button1.png";
const QString button2_pic = "./source/button2.png";
const QString button3_pic = "./source/button3.png";
const QString button4_pic = "./source/button4.png";
const QString main_pic = "./source/main.jpg";
const QString chat_pic = "./source/chat.png";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->label->setStyleSheet("background:transparent;border:2px solid red;");
    setAutoFillBackground(true);
    QPalette pal = this->palette();

    pal.setBrush(backgroundRole(), QPixmap(main_pic));
    setPalette(pal);                 //设置背景
    this->setStyleSheet("QMainWindow{border-radius:15px;}");
    //this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
    ui->setupUi(this);
    //设置标签字体，第一个参数是字体（微软雅黑），第二个是字体大小(单位为pt)，第三个是加粗（50代表正常）
    QFont font("Comic Sans MS",15);
    ui->lreg->setFont(font);
    ui->llog->setFont(font);
    ui->lcode->setFont(font);
    ui->luse->setFont(font);
    ui->lins->setFont(font);
    QFont nfont("Comic Sans MS",13);
    ui->exit->setFont(nfont);//设置字体

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->dengLu->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->quit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");  //按钮设成圆角

    ui->pushButton->setFlat(true);
    ui->dengLu->setFlat(true);
    ui->pushButton_3->setFlat(true);                     //按钮设成透明

    QString sheet1 = "border-image: url(" + button1_pic + ");";
    QString sheet2 = "border-image: url(" + button2_pic + ");";
    QString sheet3 = "border-image: url(" + button4_pic + ");";
    ui->pushButton->setStyleSheet(sheet1);
    ui->pushButton_3->setStyleSheet(sheet2);
    ui->dengLu->setStyleSheet(sheet3);           //设置按钮图案

    ui->userName ->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->userPassword ->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->exit ->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");

    ui->userPassword->setEchoMode(QLineEdit::Password);                     //隐藏密码
   // RoundRect();

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
    delete tcpClient;
    delete new_client;
    delete new_login;
    delete new_reg;
    delete new_ins;
    delete new_error;
    delete new_regerror;
    delete new_nn;
    delete new_no;
    delete ui;
}

void MainWindow::RoundRect(){                  //将窗口设为圆角
    QBitmap bmp(this->size());
    bmp.fill(this,0,0);
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawRoundedRect(bmp.rect(),20,20,Qt::AbsoluteSize);
    setMask(bmp);
}

void MainWindow::on_dengLu_clicked()
{
    QString msg = ui->userName->text();
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
    QString msg = ui->userName->text();
    QString msg2 = ui->userPassword->text();
    _input_name = msg.toStdString();
    string password=msg2.toStdString();
    if(_input_name == ""||password == ""){
         new_regerror=new regerror;
         new_regerror->show();
    }                                                   //判断密码是否为空
    else{
        msg = "SZ" + msg + " " + msg2;
        QByteArray  str = msg.toUtf8();
        str.append('\n');
        string temp = str.toStdString();
        cout << "[out]" << temp << endl;
        tcpClient->write(str);
    }

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
        else if(str2 == "YD\n"){
            _roomName = _input_roomName;
            this->hide();
            new_login->hide();
            new_client=new clientDialog;
            connect(new_client,SIGNAL(sendsignal()),new_login,SLOT(show()));
            new_client->show();
        }
        else if(str2[0] == '['){
            new_client->ui->output->appendPlainText(input);
        }
        else if(str2 == "NP\n"){
            new_error=new error;
            cout << "password wrong" << endl;
            new_error->show();
        }
        else if(str2 == "NO\n"){
            cout << "already online" << endl;
            new_nn=new error_NN;
            new_nn->show();
        }
        else if(str2 == "NN\n"){
            cout << "room name already" << endl;
            new_no=new error_No;
            new_no->show();
        }
        else if(str2[0] == 'U'){
            cout << "[成员输出]" << str2 << endl;  //////////////////////////////
            //new_client->ui->chengyuan->setText(QString::fromStdString((str2.substr(1))));
            clientinfo=str1;
        }
        else if(str2[0] == 'R'){
            //str2显示到room.ui上
            cout << str2 << endl;
            roominfo=str1;
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



void MainWindow::on_quit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_exit_clicked()
{
    this->close();
}
