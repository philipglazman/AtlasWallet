#include "app.h"
#include "ui_app.h"

app::app(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::app)
{
    ui->setupUi(this);
}

app::~app()
{
    delete ui;
}

void app::on_pushButton_2_clicked()
{
    delete ui;
}

void app::on_restore_existing_wallet_clicked()
{
    delete ui;
}
