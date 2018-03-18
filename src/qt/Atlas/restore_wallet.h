#ifndef RESTORE_WALLET_H
#define RESTORE_WALLET_H

#include <QDialog>
#include <string>

namespace Ui {
class restore_wallet;
}

class restore_wallet : public QDialog
{
    Q_OBJECT

public:
    explicit restore_wallet(QWidget *parent = 0);
    ~restore_wallet();

    // Returns a vector of the 12-word phrase.
    const std::vector<std::string> get_word_list();

    // TODO:
    // QValidator, setValidator
    // When value in lineedit is changed, signal is emitted, check if the value change is valid.
    // Require all lines to be filled out.

private:
    Ui::restore_wallet *ui;
};

#endif // RESTORE_WALLET_H
