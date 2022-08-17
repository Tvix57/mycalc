#include "debit_calc.h"
#include <QtMath>


Debit_calc::Debit_calc(double summ, double proc, double nalog , QDate start_date, QDate end_date) {
    this->summ = summ;
    this->proc = proc/100;
    this->nalog = nalog/100;
    this->start_date = start_date;
    this->end_date = end_date;
}

void Debit_calc::calculateNOcapit() {
    if (addition_list.empty()) {
        summ_on_bill = (summ * proc * (start_date.daysTo(end_date))) / start_date.daysInYear() /100;
    } else {

    }
}

void Debit_calc::calculate(int period) {
    QDate capit_date = start_date;
    capit_date = updateCapitDay(capit_date, period);
    summ_on_bill = summ;
    for (;start_date != end_date; start_date = start_date.addDays(1)) {
        if (start_date == capit_date) {
            capit_date = updateCapitDay(capit_date, period);
            summ_on_bill += profit;
            profit = 0;
        }
        if (start_date == addition_list.firstKey()) {
            summ_on_bill += addition_list.value(start_date);
        }
      profit +=  round(summ_on_bill * proc * 1 / start_date.daysInYear()) / 100;
    }
    profit = summ_on_bill - summ;
    if (nalog != 0) {
        nalog_on_profit = profit * nalog;
        profit -= nalog_on_profit;
        summ_on_bill = summ + profit;
    }
}

void Debit_calc::getNewAddition(QDate date, double summ) {
    addition_list.insert(date, summ);
}

QDate Debit_calc::updateCapitDay(QDate date, int period) {
    switch(period) {
    case 0:date = date.addDays(1);
        break;
    case 1:date = date.addDays(7);
        break;
    case 2:date = date.addMonths(1);
        break;
    case 3:date = date.addMonths(3);
        break;
    case 4:date = date.addMonths(6);
        break;
    case 5:date = date.addYears(1);
        break;
    case 6:date = end_date;
        break;
    default:
        break;
    }
    return date;
}
