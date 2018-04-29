#ifndef START_MENU_H
#define START_MENU_H

#include <QDialog>

namespace Ui {
class start_menu;
}

class start_menu : public QDialog
{
    Q_OBJECT

public:
    explicit start_menu(QWidget *parent = 0);
    ~start_menu();

    std::string get_menu_choice() const;

private slots:

    // New wallet will be made.
    void on_create_new_wallet_clicked();

    // Restore wallet will be made.s
    void on_restore_existing_wallet_clicked();

private:

    const std::string NEW_WALLET = "new";
    const std::string RESTORE_WALLET = "restore";

    std::string menu_choice;

    Ui::start_menu *ui;
};

#endif // START_MENU_H
