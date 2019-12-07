#ifndef REGERROR_H
#define REGERROR_H

#include <QDialog>

namespace Ui {
class regerror;
}

class regerror : public QDialog
{
    Q_OBJECT

public:
    explicit regerror(QWidget *parent = nullptr);
    ~regerror();

private:
    Ui::regerror *ui;
};

#endif // REGERROR_H
