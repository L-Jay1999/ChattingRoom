﻿#ifndef ROOM_H
#define ROOM_H

#include <QDialog>
#include <string>
#include <iostream>
#include "const.h"

using std::cout;
using std::endl;

namespace Ui {
class room;
}

class room : public QDialog
{
    Q_OBJECT

public:
    explicit room(QWidget *parent = nullptr);
    ~room();

private:
    Ui::room *ui;

};

#endif // ROOM_H
