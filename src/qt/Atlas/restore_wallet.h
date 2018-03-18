#ifndef RESTORE_WALLET_H
#define RESTORE_WALLET_H

#include <QDialog>

namespace Ui {
class restore_wallet;
}

class restore_wallet : public QDialog
{
    Q_OBJECT

public:
    explicit restore_wallet(QWidget *parent = 0);
    ~restore_wallet();

private:
    Ui::restore_wallet *ui;
};

#endif // RESTORE_WALLET_H
