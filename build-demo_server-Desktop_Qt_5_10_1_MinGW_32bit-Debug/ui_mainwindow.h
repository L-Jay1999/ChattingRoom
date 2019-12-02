/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *listen;
    QLineEdit *server_ip;
    QLabel *label_2;
    QLineEdit *server_port;
    QLabel *label;
    QPushButton *shutdown;
    QGridLayout *gridLayout;
    QPlainTextEdit *message;
    QPushButton *send;
    QCheckBox *checkBox;
    QPlainTextEdit *information;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(507, 390);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listen = new QPushButton(centralWidget);
        listen->setObjectName(QStringLiteral("listen"));

        gridLayout_2->addWidget(listen, 0, 5, 1, 1);

        server_ip = new QLineEdit(centralWidget);
        server_ip->setObjectName(QStringLiteral("server_ip"));

        gridLayout_2->addWidget(server_ip, 0, 1, 1, 2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);

        server_port = new QLineEdit(centralWidget);
        server_port->setObjectName(QStringLiteral("server_port"));

        gridLayout_2->addWidget(server_port, 0, 4, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        shutdown = new QPushButton(centralWidget);
        shutdown->setObjectName(QStringLiteral("shutdown"));

        gridLayout_2->addWidget(shutdown, 0, 6, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        message = new QPlainTextEdit(centralWidget);
        message->setObjectName(QStringLiteral("message"));

        gridLayout->addWidget(message, 0, 0, 3, 1);

        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));

        gridLayout->addWidget(send, 0, 1, 1, 1);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 1, 2, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        information = new QPlainTextEdit(centralWidget);
        information->setObjectName(QStringLiteral("information"));

        gridLayout_3->addWidget(information, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        listen->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        server_ip->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\233\221\345\220\254\347\253\257\345\217\243\345\217\267", nullptr));
        server_port->setText(QApplication::translate("MainWindow", "7777", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\234\254\346\234\272ip", nullptr));
        shutdown->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
        send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\275\254\345\217\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
