#ifndef ERROR_NO_H
#define ERROR_NO_H

#include <QDialog>

namespace Ui {
class error_No;
}

class error_No : public QDialog
{
    Q_OBJECT

public:
    explicit error_No(QWidget *parent = nullptr);
    ~error_No();

private:
    Ui::error_No *ui;
};

#endif // ERROR_NO_H
