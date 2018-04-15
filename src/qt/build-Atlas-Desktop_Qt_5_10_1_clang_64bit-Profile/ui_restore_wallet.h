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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_restore_wallet
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_13;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *word_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *word_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *word_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *word_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *word_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *word_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *word_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *word_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *word_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *word_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *word_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLineEdit *word_12;

    void setupUi(QDialog *restore_wallet)
    {
        if (restore_wallet->objectName().isEmpty())
            restore_wallet->setObjectName(QStringLiteral("restore_wallet"));
        restore_wallet->resize(400, 300);
        buttonBox = new QDialogButtonBox(restore_wallet);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        label_13 = new QLabel(restore_wallet);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(130, 10, 141, 16));
        widget = new QWidget(restore_wallet);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 30, 312, 218));
        widget->setAutoFillBackground(false);
        widget->setInputMethodHints(Qt::ImhNone);
        horizontalLayout_13 = new QHBoxLayout(widget);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(false);
        label->setInputMethodHints(Qt::ImhNone);

        horizontalLayout->addWidget(label);

        word_1 = new QLineEdit(widget);
        word_1->setObjectName(QStringLiteral("word_1"));
        word_1->setAutoFillBackground(false);
        word_1->setInputMethodHints(Qt::ImhNone);
        word_1->setMaxLength(50);
        word_1->setClearButtonEnabled(false);

        horizontalLayout->addWidget(word_1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAutoFillBackground(false);
        label_2->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_2->addWidget(label_2);

        word_2 = new QLineEdit(widget);
        word_2->setObjectName(QStringLiteral("word_2"));
        word_2->setAutoFillBackground(false);
        word_2->setInputMethodHints(Qt::ImhNone);
        word_2->setMaxLength(50);
        word_2->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(word_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAutoFillBackground(false);
        label_3->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_3->addWidget(label_3);

        word_3 = new QLineEdit(widget);
        word_3->setObjectName(QStringLiteral("word_3"));
        word_3->setAutoFillBackground(false);
        word_3->setInputMethodHints(Qt::ImhNone);
        word_3->setMaxLength(50);
        word_3->setClearButtonEnabled(false);

        horizontalLayout_3->addWidget(word_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAutoFillBackground(false);
        label_4->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_4->addWidget(label_4);

        word_4 = new QLineEdit(widget);
        word_4->setObjectName(QStringLiteral("word_4"));
        word_4->setAutoFillBackground(false);
        word_4->setInputMethodHints(Qt::ImhNone);
        word_4->setMaxLength(50);
        word_4->setClearButtonEnabled(false);

        horizontalLayout_4->addWidget(word_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAutoFillBackground(false);
        label_5->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_5->addWidget(label_5);

        word_5 = new QLineEdit(widget);
        word_5->setObjectName(QStringLiteral("word_5"));
        word_5->setAutoFillBackground(false);
        word_5->setInputMethodHints(Qt::ImhNone);
        word_5->setMaxLength(50);
        word_5->setClearButtonEnabled(false);

        horizontalLayout_5->addWidget(word_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAutoFillBackground(false);
        label_6->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_6->addWidget(label_6);

        word_6 = new QLineEdit(widget);
        word_6->setObjectName(QStringLiteral("word_6"));
        word_6->setAutoFillBackground(false);
        word_6->setInputMethodHints(Qt::ImhNone);
        word_6->setMaxLength(50);
        word_6->setClearButtonEnabled(false);

        horizontalLayout_6->addWidget(word_6);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_13->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAutoFillBackground(false);
        label_7->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_7->addWidget(label_7);

        word_7 = new QLineEdit(widget);
        word_7->setObjectName(QStringLiteral("word_7"));
        word_7->setAutoFillBackground(false);
        word_7->setInputMethodHints(Qt::ImhNone);
        word_7->setMaxLength(50);
        word_7->setClearButtonEnabled(false);

        horizontalLayout_7->addWidget(word_7);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAutoFillBackground(false);
        label_8->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_8->addWidget(label_8);

        word_8 = new QLineEdit(widget);
        word_8->setObjectName(QStringLiteral("word_8"));
        word_8->setAutoFillBackground(false);
        word_8->setInputMethodHints(Qt::ImhNone);
        word_8->setMaxLength(50);
        word_8->setClearButtonEnabled(false);

        horizontalLayout_8->addWidget(word_8);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAutoFillBackground(false);
        label_9->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_9->addWidget(label_9);

        word_9 = new QLineEdit(widget);
        word_9->setObjectName(QStringLiteral("word_9"));
        word_9->setAutoFillBackground(false);
        word_9->setInputMethodHints(Qt::ImhNone);
        word_9->setMaxLength(50);
        word_9->setClearButtonEnabled(false);

        horizontalLayout_9->addWidget(word_9);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAutoFillBackground(false);
        label_10->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_10->addWidget(label_10);

        word_10 = new QLineEdit(widget);
        word_10->setObjectName(QStringLiteral("word_10"));
        word_10->setAutoFillBackground(false);
        word_10->setInputMethodHints(Qt::ImhNone);
        word_10->setMaxLength(50);
        word_10->setClearButtonEnabled(false);

        horizontalLayout_10->addWidget(word_10);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAutoFillBackground(false);
        label_11->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_11->addWidget(label_11);

        word_11 = new QLineEdit(widget);
        word_11->setObjectName(QStringLiteral("word_11"));
        word_11->setAutoFillBackground(false);
        word_11->setInputMethodHints(Qt::ImhNone);
        word_11->setMaxLength(50);
        word_11->setClearButtonEnabled(false);

        horizontalLayout_11->addWidget(word_11);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAutoFillBackground(false);
        label_12->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_12->addWidget(label_12);

        word_12 = new QLineEdit(widget);
        word_12->setObjectName(QStringLiteral("word_12"));
        word_12->setAutoFillBackground(false);
        word_12->setInputMethodHints(Qt::ImhNone);
        word_12->setMaxLength(50);
        word_12->setClearButtonEnabled(false);

        horizontalLayout_12->addWidget(word_12);


        verticalLayout_2->addLayout(horizontalLayout_12);


        horizontalLayout_13->addLayout(verticalLayout_2);


        retranslateUi(restore_wallet);
        QObject::connect(buttonBox, SIGNAL(accepted()), restore_wallet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), restore_wallet, SLOT(reject()));

        QMetaObject::connectSlotsByName(restore_wallet);
    } // setupUi

    void retranslateUi(QDialog *restore_wallet)
    {
        restore_wallet->setWindowTitle(QApplication::translate("restore_wallet", "Dialog", nullptr));
        label_13->setText(QApplication::translate("restore_wallet", "Enter 12-word phrase:", nullptr));
        label->setText(QApplication::translate("restore_wallet", "1.", nullptr));
        word_1->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("restore_wallet", "2.", nullptr));
        word_2->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("restore_wallet", "3.", nullptr));
        word_3->setPlaceholderText(QString());
        label_4->setText(QApplication::translate("restore_wallet", "4.", nullptr));
        word_4->setPlaceholderText(QString());
        label_5->setText(QApplication::translate("restore_wallet", "5.", nullptr));
        word_5->setPlaceholderText(QString());
        label_6->setText(QApplication::translate("restore_wallet", "6.", nullptr));
        word_6->setPlaceholderText(QString());
        label_7->setText(QApplication::translate("restore_wallet", "7.", nullptr));
        word_7->setPlaceholderText(QString());
        label_8->setText(QApplication::translate("restore_wallet", "8.", nullptr));
        word_8->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("restore_wallet", "9.", nullptr));
        word_9->setPlaceholderText(QString());
        label_10->setText(QApplication::translate("restore_wallet", "10.", nullptr));
        word_10->setPlaceholderText(QString());
        label_11->setText(QApplication::translate("restore_wallet", "11.", nullptr));
        word_11->setPlaceholderText(QString());
        label_12->setText(QApplication::translate("restore_wallet", "12.", nullptr));
        word_12->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class restore_wallet: public Ui_restore_wallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTORE_WALLET_H
