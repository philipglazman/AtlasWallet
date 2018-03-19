#include "app.h"
#include "restore_wallet.h"
#include <QApplication>
#include "start_menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Asks user to start new wallet or restore existing wallet.
    start_menu start_menu;
    if(start_menu.exec())
    {
        int x = 1;
    };

    restore_wallet restore_wallet;

    restore_wallet.setModal(true);
    restore_wallet.exec();

    app w;
    w.show();

    return a.exec();
}
