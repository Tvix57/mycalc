#include "depos_window_2.h"
#include "ui_depos_window_2.h"


depos_window_2::depos_window_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::depos_window_2)
{
    ui->setupUi(this);
    widg_count = 0;
    QWidget * addition_widget = new QWidget();
    addition = new QGridLayout();
    addition->setAlignment(Qt::AlignTop);
    addition_widget->setLayout(addition);
    ui->scrollArea->setWidget(addition_widget);
    ui->comboBox->setVisible(false);
    ui->label_11->setVisible(false);
    ui->start_dateEdit->setDate(QDate::currentDate());
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

void depos_window_2::on_calc_pushButton_clicked() {
    int period = ui->spinBox_day->value();
    double summ = ui->doubleSpinBox_summ->value();
    double proc = ui->proc_doubleSpinBox->value();
    double nalog = ui->nalog_doubleSpinBox_2->value();
    QDate start_date = ui->start_dateEdit->date();
    QDate end_date;

    switch (ui->comboBox_period->currentIndex()) {
    case 1:
        end_date = start_date.addMonths(period);
        break;
    case 2:
        end_date = start_date.addYears(period);
        break;
    default:
        end_date = start_date.addDays(period);
        break;
    }
    Debit_calc calc(summ, proc, nalog, start_date, end_date);
    if (widg_count > 0) {
        for (int i = 1; i <= widg_count; i++) {
            QWidget *tmp_widget = addition->itemAtPosition(i, 0)->widget();
            QList <QDateEdit*> list = tmp_widget->findChildren<QDateEdit*>("date_addition_form");
            QList <QDoubleSpinBox*> list2 = tmp_widget->findChildren<QDoubleSpinBox*>("summ_addition_form");
            QList <QComboBox*> list3 = tmp_widget->findChildren<QComboBox*>("type_addition_form");
            double add = list2[0]->value();
            if (list3[0]->currentIndex() == 1) {
                add *=-1;
            }
            calc.getNewAddition(list[0]->date(), add);
        }
    }
    if (!ui->capit_checkBox->isChecked()) {
      calc.calculateNOcapit();
    } else {
      calc.calculate(ui->comboBox->currentIndex());
    }
    ui->label_summ_out->setText(QString::number(calc.get_profit(), 'f', 2));
    ui->label_nalog_out->setText(QString::number(calc.get_nalog(), 'f', 2));
    ui->label_summ_all_out->setText(QString::number(calc.get_summ_on_bill(), 'f', 2));
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
