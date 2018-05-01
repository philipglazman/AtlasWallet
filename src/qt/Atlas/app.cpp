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

/**
 * @brief Constructor for app::app
 * @param parent
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
app::app(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::app)
{
    ui->setupUi(this);

    // Starts immediate dialog box asking user for new/restore wallet.
    init_start_menu();
    init_wallet();
    set_main_tab();

    // Initialize network.
    network = new Network();

    // Initialize script.
    script = new Script();
}

/**
 * @brief Desturctor for app::~app
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
app::~app()
{
    delete ui;
}

/**
 * @brief Asks user if they would like to start a new wallet or restore wallet. Creates new dialog window.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::init_start_menu()
{

    // Start new dialog box.
    start_menu = new class start_menu();
    start_menu -> setModal(true);
    start_menu->exec();

    // Get choice from dialog box.
    if(start_menu->close() == true)
    {
        menu_choice = start_menu->get_menu_choice();
    }
    else
    {
        menu_choice = "new";
    }

};

/**
 * @brief Starts new wallet using menmonic seed phrase or restoring an old one from a word list.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::init_wallet()
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

/**
 * @brief Gets mnemonic phrase from the restore wallet dialog box.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::get_mnemonic_phrase()
{
    // Starts new dialog window which asks users for 12-word mnemonic phrase.
    restore_wallet = new class restore_wallet();

    // Main focus of UI will be on new restore_wallet window.
    restore_wallet->setModal(true);

    // Once accepted, get the vector containing phrase.
    if(restore_wallet->exec() == QDialog::Accepted){
        word_list = restore_wallet->get_word_list();
    }
};

/**
 * @brief Sets the text of the availabe payment address.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::set_available_payment_address()
{
    ui->btc_address->setText(QString::fromStdString(wallet->getAddress(1).encoded()));
};

/**
 * @brief Sets the text of the available balance of the bitcoin wallet.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::set_btc_balance()
{
    ui->btc_balance->setText(QString::fromStdString(wallet->get_balance_as_string()));
};

/**
 * @brief Refreshes the main tab including the payment addresses and balance.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::set_main_tab()
{
    this->set_available_payment_address();
    this->set_btc_balance();
};

/**
 * @brief Refreshes the analytics tab including the fee recommendations.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::set_analytics_tab()
{
    // Get network fee recommendations.
    network->refreshFeeRecommendations();

    // Change text for fee recommendations.
    ui->fastwait_fee->setText(QString::number(network->getFastestFee()) + " Satoshis per Byte");
    ui->midwait_fee->setText(QString::number(network->getHalfHourFee()) + " Satoshis per Byte");
    ui->highwait_fee->setText(QString::number(network->getHourFee()) + " Satoshis per Byte");
};

/**
 * @brief Refreshes the send transaction tab including the maximum fee that user can send.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::set_send_tab()
{
    // Get network free recommendations.
    network->refreshFeeRecommendations();

    // Set a maximum fee user can send so that the user is not overpaying a fee.
    // This reduces the flexibility of the wallet but places greater important on protecting user from overpaying fees.
    ui->fee_slider->setMaximum(network->getFastestFee());
};

/**
 * @brief Refreshes the history tab by showing all the last transactions involving wallet's addresses.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::set_history_tab()
{

    // Vector holding last history of transactions.
    std::vector< std::tuple<unsigned long long,bc::hash_digest,int> > tx =  wallet-> get_transaction_history();

    // Number of transactions.
    const int NUM_TX = tx.size();

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

        QLabel *date = new QLabel("Block Height: " + QString::number(std::get<2>(tx[i])));
        QLabel *hash = new QLabel("Transaction Hash: " + QString::fromStdString(bc::encode_hash(std::get<1>(tx[i]))));
        //bc::encode_base10(output.value(), 8)
        QLabel *value = new QLabel("Value: " + QString::fromStdString(bc::encode_base10(std::get<0>(tx[i]),8)) + " BTC");

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

/**
 * @brief Refreshes the script tab.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::set_script_tab()
{
    ui->is_valid_script_label->setText("Valid!");
    ui->is_valid_script_label->setStyleSheet("QLabel { color : green; }");
    ui->is_valid_script_label->setVisible(false);
};

/**
 * @brief Refreshes a given tab that has been clicked.
 * @param index
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::on_tabWidget_tabBarClicked(int index)
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
            this->set_script_tab();
            break;
    }
};

/**
 * @brief User clicked on copy bitcoin address. Bitcoin address is copied to computer's clipboard.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::on_copy_btc_address_clicked()
{
    // Access clipboard.
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->btc_address->text());
};

/**
 * @brief User slided fee slider on send transaction tab.
 * @param position
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::on_fee_slider_sliderMoved(int position)
{
    ui->sat_byte_fee->setText(QString::number(position)+" Satoshis per Byte");
};

/**
 * @brief Performs a check that a given payment address is a legimiate address.
 * @return boolean
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
app::is_valid_address()
{
    std::string address = ui->send_btc_address->toPlainText().toStdString();
    std::cout << address << std::endl;

    /** @todo do appropriate address validation using checksum
     */

    // Bitcoin address is between 26 and 35 characters.
    // check length
    if(address.length()<26 || address.length() >35)
    {
        return false;
    }


    /**
      @todo - check base58 encoding
      */
    else
    {
        return true;
    }
};

/**
 * @brief Sends transaction on send button in send transaction tab. Does validation first.
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
void
app::on_send_tx_clicked()
{
    // validate transaction
    if(this->is_validate_tx())
    {
        //send transaction
        this->send_transaction();
    }

};


/**
 * @brief app::is_validate_tx
 * @return
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
app::is_validate_tx()
{
    //validate btc address
    if(!is_valid_address())
    {

        // Show error message.
        error_msg.showMessage("Invalid address!");

        return false;
    };

    // validate btc amount
    if(wallet->getBalance() < (ui->send_btc_amount->toPlainText().toInt()*100000 + ui->fee_slider->value() ))
    {

        std::cout << ui->fee_slider->value() << std::endl;

        // Show error message.
        error_msg.showMessage("Not enough money!");

        return false;
    };

    return true;
};

/**
 * @brief Broadcasts transaction to the network.
 * @return
 *
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
app::send_transaction()
{
    // Get address, value, and fee.
    std::string address = ui->send_btc_address->toPlainText().toStdString();
    unsigned long long amount = ui->send_btc_amount->toPlainText().toInt()*100000;
    unsigned long long fee = ui->fee_slider->value();

    // Broadcast transaction.
    wallet->build_P2PKH(address,amount,fee);
};

/**
 * @brief app::on_run_script_btn_clicked
 *
 * @author Philip Glazman
 * @date 4/30/18
 */
void
app::on_run_script_btn_clicked()
{
    this->run_script();
}

/**
 * @brief app::run_script
 *
 * @author Philip Glazman
 * @date 4/30/18
 */
void
app::run_script()
{
    std::string witness = ui->witness_text_edit->toPlainText().toStdString();
    std::string witness_script = ui->witness_script_text_edit->toPlainText().toStdString();

    script->run_script();
    script->build_script(witness,witness_script);
};
