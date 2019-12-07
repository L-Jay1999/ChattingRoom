/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *create;
    QSpacerItem *horizontalSpacer;
    QPushButton *enter;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QPlainTextEdit *roomName;
    QLabel *label_2;
    QLineEdit *roomPassword;
    QSpacerItem *verticalSpacer;
    QPushButton *exit;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(705, 501);
        widget = new QWidget(login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(82, 135, 583, 341));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        create = new QPushButton(widget);
        create->setObjectName(QStringLiteral("create"));
        create->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(create, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(9, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 2);

        enter = new QPushButton(widget);
        enter->setObjectName(QStringLiteral("enter"));
        enter->setMinimumSize(QSize(100, 100));
        enter->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(enter, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 7, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 100));

        gridLayout->addWidget(pushButton, 0, 8, 1, 2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 10, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 20));

        gridLayout->addWidget(label_3, 1, 1, 2, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 20));

        gridLayout->addWidget(label_4, 1, 5, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 6, 3, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label_5, 1, 8, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 10, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 2, 1, 2);

        roomName = new QPlainTextEdit(widget);
        roomName->setObjectName(QStringLiteral("roomName"));
        roomName->setMaximumSize(QSize(200, 30));

        gridLayout->addWidget(roomName, 4, 4, 1, 3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 5, 2, 1, 2);

        roomPassword = new QLineEdit(widget);
        roomPassword->setObjectName(QStringLiteral("roomPassword"));
        roomPassword->setMinimumSize(QSize(0, 30));
        roomPassword->setMaximumSize(QSize(200, 30));

        gridLayout->addWidget(roomPassword, 5, 4, 2, 3);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 9, 1, 1);

        exit = new QPushButton(widget);
        exit->setObjectName(QStringLiteral("exit"));

        gridLayout->addWidget(exit, 8, 8, 1, 2);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        create->setText(QString());
        enter->setText(QString());
        pushButton->setText(QString());
        label_3->setText(QApplication::translate("login", "     \345\210\233\346\210\277", Q_NULLPTR));
        label_4->setText(QApplication::translate("login", "     \350\277\233\346\210\277", Q_NULLPTR));
        label_5->setText(QApplication::translate("login", "    \346\210\277\351\227\264\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("login", "     \346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "     \345\257\206\347\240\201", Q_NULLPTR));
        exit->setText(QApplication::translate("login", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
