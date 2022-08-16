#include "debit_calc.h"
#include <QtMath>


Debit_calc::Debit_calc(double summ, double proc, double nalog , QDate start_date, QDate end_date) {
    this->summ = summ;
    this->proc = proc/100;
    this->nalog = nalog;
    this->start_date = start_date;
    this->end_date = end_date;
}


double Debit_calc::get_dayly_proc() {
    double result;
    result = (summ*proc*1/(QDate::currentDate().daysInYear()));
    return result;
}

void Debit_calc::add_summ_on_bill(double addition)
{
    summ_on_bill += addition;
}

void Debit_calc::calculateNOcapit() {

}

void Debit_calc::calculate(int preiod) {

}
