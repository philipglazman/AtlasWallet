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

private:
    Ui::start_menu *ui;
};

#endif // START_MENU_H
