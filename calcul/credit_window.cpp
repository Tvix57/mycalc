#include "credit_window.h"
#include "ui_credit_window.h"

Credit_window::Credit_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Credit_window)
{
    ui->setupUi(this);
    ui->line_day->setValidator(new QIntValidator);
    ui->line_proc->setValidator(new QDoubleValidator);
    ui->line_summ->setValidator(new QDoubleValidator);
    ui->radio_anue_type->setChecked(true);
}

Credit_window::~Credit_window()
{
    delete ui;
}

void Credit_window::on_calc_Button_clicked()
{
    QString summ = ui->line_summ->text();
    QString perc = ui->line_proc->text();
    QString day = ui->line_day->text();
    int param = 0;
    std::string tmp[4];
    tmp[0] = summ.toStdString();
    tmp[1] = perc.toStdString();
    tmp[2] = day.toStdString();
    char *arr_input[4];
    if (!tmp[0].empty()) {
        arr_input[0] = (char*)tmp[0].c_str();
        param++;
    }
    if (!tmp[1].empty()) {
        arr_input[1] = (char*)tmp[2].c_str();
        param++;
    }
    if (!tmp[2].empty()) {
        arr_input[2] = (char*)tmp[1].c_str();
        param++;
    }
    if (ui->radio_anue_type->isChecked()) {
        arr_input[3] = (char*)"0";
        param++;
    } else if (ui->radio_dif_type->isChecked()) {
        arr_input[3] = (char*)"1";
        param++;
    }

    double *arr_out = credit_calk(param, arr_input);

    if (arr_out[0] == NAN) {
        ui->label_month_pay->setText("Недостаточно данных");
    } else {
        if (ui->radio_anue_type->isChecked()) {
            ui->label_res_month_pay->setText(QString::number(arr_out[0], 'f', 2));
        } else {
            ui->label_res_month_pay->setText(QString::number(arr_out[0], 'f', 2) +" - " + QString::number(arr_out[3], 'f', 2));
        }

        ui->label_res_overpay->setText(QString::number(arr_out[1], 'f', 2));
        ui->label_res_all_payed->setText(QString::number(arr_out[2], 'f', 2));
    }
    free(arr_out);
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

