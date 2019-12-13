#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap(main_pic));
    setPalette(pal);             //加背景
    //this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
    ui->setupUi(this);

    QFont font("Comic Sans MS",15);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->label_4->setFont(font);
    ui->label_5->setFont(font);
    QFont nfont("Comic Sans MS",13);
    ui->exit->setFont(nfont);

    ui->exit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->create->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->enter->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");      //按钮设成圆角
    ui->pushButton->setFlat(true);
    ui->create->setFlat(true);
    ui->enter->setFlat(true);                     //按钮设成透明

    QString sheet1 = "border-image: url(" + button1_pic + ");";
    QString sheet2 = "border-image: url(" + button2_pic + ");";
    QString sheet3 = "border-image: url(" + button4_pic + ");";
    ui->pushButton->setStyleSheet(sheet1);
    ui->create->setStyleSheet(sheet2);
    ui->enter->setStyleSheet(sheet3);           //设置按钮图案

    ui->roomPassword->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->roomName->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px"); //设置显示框

    ui->roomPassword->setEchoMode(QLineEdit::Password);         //密码显示
    //RoundRect();
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(MainWindow::onSocketReadyRead()));
}

login::~login()
{
    delete ui;
}

bool check1(QString test){
    for(auto i = test.begin(); i != test.end(); ++ i){
        if((*i>='0'&&*i<='9')||(*i>='a'&&*i<='z')||(*i>='A'&&*i<='Z'))
            ;
        else
            return false;
    }
    return true;
}

void login::RoundRect(){                  //将窗口设为圆角
    QBitmap bmp(this->size());
    bmp.fill(this,0,0);
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawRoundedRect(bmp.rect(),20,20,Qt::AbsoluteSize);
    setMask(bmp);
}

void login::on_exit_clicked()
{
    QString msg = QString::fromStdString(_name);
    msg = "D" + msg;
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out]" << temp << endl;
    tcpClient->write(str);
    emit sendsignal();
    this->close();

}

void login::on_enter_clicked()
{
    QString msg = ui->roomName->text();
    QString msg2 = ui->roomPassword->text();
    _input_roomName = msg.toStdString();
    QString test = msg + msg2;
    if(check1(test)==false){
        new_regerror=new   regerror;
        new_regerror->show();
    }
    else{
        msg = "SE" + QString::fromStdString(_name) + " " + msg + " " + msg2;
        QByteArray  str = msg.toUtf8();
        str.append('\n');
        string temp = str.toStdString();
        cout << "[out]" << temp << endl;
        tcpClient->write(str);
    }
}

void login::on_create_clicked()
{
    QString msg = ui->roomName->text();
    QString msg2 = ui->roomPassword->text();
    _input_roomName = msg.toStdString();
    string password=msg2.toStdString();
    QString test = msg + msg2;
    if(check1(test)==false){
        new_regerror=new   regerror;
        new_regerror->show();
    }                                         //判断密码是否为空
    else{
        msg = "SC" + QString::fromStdString(_name) + " " + msg + " " + msg2;
        QByteArray  str = msg.toUtf8();
        str.append('\n');
        string temp = str.toStdString();
        cout << "[out]" << temp << endl;
        tcpClient->write(str);
    }

}


void login::on_pushButton_clicked()
{
    QString msg;
    msg = "R";
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out]" << temp << endl;
    tcpClient->write(str);
}
