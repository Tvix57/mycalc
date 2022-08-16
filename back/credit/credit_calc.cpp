#include "credit_calc.h"
#include <QtMath>

Credit_calc::Credit_calc(double summ, int term, double nalog) {
    this->summ = summ;
    this->term = term;
    this->nalog = nalog/100;
}

void Credit_calc::calculated_anuited() {
    double month_nalog = nalog / 12;
    month_pay = summ * (month_nalog/(1-pow((1+month_nalog),((-1*term)-1))));
    all_payed = month_pay * term;
    overpay = all_payed - summ;
}

void Credit_calc::calculated_differ() {
    double credit_part = summ / term;
    double bank_part = 0;
    for (int i = 0; i < term; i++) {
        bank_part = (credit_part * (term - i)) * nalog;
        if (all_payed == 0) {
            month_pay = credit_part + bank_part;
        }
        all_payed += credit_part + bank_part;
    }
    final_monthpay = credit_part + bank_part;
}

