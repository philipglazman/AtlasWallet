#include "restore_wallet.h"
#include "ui_restore_wallet.h"

restore_wallet::restore_wallet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restore_wallet)
{
    ui->setupUi(this);
}

restore_wallet::~restore_wallet()
{
    delete ui;
}
