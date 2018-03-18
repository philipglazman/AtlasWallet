/********************************************************************************
** Form generated from reading UI file 'restore_wallet.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTORE_WALLET_H
#define UI_RESTORE_WALLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_restore_wallet
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;

    void setupUi(QDialog *restore_wallet)
    {
        if (restore_wallet->objectName().isEmpty())
            restore_wallet->setObjectName(QStringLiteral("restore_wallet"));
        restore_wallet->resize(400, 300);
        buttonBox = new QDialogButtonBox(restore_wallet);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(restore_wallet);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 221, 16));
        widget = new QWidget(restore_wallet);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 30, 111, 216));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        textEdit_3 = new QTextEdit(widget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        verticalLayout->addWidget(textEdit_3);

        textEdit_2 = new QTextEdit(widget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout->addWidget(textEdit_2);

        textEdit_4 = new QTextEdit(widget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));

        verticalLayout->addWidget(textEdit_4);

        textEdit_5 = new QTextEdit(widget);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));

        verticalLayout->addWidget(textEdit_5);

        textEdit_6 = new QTextEdit(widget);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));

        verticalLayout->addWidget(textEdit_6);


        retranslateUi(restore_wallet);
        QObject::connect(buttonBox, SIGNAL(accepted()), restore_wallet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), restore_wallet, SLOT(reject()));

        QMetaObject::connectSlotsByName(restore_wallet);
    } // setupUi

    void retranslateUi(QDialog *restore_wallet)
    {
        restore_wallet->setWindowTitle(QApplication::translate("restore_wallet", "Dialog", nullptr));
        label->setText(QApplication::translate("restore_wallet", "Enter 12-Word Phrases:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class restore_wallet: public Ui_restore_wallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTORE_WALLET_H
