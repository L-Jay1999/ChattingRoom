#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket>
#include <string>
#include <iostream>
#include "clientdialog.h"
#include "error.h"
#include "ui_mainwindow.h"
#include "ui_login.h"
#include "regerror.h"
using std::string;
using std::cout;
using std::endl;

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    clientDialog* new_client;
    error* new_error;
     regerror* new_regerror;

private slots:
    void on_create_clicked();

    void on_exit_clicked();

    void on_enter_clicked();

    void RoundRect();

private:
    Ui::login *ui;

signals:
    void sendsignal();
};

#endif // LOGIN_H
