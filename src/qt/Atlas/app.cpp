#include "app.h"
#include "ui_app.h"
#include "restore_wallet.h"
#include <string>
#include <vector>
#include <QDebug>
#include "../../wallet/stdafx.h"

// Constructor
app::app(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::app)
{
    ui->setupUi(this);

    // Starts immediate dialog box asking user for new/restore wallet.
    init_start_menu();
    init_wallet();
}

// Destructor
app::~app()
{
    delete ui;
}

// Asks user if they would like to start new wallet or restore wallet.
void app::init_start_menu()
{
    start_menu = new class start_menu();
    start_menu -> setModal(true);
    start_menu->exec();

    if(start_menu->close() == true)
    {
        menu_choice = start_menu->get_menu_choice();
        ui->debuggerLabel->setText(QString::fromStdString(menu_choice));
    }
};

void app::init_wallet()
{
    // Create new wallet.
    if(menu_choice == "new")
    {
        bc::wallet::word_list mnemonicSeed;
        wallet = new Wallet();
    }
    // Restore existing wallet.
    else if(menu_choice =="restore")
    {
        get_mnemonic_phrase();
//        ui->debuggerLabel->setText(QString::fromStdString(word_list[3]));
        wallet = new Wallet(word_list);
        ui->debuggerLabel->setText(QString::fromStdString(wallet->getAddress(1).encoded()));
    }
};

void app::get_mnemonic_phrase()
{
    restore_wallet = new class restore_wallet();

    // Main focus of UI will be on new restore_wallet window.
    restore_wallet->setModal(true);

    if(restore_wallet->exec() == QDialog::Accepted){
        word_list = restore_wallet->get_word_list();
//        for(int i = 0; i < temp.size();i++)
//        {
//            word_list.push_back(temp[i]);
//        }
    }
}
