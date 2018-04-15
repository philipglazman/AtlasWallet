#include "app.h"
#include "restore_wallet.h"
#include <QApplication>
#include "start_menu.h"
#include "../../wallet/stdafx.h"

int main(int argc, char *argv[])
{
    // Launch main application window.
    QApplication a(argc, argv);
    app w;
    w.show();

    return a.exec();
}
