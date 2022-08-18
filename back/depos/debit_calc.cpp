#include "debit_calc.h"
#include <QtMath>


Debit_calc::Debit_calc(double summ, double proc, double nalog , QDate start_date, QDate end_date) {
    this->summ = summ;
    this->proc = proc/100;
    this->nalog = nalog/100;
    this->start_date = start_date;
    this->end_date = end_date;
    profit = 0;
    summ_on_bill = 0;
}

void Debit_calc::calculateNOcapit() {
    if (addition_list.empty()) {
        profit = (summ * proc * (start_date.daysTo(end_date))) / start_date.daysInYear();
    } else {
        QDate tmp = start_date;
        for(auto i = addition_list.begin(); i!= addition_list.end(); i++) {
            if (tmp < i.key()) {
                profit += round(summ * proc * tmp.daysTo(i.key()) / tmp.daysInYear() * 100)/100;
                summ += i.value();
                tmp = i.key();
            }
        }
        profit += round(summ * proc * tmp.daysTo(end_date) / tmp.daysInYear() * 100)/100;
    }
    nalog_on_profit = profit * nalog;
    summ_on_bill = summ;
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
        if (addition_list.contains(start_date)) {
            summ_on_bill += addition_list.value(start_date, 0);
            summ += addition_list.value(start_date, 0);
        }
      profit +=  round(summ_on_bill * (1+ ( proc  / start_date.daysInYear()))) / 100;
    }
    profit = summ_on_bill - summ;
    nalog_on_profit = profit * nalog;
}

void Debit_calc::getNewAddition(QDate date, double summ) {
    if (addition_list.contains(date)) {
        *addition_list.find(date) += summ;
    } else {
      addition_list.insert(date, summ);
    }
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
