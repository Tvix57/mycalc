#include "depos_window.h"
#include "ui_depos_window.h"

depos_window::depos_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::depos_window)
{
    ui->setupUi(this);
}

depos_window::~depos_window()
{
    delete ui;
}
