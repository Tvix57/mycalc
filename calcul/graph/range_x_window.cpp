#include "range_x_window.h"
#include "ui_range_x_window.h"
#include <cmath>

range_x_window::range_x_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::range_x_window) {
    ui->setupUi(this);
    setWindowTitle("Настройки графика функции");
    range_row_x_begin = ui->start_doubleSpinBox->value();
    range_row_x_end = ui->end_doubleSpinBox->value();
    step = ui->doubleSpinBox->value();
}

range_x_window::~range_x_window() {
    delete ui;
}

void range_x_window::on_buttonBox_accepted() {
    range_row_x_begin = ui->start_doubleSpinBox->value();
    range_row_x_end = ui->end_doubleSpinBox->value();

    if (range_row_x_end < range_row_x_begin) {
        double tmp = range_row_x_begin;
        range_row_x_begin = range_row_x_end;
        range_row_x_end = tmp;
    }
    step = ui->doubleSpinBox->value();
}

void range_x_window::on_buttonBox_rejected() {
    ui->start_doubleSpinBox->setValue(range_row_x_begin);
    ui->end_doubleSpinBox->setValue(range_row_x_end);
    ui->doubleSpinBox->setValue(step);
}

void range_x_window::on_end_doubleSpinBox_valueChanged(double arg1) {
    double maximum = fabs(ui->start_doubleSpinBox->value()-arg1);
    ui->doubleSpinBox->setMinimum(maximum/1e+7);
    ui->doubleSpinBox->setMaximum(maximum/2);
}

void range_x_window::on_start_doubleSpinBox_valueChanged(double arg1) {
    double maximum = fabs(arg1-ui->end_doubleSpinBox->value());
    ui->doubleSpinBox->setMinimum(maximum/1e+7);
    ui->doubleSpinBox->setMaximum(maximum/2);
}
