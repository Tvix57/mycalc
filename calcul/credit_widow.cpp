#include "credit_widow.h"
#include "ui_credit_widow.h"

credit_widow::credit_widow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credit_widow)
{
    ui->setupUi(this);
}

credit_widow::~credit_widow()
{
    delete ui;
}
