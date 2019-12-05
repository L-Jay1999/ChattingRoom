/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_error
{
public:
    QLabel *label;
    QLabel *warn;

    void setupUi(QDialog *error)
    {
        if (error->objectName().isEmpty())
            error->setObjectName(QStringLiteral("error"));
        error->resize(400, 300);
        label = new QLabel(error);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 120, 54, 12));
        warn = new QLabel(error);
        warn->setObjectName(QStringLiteral("warn"));
        warn->setGeometry(QRect(0, -20, 331, 61));

        retranslateUi(error);

        QMetaObject::connectSlotsByName(error);
    } // setupUi

    void retranslateUi(QDialog *error)
    {
        error->setWindowTitle(QApplication::translate("error", "Dialog", Q_NULLPTR));
        label->setText(QString());
        warn->setText(QApplication::translate("error", "\345\257\206\347\240\201\351\224\231\350\257\257\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class error: public Ui_error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
