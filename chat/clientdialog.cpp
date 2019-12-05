#include "clientdialog.h"
#include <QShortcut>
#include<QKeyEvent>

extern string _roomName;
extern string _name;
extern QTcpSocket  *tcpClient;

clientDialog::clientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientDialog)
{
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("D:/source/chat.png"));
    setPalette(pal);             //加背景
   // this->showFullScreen();
     this->setFixedSize( 800,700);
      ui->setupUi(this);
    QPalette pl = ui->output->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->output->setPalette(pl);
   pl = ui->input->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->input->setPalette(pl);        //对话框透明
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

void clientDialog::on_pushButton_clicked()
{
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

bool clientDialog::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->input)
    {
        if(event->type() == QEvent::KeyPress)//回车键
        {
             QKeyEvent *k = static_cast<QKeyEvent *>(event);
             if(k->key() == Qt::Key_Return)
             {
                 on_send_clicked();
                 return true;
             }
        }
    }
    return QDialog::eventFilter(target,event);
}


