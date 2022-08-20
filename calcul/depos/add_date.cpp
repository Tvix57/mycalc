#include "add_date.h"
#include "ui_add_date.h"

add_date::add_date(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_date)
{
    ui->setupUi(this);
    ui->date_addition_form->setDate(QDate::currentDate());
}

add_date::~add_date() {
    delete ui;
}

void add_date::on_pushButton_clicked() {
    this->close();
    emit Close_add_window();
}

