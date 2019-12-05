/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_clientDialog
{
public:
    QPushButton *pushButton;
    QPlainTextEdit *output;
    QPushButton *send;
    QTextEdit *input;

    void setupUi(QDialog *clientDialog)
    {
        if (clientDialog->objectName().isEmpty())
            clientDialog->setObjectName(QStringLiteral("clientDialog"));
        clientDialog->resize(1000, 747);
        pushButton = new QPushButton(clientDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 610, 75, 23));
        output = new QPlainTextEdit(clientDialog);
        output->setObjectName(QStringLiteral("output"));
        output->setGeometry(QRect(40, 130, 681, 331));
        send = new QPushButton(clientDialog);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(660, 560, 61, 20));
        input = new QTextEdit(clientDialog);
        input->setObjectName(QStringLiteral("input"));
        input->setGeometry(QRect(40, 460, 681, 121));
        input->raise();
        pushButton->raise();
        output->raise();
        send->raise();

        retranslateUi(clientDialog);

        QMetaObject::connectSlotsByName(clientDialog);
    } // setupUi

    void retranslateUi(QDialog *clientDialog)
    {
        clientDialog->setWindowTitle(QApplication::translate("clientDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("clientDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        send->setText(QApplication::translate("clientDialog", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class clientDialog: public Ui_clientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
