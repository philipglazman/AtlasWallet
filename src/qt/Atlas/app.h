#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include "restore_wallet.h"
#include "start_menu.h"
#include "../../wallet/stdafx.h"

namespace Ui {
class app;
}

class app : public QMainWindow
{
    Q_OBJECT

public:
    explicit app(QWidget *parent = 0);
    ~app();

private:
    Wallet * wallet;

    std::string menu_choice;

    Ui::app *ui;
    restore_wallet * restore_wallet;
    start_menu * start_menu;

    std::vector<std::string> word_list;

    void init_start_menu();
    void init_wallet();

    void get_mnemonic_phrase();
};

#endif // APP_H
