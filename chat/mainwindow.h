#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QFont>
#include <QBitmap>
#include <QPainter>
#include <string>
#include <iostream>

#include "clientdialog.h"
#include "registerin.h"
#include "instruction.h"
#include "error.h"
#include "regerror.h"
#include "error_nn.h"
#include "error_no.h"
#include "login.h"
#include "const.h"

using std::string;
using std::cout;
using std::endl;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*void  send_room(QString data);
    void  send_client(QString data);*/
    clientDialog* new_client;
    login* new_login;
    registerin* new_reg;
    instruction* new_ins;
    error* new_error;
    regerror* new_regerror;
    error_NN*  new_nn;
    error_No* new_no;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void RoundRect();
private:
    Ui::MainWindow *ui;

private:
    //QTcpSocket  *tcpClient;//客户端
protected:
    //客户端关闭事件
    //void  closeEvent(QCloseEvent *event);
private slots:
    //当连接成功时
    void  onConnected();
    //断开连接
    void  onDisconnected();
    //服务端发来了信息
    void  onSocketReadyRead();

    //点击连接
    //void on_connect_clicked();
    //断开连接
    //void on_disconnect_clicked();
    void on_quit_clicked();
    //发送消息
    //void on_send_clicked();
    void on_dengLu_clicked();
    void on_pushButton_2_clicked();

    void on_exit_clicked();
};

#endif // MAINWINDOW_H
