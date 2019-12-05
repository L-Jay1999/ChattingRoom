#include "login.h"


extern QTcpSocket* tcpClient;
extern string _name;
extern string _input_roomName;


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("G:/back/main.jpg"));
    setPalette(pal);             //加背景
   // this->showFullScreen();
    ui->setupUi(this);

    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->create->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->enter->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");      //按钮设成圆角
    ui->pushButton->setFlat(true);
    ui->create->setFlat(true);
    ui->enter->setFlat(true);                     //按钮设成透明
    ui->pushButton->setStyleSheet(tr("border-image: url(G:/back/button1.png);"));
    ui->create->setStyleSheet(tr("border-image: url(G:/back/button2.png);"));
    ui->enter->setStyleSheet(tr("border-image: url(G:/back/button4.png);"));           //设置按钮图案

    ui->roomPassword->setEchoMode(QLineEdit::Password);
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
    QString msg2 = ui->roomPassword->text();
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
    QString msg2 = ui->roomPassword->text();
    _input_roomName = msg.toStdString();
    string password=msg2.toStdString();
    if(_input_roomName==""||password==""){
         new_regerror=new   regerror;
         new_regerror->show();
    }                                                   //判断密码是否为空
    else{
        msg = "SC" + msg + " " + msg2;
        QByteArray  str = msg.toUtf8();
        str.append('\n');
        string temp = str.toStdString();
        cout << "[out]" << temp << endl;
        tcpClient->write(str);}
}

