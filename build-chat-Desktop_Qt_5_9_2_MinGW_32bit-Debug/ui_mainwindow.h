/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton;
    QPushButton *dengLu;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lreg;
    QLabel *llog;
    QLabel *lins;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *luse;
    QPlainTextEdit *userName;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lcode;
    QLineEdit *userPassword;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1583, 1000);
        MainWindow->setMinimumSize(QSize(500, 1000));
        MainWindow->setBaseSize(QSize(500, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 0, 1372, 714));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_8 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 0, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 7, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 1, 11, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(250, 280));

        gridLayout->addWidget(pushButton, 2, 2, 2, 2);

        dengLu = new QPushButton(widget);
        dengLu->setObjectName(QStringLiteral("dengLu"));
        dengLu->setMinimumSize(QSize(270, 280));
        dengLu->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(dengLu, 2, 6, 2, 3);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(250, 280));

        gridLayout->addWidget(pushButton_3, 2, 10, 2, 2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 13, 1, 1);

        horizontalSpacer = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 9, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 12, 1, 1);

        lreg = new QLabel(widget);
        lreg->setObjectName(QStringLiteral("lreg"));

        gridLayout->addWidget(lreg, 4, 2, 1, 1);

        llog = new QLabel(widget);
        llog->setObjectName(QStringLiteral("llog"));

        gridLayout->addWidget(llog, 4, 7, 1, 1);

        lins = new QLabel(widget);
        lins->setObjectName(QStringLiteral("lins"));

        gridLayout->addWidget(lins, 4, 10, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 5, 7, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 5, 11, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 6, 4, 1, 1);

        luse = new QLabel(widget);
        luse->setObjectName(QStringLiteral("luse"));

        gridLayout->addWidget(luse, 6, 5, 1, 1);

        userName = new QPlainTextEdit(widget);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setMaximumSize(QSize(200, 25));

        gridLayout->addWidget(userName, 6, 6, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 6, 8, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_7, 7, 7, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 8, 4, 1, 1);

        lcode = new QLabel(widget);
        lcode->setObjectName(QStringLiteral("lcode"));

        gridLayout->addWidget(lcode, 8, 5, 1, 1);

        userPassword = new QLineEdit(widget);
        userPassword->setObjectName(QStringLiteral("userPassword"));

        gridLayout->addWidget(userPassword, 8, 6, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 8, 8, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_10, 8, 10, 2, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 9, 7, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_11, 10, 6, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1583, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QString());
        dengLu->setText(QString());
        pushButton_3->setText(QString());
        lreg->setText(QApplication::translate("MainWindow", "          register", Q_NULLPTR));
        llog->setText(QApplication::translate("MainWindow", "login", Q_NULLPTR));
        lins->setText(QApplication::translate("MainWindow", "       instruction", Q_NULLPTR));
        luse->setText(QApplication::translate("MainWindow", "name", Q_NULLPTR));
        lcode->setText(QApplication::translate("MainWindow", "password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
