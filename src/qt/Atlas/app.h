#ifndef APP_H
#define APP_H

#include <QMainWindow>

namespace Ui {
class app;
}

class app : public QMainWindow
{
    Q_OBJECT

public:
    explicit app(QWidget *parent = 0);
    ~app();

private slots:
    void on_pushButton_2_clicked();

    void on_restore_existing_wallet_clicked();

private:
    Ui::app *ui;
};

#endif // APP_H
