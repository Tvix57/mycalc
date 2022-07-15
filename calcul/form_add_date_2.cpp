#include "form_add_date_2.h"
#include "ui_form_add_date_2.h"

form_add_date_2::form_add_date_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_add_date_2)
{
    ui->setupUi(this);
}

form_add_date_2::~form_add_date_2()
{
    delete ui;
}
