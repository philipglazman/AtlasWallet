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
    QScrollArea *tx_scroll_area;
    QWidget *scrollAreaWidgetContents;
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
        tx_scroll_area = new QScrollArea(tab_history);
        tx_scroll_area->setObjectName(QStringLiteral("tx_scroll_area"));
        tx_scroll_area->setGeometry(QRect(20, 20, 891, 341));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(tx_scroll_area->sizePolicy().hasHeightForWidth());
        tx_scroll_area->setSizePolicy(sizePolicy);
        tx_scroll_area->setLineWidth(1);
        tx_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tx_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tx_scroll_area->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tx_scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 873, 339));
        tx_scroll_area->setWidget(scrollAreaWidgetContents);
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
