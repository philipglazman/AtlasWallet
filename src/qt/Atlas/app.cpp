#include "app.h"
#include "ui_app.h"
#include "restore_wallet.h"
#include <string>

app::app(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::app)
{
    ui->setupUi(this);
}

app::~app()
{
    delete ui;
}

void app::on_pushButton_2_clicked()
{
    delete ui;
}


void app::on_restore_existing_wallet_clicked()
{
    restore_wallet = new class restore_wallet();

    // Main focus of UI will be on new restore_wallet window.
    restore_wallet->setModal(true);

    if(restore_wallet->exec() == QDialog::Accepted){
        std::vector<std::string> word_list(restore_wallet->get_word_list());
        ui->debuggerLabel->setText( QString::fromStdString(word_list[2]) );
    }
    //else do something
}
