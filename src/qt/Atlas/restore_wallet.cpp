#include "restore_wallet.h"
#include "ui_restore_wallet.h"
#include <string>

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

const std::vector<std::string> restore_wallet::get_word_list()
{
    // Vector holds the word list of the mnemomic 12-word phrase.
    std::vector<std::string> word_list;

    // Append each word to vector.
    word_list.push_back(ui->word_1->text().toStdString());
    word_list.push_back(ui->word_2->text().toStdString());
    word_list.push_back(ui->word_3->text().toStdString());
    word_list.push_back(ui->word_4->text().toStdString());
    word_list.push_back(ui->word_5->text().toStdString());
    word_list.push_back(ui->word_6->text().toStdString());
    word_list.push_back(ui->word_7->text().toStdString());
    word_list.push_back(ui->word_8->text().toStdString());
    word_list.push_back(ui->word_9->text().toStdString());
    word_list.push_back(ui->word_10->text().toStdString());
    word_list.push_back(ui->word_11->text().toStdString());
    word_list.push_back(ui->word_12->text().toStdString());

    return word_list;
}
