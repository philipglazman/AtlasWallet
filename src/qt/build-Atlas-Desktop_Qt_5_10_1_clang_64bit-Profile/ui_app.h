/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_app
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_main;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *btc_recieved;
    QLabel *btc_sent;
    QLabel *btc_balance;
    QGroupBox *groupBox_2;
    QLabel *btc_address;
    QPushButton *copy_btc_address;
    QWidget *tab_send;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *send_tx;
    QPushButton *pushButton_2;
    QTextEdit *send_btc_address;
    QTextEdit *send_btc_amount;
    QScrollBar *fee_slider;
    QLabel *sat_byte_fee;
    QLabel *label_7;
    QWidget *tab_history;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QGroupBox *groupBox_5;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QGroupBox *groupBox_6;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QGroupBox *groupBox_7;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *tab_analytics;
    QGroupBox *groupBox_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *fastwait_fee;
    QLabel *midwait_fee;
    QLabel *highwait_fee;
    QWidget *tab_script;
    QMenuBar *menuBar;
    QMenu *menuAtlas;
    QMenu *menuHistory;
    QMenu *menuAnalytics;
    QMenu *menuScript;

    void setupUi(QMainWindow *app)
    {
        if (app->objectName().isEmpty())
            app->setObjectName(QStringLiteral("app"));
        app->resize(953, 467);
        app->setTabShape(QTabWidget::Rounded);
        actionExit = new QAction(app);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(app);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 931, 401));
        tabWidget->setTabsClosable(false);
        tab_main = new QWidget();
        tab_main->setObjectName(QStringLiteral("tab_main"));
        groupBox = new QGroupBox(tab_main);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(260, 20, 401, 191));
        groupBox->setAutoFillBackground(false);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 171, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 171, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 171, 16));
        btc_recieved = new QLabel(groupBox);
        btc_recieved->setObjectName(QStringLiteral("btc_recieved"));
        btc_recieved->setGeometry(QRect(210, 40, 171, 20));
        btc_sent = new QLabel(groupBox);
        btc_sent->setObjectName(QStringLiteral("btc_sent"));
        btc_sent->setGeometry(QRect(210, 70, 181, 16));
        btc_balance = new QLabel(groupBox);
        btc_balance->setObjectName(QStringLiteral("btc_balance"));
        btc_balance->setGeometry(QRect(210, 100, 181, 16));
        groupBox_2 = new QGroupBox(tab_main);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 240, 391, 80));
        btc_address = new QLabel(groupBox_2);
        btc_address->setObjectName(QStringLiteral("btc_address"));
        btc_address->setGeometry(QRect(10, 30, 341, 16));
        copy_btc_address = new QPushButton(groupBox_2);
        copy_btc_address->setObjectName(QStringLiteral("copy_btc_address"));
        copy_btc_address->setGeometry(QRect(270, 50, 113, 32));
        tabWidget->addTab(tab_main, QString());
        tab_send = new QWidget();
        tab_send->setObjectName(QStringLiteral("tab_send"));
        label_4 = new QLabel(tab_send);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 40, 81, 16));
        label_5 = new QLabel(tab_send);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 80, 81, 16));
        label_6 = new QLabel(tab_send);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 120, 81, 16));
        send_tx = new QPushButton(tab_send);
        send_tx->setObjectName(QStringLiteral("send_tx"));
        send_tx->setGeometry(QRect(140, 150, 113, 32));
        pushButton_2 = new QPushButton(tab_send);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 150, 113, 32));
        send_btc_address = new QTextEdit(tab_send);
        send_btc_address->setObjectName(QStringLiteral("send_btc_address"));
        send_btc_address->setGeometry(QRect(120, 40, 481, 21));
        send_btc_address->setInputMethodHints(Qt::ImhNone);
        send_btc_amount = new QTextEdit(tab_send);
        send_btc_amount->setObjectName(QStringLiteral("send_btc_amount"));
        send_btc_amount->setGeometry(QRect(120, 80, 101, 21));
        fee_slider = new QScrollBar(tab_send);
        fee_slider->setObjectName(QStringLiteral("fee_slider"));
        fee_slider->setGeometry(QRect(120, 120, 160, 16));
        fee_slider->setMaximum(99);
        fee_slider->setOrientation(Qt::Horizontal);
        sat_byte_fee = new QLabel(tab_send);
        sat_byte_fee->setObjectName(QStringLiteral("sat_byte_fee"));
        sat_byte_fee->setGeometry(QRect(300, 120, 131, 16));
        label_7 = new QLabel(tab_send);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(230, 80, 81, 16));
        tabWidget->addTab(tab_send, QString());
        tab_history = new QWidget();
        tab_history->setObjectName(QStringLiteral("tab_history"));
        scrollArea = new QScrollArea(tab_history);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 20, 891, 341));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 875, 339));
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 10, 851, 81));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 30, 161, 31));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(670, 30, 161, 31));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(340, 30, 161, 31));
        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 100, 851, 81));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 30, 161, 31));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(670, 30, 161, 31));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(340, 30, 161, 31));
        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 190, 851, 81));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 30, 161, 31));
        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(670, 30, 161, 31));
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(340, 30, 161, 31));
        groupBox_7 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 280, 851, 81));
        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 30, 161, 31));
        label_21 = new QLabel(groupBox_7);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(670, 30, 161, 31));
        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(340, 30, 161, 31));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab_history, QString());
        tab_analytics = new QWidget();
        tab_analytics->setObjectName(QStringLiteral("tab_analytics"));
        groupBox_3 = new QGroupBox(tab_analytics);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(480, 60, 361, 241));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 40, 161, 16));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 80, 161, 16));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 120, 161, 16));
        fastwait_fee = new QLabel(groupBox_3);
        fastwait_fee->setObjectName(QStringLiteral("fastwait_fee"));
        fastwait_fee->setGeometry(QRect(180, 40, 161, 16));
        midwait_fee = new QLabel(groupBox_3);
        midwait_fee->setObjectName(QStringLiteral("midwait_fee"));
        midwait_fee->setGeometry(QRect(180, 80, 161, 16));
        highwait_fee = new QLabel(groupBox_3);
        highwait_fee->setObjectName(QStringLiteral("highwait_fee"));
        highwait_fee->setGeometry(QRect(180, 120, 161, 16));
        tabWidget->addTab(tab_analytics, QString());
        tab_script = new QWidget();
        tab_script->setObjectName(QStringLiteral("tab_script"));
        tabWidget->addTab(tab_script, QString());
        app->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(app);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 22));
        menuBar->setDefaultUp(true);
        menuAtlas = new QMenu(menuBar);
        menuAtlas->setObjectName(QStringLiteral("menuAtlas"));
        menuHistory = new QMenu(menuBar);
        menuHistory->setObjectName(QStringLiteral("menuHistory"));
        menuHistory->setAcceptDrops(false);
        menuAnalytics = new QMenu(menuBar);
        menuAnalytics->setObjectName(QStringLiteral("menuAnalytics"));
        menuScript = new QMenu(menuBar);
        menuScript->setObjectName(QStringLiteral("menuScript"));
        app->setMenuBar(menuBar);

        menuBar->addAction(menuAtlas->menuAction());
        menuBar->addAction(menuHistory->menuAction());
        menuBar->addAction(menuAnalytics->menuAction());
        menuBar->addAction(menuScript->menuAction());
        menuAtlas->addAction(actionExit);
        menuAtlas->addSeparator();

        retranslateUi(app);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(app);
    } // setupUi

    void retranslateUi(QMainWindow *app)
    {
        app->setWindowTitle(QApplication::translate("app", "Atlas", nullptr));
        actionExit->setText(QApplication::translate("app", "Exit", nullptr));
        groupBox->setTitle(QApplication::translate("app", "Overview", nullptr));
        label->setText(QApplication::translate("app", "Recieved:", nullptr));
        label_2->setText(QApplication::translate("app", "Sent:", nullptr));
        label_3->setText(QApplication::translate("app", "Balance:", nullptr));
        btc_recieved->setText(QApplication::translate("app", "btc_recieved", nullptr));
        btc_sent->setText(QApplication::translate("app", "btc_sent", nullptr));
        btc_balance->setText(QApplication::translate("app", "btc_balance", nullptr));
        groupBox_2->setTitle(QApplication::translate("app", "Available Payment Address", nullptr));
        btc_address->setText(QApplication::translate("app", "btc_address", nullptr));
        copy_btc_address->setText(QApplication::translate("app", "Copy", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_main), QApplication::translate("app", "Main", nullptr));
        label_4->setText(QApplication::translate("app", "Recipient", nullptr));
        label_5->setText(QApplication::translate("app", "Amount", nullptr));
        label_6->setText(QApplication::translate("app", "Fee", nullptr));
        send_tx->setText(QApplication::translate("app", "Send", nullptr));
        pushButton_2->setText(QApplication::translate("app", "Cancel", nullptr));
        sat_byte_fee->setText(QApplication::translate("app", "0 Satoshis per Byte", nullptr));
        label_7->setText(QApplication::translate("app", "mBTC", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_send), QApplication::translate("app", "Send", nullptr));
        groupBox_4->setTitle(QApplication::translate("app", "Block Num", nullptr));
        label_11->setText(QApplication::translate("app", "Date", nullptr));
        label_12->setText(QApplication::translate("app", "+0.2 BTC", nullptr));
        label_13->setText(QApplication::translate("app", "Hash", nullptr));
        groupBox_5->setTitle(QApplication::translate("app", "Block Num", nullptr));
        label_14->setText(QApplication::translate("app", "Date", nullptr));
        label_15->setText(QApplication::translate("app", "+0.2 BTC", nullptr));
        label_16->setText(QApplication::translate("app", "Hash", nullptr));
        groupBox_6->setTitle(QApplication::translate("app", "Block Num", nullptr));
        label_17->setText(QApplication::translate("app", "Date", nullptr));
        label_18->setText(QApplication::translate("app", "+0.2 BTC", nullptr));
        label_19->setText(QApplication::translate("app", "Hash", nullptr));
        groupBox_7->setTitle(QApplication::translate("app", "Block Num", nullptr));
        label_20->setText(QApplication::translate("app", "Date", nullptr));
        label_21->setText(QApplication::translate("app", "+0.2 BTC", nullptr));
        label_22->setText(QApplication::translate("app", "Hash", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_history), QApplication::translate("app", "History", nullptr));
        groupBox_3->setTitle(QApplication::translate("app", "Fees", nullptr));
        label_8->setText(QApplication::translate("app", "Fastest Fee:", nullptr));
        label_9->setText(QApplication::translate("app", "30-minute Fee:", nullptr));
        label_10->setText(QApplication::translate("app", "1-hour Fee:", nullptr));
        fastwait_fee->setText(QApplication::translate("app", "fastwait_fee", nullptr));
        midwait_fee->setText(QApplication::translate("app", "midwait_fee", nullptr));
        highwait_fee->setText(QApplication::translate("app", "highwait_fee", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_analytics), QApplication::translate("app", "Analytics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_script), QApplication::translate("app", "Script", nullptr));
        menuAtlas->setTitle(QApplication::translate("app", "Atlas", nullptr));
        menuHistory->setTitle(QApplication::translate("app", "History", nullptr));
        menuAnalytics->setTitle(QApplication::translate("app", "Analytics", nullptr));
        menuScript->setTitle(QApplication::translate("app", "Script", nullptr));
    } // retranslateUi

};

namespace Ui {
    class app: public Ui_app {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
