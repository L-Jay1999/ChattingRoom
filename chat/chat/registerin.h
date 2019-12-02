#ifndef REGISTERIN_H
#define REGISTERIN_H

#include <QDialog>

namespace Ui {
class registerin;
}

class registerin : public QDialog
{
    Q_OBJECT

public:
    explicit registerin(QWidget *parent = nullptr);
    ~registerin();

private:
    Ui::registerin *ui;

signals:
    void sendsignal();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // REGISTERIN_H
