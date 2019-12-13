#include "clientdialog.h"
#include "ui_clientdialog.h"

clientDialog::clientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientDialog)
{
    setAutoFillBackground(true);
    QPalette pal = this->palette();

    pal.setBrush(backgroundRole(), QPixmap(chat_pic));
    //  setPalette(pal);             //加背景
    // this->showFullScreen();

    ui->setupUi(this);
    ui->send->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->shuaxin->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;"); //按钮设成圆角
    QFont font("Comic Sans MS",13);
    ui->send->setFont(font);
    ui->shuaxin->setFont(font);
    ui->pushButton->setFont(font);
    QPalette pl = ui->output->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->output->setPalette(pl);
    pl = ui->input->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    // QShortcut *key=new QShortcut(QKeySequence(Qt::Key_Return),this);//创建一个快捷键"Key_Return"键
    //connect(key,SIGNAL(act()),this,SLOT(槽函数));//连接到指定槽函数
    ui->input->setFocusPolicy(Qt::StrongFocus);
    ui->input->setFocus();
    ui->input->installEventFilter(this);//设置完后自动调用其eventFilter函数
}

clientDialog::~clientDialog()
{
    delete ui;
}

void clientDialog::RoundRect(){                  //将窗口设为圆角
    QBitmap bmp(this->size());
    bmp.fill(this,0,0);
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawRoundedRect(bmp.rect(),20,20,Qt::AbsoluteSize);
    setMask(bmp);
}

void clientDialog::on_pushButton_clicked()
{
    string msg1 = "F" + _name + " " + _roomName;
    QString msg = QString::fromStdString(msg1);
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    tcpClient->write(str);
    emit sendsignal();
    this->close();
}


void clientDialog::on_send_clicked()
{
    QString in = ui->input ->toPlainText();
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

bool clientDialog::eventFilter(QObject *target, QEvent *event)      //回车键发送
{
    if(target == ui->input){
        if(event->type() == QEvent::KeyPress){  //回车键
             QKeyEvent *k = static_cast<QKeyEvent *>(event);
             if(k->key() == Qt::Key_Return){
                 on_send_clicked();
                 return true;
             }
        }
    }
    return QDialog::eventFilter(target,event);
}

void clientDialog::on_shuaxin_clicked()
{
    string msg1 = "U"+_roomName;
    QString msg = QString::fromStdString(msg1);
    QByteArray  str = msg.toUtf8();
    str.append('\n');
    string temp = str.toStdString();
    cout << "[out Dialog]" << temp << endl;
    tcpClient->write(str);
    //ui->chengyuan->setText(clientinfo);
}


