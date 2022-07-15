#include "depos_window_2.h"
#include "ui_depos_window_2.h"


depos_window_2::depos_window_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::depos_window_2)
{
    ui->setupUi(this);
    ui->start_date_lable->setVisible(false);
    ui->start_dateEdit->setVisible(false);
    widg_count = 0;
    QWidget * addition_widget = new QWidget();
    addition = new QGridLayout();
    addition->setAlignment(Qt::AlignTop);
    addition_widget->setLayout(addition);
    ui->scrollArea->setWidget(addition_widget);
    ui->line_nalog->setValidator(new QDoubleValidator);
    ui->line_proc->setValidator(new QDoubleValidator);
    ui->comboBox->setVisible(false);
    ui->label_11->setVisible(false);
    connect(ui->capit_checkBox, SIGNAL(clicked(bool)), this, SLOT(hide_capit_period(bool)));
}


depos_window_2::~depos_window_2()
{
    delete ui;
}

void depos_window_2::on_Credit_calc_button_triggered()
{
    this->close();
    emit credit_window_from_depos();
}

void depos_window_2::on_main_calc_buttom_triggered()
{
    this->close();
    emit Calcul();
}

void depos_window_2::on_calc_pushButton_clicked()
{
    int day_int = ui->spinBox_day->value();
    switch (ui->comboBox_period->currentIndex()) {
    case 1:
        day_int *=30;
        break;
    case 2:
        day_int *=365;
        break;
    default:
        break;
    }
    QString day = QString::number(day_int);
    QString summ = ui->doubleSpinBox_summ->textFromValue(ui->doubleSpinBox_summ->value());
    summ.remove(',');
    QString perc = ui->line_proc->text();
    QString nalog = ui->line_nalog->text();
    int param = 0;
    char *arr_input[8];
    std::string tmp[8];
    tmp[0] = summ.toStdString();
    tmp[1] = day.toStdString();
    tmp[2] = perc.toStdString();
    tmp[3] = nalog.toStdString();

    switch (ui->comboBox->currentIndex()) {
    case 0:
        tmp[4] = "1";
        break;
    case 1:
        tmp[4] = "7";
        break;
    case 2:
        tmp[4] = "30";
        break;
    case 3:
        tmp[4] = "90";
        break;
    case 4:
        tmp[4] = "183";
        break;
    case 5:
        tmp[4] = "365";
        break;
    case 6:
        tmp[4] = "0";
        break;
    default:
        break;
    }

    if (ui->capit_checkBox->isChecked()) {
        tmp[5] = "1";

    } else {
        tmp[5] = "0";

    }

    for (int i = 0; i < 8; i++) {
      if (!tmp[i].empty()) {
        arr_input[i] = (char*)tmp[i].c_str();
        param++;
      }
    }
    if (widg_count > 0) {
        QString day_input;
        QString summ_input;
        day_input.clear();
        summ_input.clear();
        QDate start_date = ui->start_dateEdit->date();
        for (int i = 0; i < widg_count; i++) {
         QWidget *tmp_widget = addition->itemAtPosition(i+1, 0)->widget();
         QList <QDateEdit*> list = tmp_widget->findChildren<QDateEdit*>("date_addition_form");
         QList <QDoubleSpinBox*> list2 = tmp_widget->findChildren<QDoubleSpinBox*>("summ_addition_form");
         QList <QComboBox*> list3 = tmp_widget->findChildren<QComboBox*>("type_addition_form");
         if (start_date.daysTo(list[0]->date()) >= 0) {
             int day_input_int = start_date.daysTo(list[0]->date());
             double summ_input_double = list2[0]->value();
             if (list3[0]->currentIndex() == 1) {
                summ_input_double *= -1;
             }
                day_input += day_input.number(day_input_int);
                day_input += " ";
                summ_input += summ_input.number(summ_input_double);
                summ_input += " ";
            }
         }
        tmp[6] = day_input.toStdString();
        tmp[7] = summ_input.toStdString();
        arr_input[6] = (char*)tmp[6].c_str();
        arr_input[7] = (char*)tmp[7].c_str();
        param +=2;
    }
    double *arr_out = debit_calk(param, arr_input);

    if (arr_out[0] == NAN) {
        ui->label_summ_out->setText("Недостаточно данных");
    } else {
        ui->label_summ_out->setText(QString::number(arr_out[0], 'f', 2));
        ui->label_nalog_out->setText(QString::number(arr_out[1], 'f', 2));
        ui->label_summ_all_out->setText(QString::number(arr_out[2], 'f', 2));/////summ on bill
    }
    free(arr_out);
}

void depos_window_2::on_calc_pushButton_2_clicked()
{
    if (!ui->start_date_lable->isVisible()) {
        ui->start_date_lable->setVisible(true);
        ui->start_dateEdit->setVisible(true);
    }
    new_add = new add_date();
    new_add->setMinimumHeight(50);
    widg_count++;
    connect(new_add, &add_date::Close_add_window, this, &depos_window_2::delete_widg);
    addition->addWidget(new_add, widg_count, 0);
    ui->scrollArea->show();
}

void depos_window_2::delete_widg() {
    widg_count--;
}

void depos_window_2::hide_capit_period(bool is_checked) {
    if (is_checked) {
        ui->comboBox->setVisible(true);
        ui->label_11->setVisible(true);
    } else {
        ui->comboBox->setVisible(false);
        ui->label_11->setVisible(false);
    }
}
