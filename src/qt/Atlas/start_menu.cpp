#include "start_menu.h"
#include "ui_start_menu.h"

start_menu::start_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start_menu)
{
    ui->setupUi(this);
}

start_menu::~start_menu()
{
    delete ui;
}

std::string start_menu::get_menu_choice() const
{
    return menu_choice;
}

void start_menu::on_create_new_wallet_clicked()
{
    menu_choice = NEW_WALLET;
    this->close();
}

void start_menu::on_restore_existing_wallet_clicked()
{
    menu_choice = RESTORE_WALLET;
    this->close();
}
