/********************************************************************************
** Form generated from reading UI file 'start_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_MENU_H
#define UI_START_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start_menu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *create_new_wallet;
    QPushButton *restore_existing_wallet;

    void setupUi(QDialog *start_menu)
    {
        if (start_menu->objectName().isEmpty())
            start_menu->setObjectName(QStringLiteral("start_menu"));
        start_menu->resize(400, 300);
        start_menu->setAutoFillBackground(false);
        layoutWidget = new QWidget(start_menu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 80, 291, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        create_new_wallet = new QPushButton(layoutWidget);
        create_new_wallet->setObjectName(QStringLiteral("create_new_wallet"));

        verticalLayout->addWidget(create_new_wallet);

        restore_existing_wallet = new QPushButton(layoutWidget);
        restore_existing_wallet->setObjectName(QStringLiteral("restore_existing_wallet"));

        verticalLayout->addWidget(restore_existing_wallet);


        retranslateUi(start_menu);

        QMetaObject::connectSlotsByName(start_menu);
    } // setupUi

    void retranslateUi(QDialog *start_menu)
    {
        start_menu->setWindowTitle(QApplication::translate("start_menu", "Atlas", nullptr));
        create_new_wallet->setText(QApplication::translate("start_menu", "Create New Wallet", nullptr));
        restore_existing_wallet->setText(QApplication::translate("start_menu", "Restore Existing Wallet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start_menu: public Ui_start_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_MENU_H
