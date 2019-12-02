#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket>
#include <string>
#include <iostream>
#include "ui_clientdialog.h"

using std::string;
using std::cout;
using std::endl;

namespace Ui {
class clientDialog;
}

class clientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit clientDialog(QWidget *parent = nullptr);
    ~clientDialog();

private slots:
    void on_pushButton_clicked();

    void on_send_clicked();

public:
    Ui::clientDialog *ui;

signals:
    void sendsignal();
};

#endif // CLIENTDIALOG_H
