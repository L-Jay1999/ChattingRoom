/********************************************************************************
** Form generated from reading UI file 'instruction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTION_H
#define UI_INSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_instruction
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *instruction)
    {
        if (instruction->objectName().isEmpty())
            instruction->setObjectName(QStringLiteral("instruction"));
        instruction->resize(564, 476);
        textEdit = new QTextEdit(instruction);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 50, 481, 381));
        pushButton = new QPushButton(instruction);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 440, 75, 23));

        retranslateUi(instruction);

        QMetaObject::connectSlotsByName(instruction);
    } // setupUi

    void retranslateUi(QDialog *instruction)
    {
        instruction->setWindowTitle(QApplication::translate("instruction", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("instruction", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class instruction: public Ui_instruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTION_H
