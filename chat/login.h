#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "clientdialog.h"
#include "error.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    clientDialog * new_client;
    error *new_error;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_2_inputRejected();

private:
    Ui::login *ui;

signals:
    void sendsignal();
};

#endif // LOGIN_H
