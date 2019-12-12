#ifndef ERROR_H
#define ERROR_H

#include <QDialog>
#include "ui_error.h"

namespace Ui {
class error;
}

class error : public QDialog
{
    Q_OBJECT

public:
    explicit error(QWidget *parent = nullptr);
    ~error();

private:
    Ui::error *ui;
};

#endif // ERROR_H
