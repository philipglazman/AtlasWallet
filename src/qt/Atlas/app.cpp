#include "app.h"
#include "ui_app.h"
#include "restore_wallet.h"
#include <string>
#include <vector>
#include <QDebug>
#include "../../wallet/stdafx.h"
#include <QClipboard>
#include <QRadioButton>
#include <qboxlayout.h>

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

void app::set_send_tab()
{
    network->refreshFeeRecommendations();
    ui->fee_slider->setMaximum(network->getFastestFee());
};

void app::set_history_tab()
{
    const int NUM_TX = 10;

    // Select scrollArea.
    QScrollArea *list_of_tx = ui->tx_scroll_area;
    list_of_tx->setBackgroundRole(QPalette::Window);
    list_of_tx->setFrameShadow(QFrame::Plain);
    list_of_tx->setFrameShape(QFrame::NoFrame);
    list_of_tx->setWidgetResizable(true);

    // Array of transactions.
    QGroupBox * transactions[NUM_TX];

    // Add transaction widget.
    for (int i = 0;i<NUM_TX;i++)
    {
        QGroupBox *groupBox = new QGroupBox(tr("&Transaction"));

        QLabel *date = new QLabel("Date of Transaction");
        QLabel *hash = new QLabel("Hash of Transaction");
        QLabel *value = new QLabel("Amount Transacted");

        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(date);
        vbox->addWidget(hash);
        vbox->addWidget(value);
        vbox->addStretch(1);
        groupBox->setLayout(vbox);
        transactions[i] = groupBox;
    }

    // Add box to main scroll area widget.
    QWidget* boxArea = new QWidget;
    boxArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    boxArea->setLayout(new QVBoxLayout(boxArea));
    list_of_tx->setWidget(boxArea);
    QLayout *lay = boxArea->layout();

    // Add transactions to boxArea.
    for (int i = 0;i<NUM_TX;i++)
    {
        lay->addWidget(transactions[i]);
    }
};

void app::on_tabWidget_tabBarClicked(int index)
{
    switch(index)
    {
    case 0:
        //main
        this->set_main_tab();
        break;
    case 1:
        //send
        this->set_send_tab();
        break;
    case 2:
        //history
        this->set_history_tab();
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

void app::on_fee_slider_sliderMoved(int position)
{
    ui->sat_byte_fee->setText(QString::number(position)+" Satoshis per Byte");
}

bool app::is_valid_address()
{
    std::string address = ui->send_btc_address->toPlainText().toStdString();
    std::cout << address << std::endl;

    /** @todo do appropriate address validation using checksum
     */

    // Bitcoin address is between 26 and 35 characters.
    // check length
    if(address.length()<26 || address.length() >35)
    {
        std::cout << "bad length" << std::endl;
        return false;
    }


    /**
      @todo - check base58 encoding
      */

    // check prefix
//    else if(address[0] != 'm' || address[0] != 'n' || address[0] != '2')
//    {
//        std::cout << "bad prefix" << std::endl;
//        return false;
//    }
    else
    {
        return true;
    }
}

void app::on_send_tx_clicked()
{
    //validate btc address
    if(!is_valid_address())
    {
        std::cout<<"invalid address"<<std::endl;
    }

    //validate btc amount

    //send transaction
    this->send_transaction();
}

bool app::send_transaction()
{
    std::string address = ui->send_btc_address->toPlainText().toStdString();
    unsigned long long amount = ui->send_btc_amount->toPlainText().toInt()*100000;
    //unsigned long long fee = ui->fee_slider->value();

    wallet->build_P2PKH(address,amount);
}
