/********************************************************************************
** Form generated from reading UI file 'regerror.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGERROR_H
#define UI_REGERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_regerror
{
public:
    QLabel *warn;

    void setupUi(QDialog *regerror)
    {
        if (regerror->objectName().isEmpty())
            regerror->setObjectName(QStringLiteral("regerror"));
        regerror->resize(400, 300);
        warn = new QLabel(regerror);
        warn->setObjectName(QStringLiteral("warn"));
        warn->setGeometry(QRect(10, -10, 341, 71));

        retranslateUi(regerror);

        QMetaObject::connectSlotsByName(regerror);
    } // setupUi

    void retranslateUi(QDialog *regerror)
    {
        regerror->setWindowTitle(QApplication::translate("regerror", "Dialog", Q_NULLPTR));
        warn->setText(QApplication::translate("regerror", "\347\224\250\346\210\267\345\220\215\345\222\214\345\257\206\347\240\201\344\270\215\350\203\275\344\270\272\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class regerror: public Ui_regerror {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGERROR_H
