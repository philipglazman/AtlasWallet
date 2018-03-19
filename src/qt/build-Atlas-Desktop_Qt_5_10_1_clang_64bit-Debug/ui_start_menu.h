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

QT_BEGIN_NAMESPACE

class Ui_start_menu
{
public:

    void setupUi(QDialog *start_menu)
    {
        if (start_menu->objectName().isEmpty())
            start_menu->setObjectName(QStringLiteral("start_menu"));
        start_menu->resize(400, 300);

        retranslateUi(start_menu);

        QMetaObject::connectSlotsByName(start_menu);
    } // setupUi

    void retranslateUi(QDialog *start_menu)
    {
        start_menu->setWindowTitle(QApplication::translate("start_menu", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start_menu: public Ui_start_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_MENU_H
