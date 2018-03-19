/********************************************************************************
** Form generated from reading UI file 'start_wallet.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_WALLET_H
#define UI_START_WALLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start_wallet
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *restore_existing_wallet;

    void setupUi(QWidget *start_wallet)
    {
        if (start_wallet->objectName().isEmpty())
            start_wallet->setObjectName(QStringLiteral("start_wallet"));
        start_wallet->resize(400, 300);
        layoutWidget = new QWidget(start_wallet);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 80, 291, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        restore_existing_wallet = new QPushButton(layoutWidget);
        restore_existing_wallet->setObjectName(QStringLiteral("restore_existing_wallet"));

        verticalLayout->addWidget(restore_existing_wallet);


        retranslateUi(start_wallet);

        QMetaObject::connectSlotsByName(start_wallet);
    } // setupUi

    void retranslateUi(QWidget *start_wallet)
    {
        start_wallet->setWindowTitle(QApplication::translate("start_wallet", "Form", nullptr));
        pushButton->setText(QApplication::translate("start_wallet", "Create New Wallet", nullptr));
        restore_existing_wallet->setText(QApplication::translate("start_wallet", "Restore Existing Wallet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start_wallet: public Ui_start_wallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_WALLET_H
