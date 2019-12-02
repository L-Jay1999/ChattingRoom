#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDialog>
#include <string>
#include <iostream>
#include "clientdialog.h"
#include "login.h"
#include "registerin.h"
#include "instruction.h"
#include "error.h"
#include "ui_mainwindow.h"
#include "ui_clientdialog.h"

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
    clientDialog* new_client;
    login* new_login;
    registerin* new_reg;
    instruction* new_ins;
    error* new_error;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

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
    //发送消息
    //void on_send_clicked();
    void on_dengLu_clicked();
};

#endif // MAINWINDOW_H
