#include "credit_window.h"
#include "ui_credit_window.h"
#include "credit_calc.h"
#include <QString>

Credit_window::Credit_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Credit_window)
{
    ui->setupUi(this);
    ui->radio_anue_type->setChecked(true);
}

Credit_window::~Credit_window()
{
    delete ui;
}

void Credit_window::on_calc_Button_clicked()
{
    double summ = ui->sum_doubleSpinBox->value();
    int day = ui->term_spinBox->value();
    switch (ui->term_spinBox->value()) {
    case 1: day *= 30;
        break;
    case 2: day *=365;
        break;
    default:
        break;
    }
    double proc = ui->proc_doubleSpinBox->value();
    Credit_calc calc(summ, day, proc);
    if (ui->radio_anue_type->isChecked()) {
        calc.calculated_anuited();
    } else if (ui->radio_dif_type->isChecked()) {
        calc.calculated_differ();
    }
    ui->label_res_month_pay->setText(QString::number(calc.get_month_pay(), 'f', 2));
    if (ui->radio_dif_type->isChecked()) {
        QString tmp = ui->label_res_month_pay->text();
        tmp += " - ";
        tmp += QString::number(calc.get_final_pay(), 'f', 2);
        ui->label_res_month_pay->setText(tmp);
    }
        ui->label_res_overpay->setText(QString::number(calc.get_overpay(), 'f', 2));
        ui->label_res_all_payed->setText(QString::number(calc.get_allpayed(), 'f', 2));
}

void Credit_window::on_main_calc_button_triggered()
{
    this->close();
    emit Calcul();
}

void Credit_window::on_depos_calc_button_triggered()
{
    this->close();
    emit depow_window_from_credit();
}
