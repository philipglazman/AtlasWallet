#include "app.h"
#include "ui_app.h"
#include "restore_wallet.h"
#include <string>
#include <vector>
#include <QDebug>
#include "../../wallet/stdafx.h"
#include <QClipboard>

// Constructor
app::app(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::app)
{
    ui->setupUi(this);

    // Starts immediate dialog box asking user for new/restore wallet.
    init_start_menu();
    init_wallet();
    set_main_tab();

    network = new Network();
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
        wallet = new Wallet(word_list);
    }
};

void app::get_mnemonic_phrase()
{
    // Starts new dialog window which asks users for 12-word mnemonic phrase.
    restore_wallet = new class restore_wallet();

    // Main focus of UI will be on new restore_wallet window.
    restore_wallet->setModal(true);

    // Once accepted, get the vector containing phrase.
    if(restore_wallet->exec() == QDialog::Accepted){
        word_list = restore_wallet->get_word_list();
    }
}



void app::set_available_payment_address()
{
    ui->btc_address->setText(QString::fromStdString(wallet->getAddress(1).encoded()));
};

void app::set_btc_balance()
{
    ui->btc_balance->setText(QString::fromStdString(wallet->get_balance_as_string()));
}

void app::set_main_tab()
{
    this->set_available_payment_address();
    this->set_btc_balance();
};

void app::set_analytics_tab()
{
    network->refreshFeeRecommendations();
    ui->fastwait_fee->setText(QString::number(network->getFastestFee()) + " Satoshis per Byte");
    ui->midwait_fee->setText(QString::number(network->getHalfHourFee()) + " Satoshis per Byte");
    ui->highwait_fee->setText(QString::number(network->getHourFee()) + " Satoshis per Byte");
};

void app::void set_send_tab()
{

};


void app::on_tabWidget_tabBarClicked(int index)
{
    std::cout << ui->tabWidget->currentIndex() << std::endl;
    std::cout << "index" << index << std::endl;

    switch(index)
    {
    case 0:
        //main
        this->set_main_tab();
        break;
    case 2:
        //history
        break;
    case 3:
        // fees
        this->set_analytics_tab();
        break;
    case 4:
        // script
        break;
    }
}

void app::on_copy_btc_address_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->btc_address->text());
}

void app::on_horizontalScrollBar_sliderMoved(int position)
{
    ui->sat_byte_fee->setText(QString::number(position)+" Satoshis per Byte");
}
