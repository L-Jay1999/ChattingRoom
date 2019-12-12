#ifndef ERROR_NN_H
#define ERROR_NN_H

#include <QDialog>

namespace Ui {
class error_NN;
}

class error_NN : public QDialog
{
    Q_OBJECT

public:
    explicit error_NN(QWidget *parent = nullptr);
    ~error_NN();

private:
    Ui::error_NN *ui;
};

#endif // ERROR_NN_H
