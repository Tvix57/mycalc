#include "range_x_window.h"
#include "ui_range_x_window.h"

range_x_window::range_x_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::range_x_window)
{
    ui->setupUi(this);
}

range_x_window::~range_x_window()
{
    delete ui;
}


void range_x_window::on_buttonBox_accepted()
{
    range_row_x_begin = ui->start_doubleSpinBox->value();
    range_row_x_end = ui->end_doubleSpinBox->value();
    if (range_row_x_end < range_row_x_begin) {
        double tmp = range_row_x_begin;
        range_row_x_begin = range_row_x_end;
        range_row_x_end = tmp;
    }
    step = ui->doubleSpinBox->value();
}


void range_x_window::on_buttonBox_rejected()
{
    ui->start_doubleSpinBox->setValue(range_row_x_begin);
    ui->end_doubleSpinBox->setValue(range_row_x_end);
    ui->doubleSpinBox->setValue(step);
}

