#include "mainwindow.h"

#include <QApplication>
#include<QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // QGridLayout* p=new  QGridLayout;
     //QPushButton *  pushButton=new  QPushButton ("new");
   // p->addWidget(pushButton,0,0,2,1);  //把按钮pb添加到第0行0列，该按钮占据1行和1列单元格。
    //w.setLayout(p);
    w.show();
    return a.exec();
}
