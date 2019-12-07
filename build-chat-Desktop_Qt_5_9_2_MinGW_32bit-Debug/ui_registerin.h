/********************************************************************************
** Form generated from reading UI file 'registerin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERIN_H
#define UI_REGISTERIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registerin
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *registerin)
    {
        if (registerin->objectName().isEmpty())
            registerin->setObjectName(QStringLiteral("registerin"));
        registerin->resize(400, 300);
        label = new QLabel(registerin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 80, 54, 12));
        label_2 = new QLabel(registerin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 54, 12));
        lineEdit = new QLineEdit(registerin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 80, 113, 20));
        lineEdit_2 = new QLineEdit(registerin);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 120, 113, 20));
        pushButton = new QPushButton(registerin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 200, 75, 23));
        pushButton_2 = new QPushButton(registerin);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 200, 75, 23));

        retranslateUi(registerin);

        QMetaObject::connectSlotsByName(registerin);
    } // setupUi

    void retranslateUi(QDialog *registerin)
    {
        registerin->setWindowTitle(QApplication::translate("registerin", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("registerin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("registerin", "\345\257\206\347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("registerin", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("registerin", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registerin: public Ui_registerin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERIN_H
