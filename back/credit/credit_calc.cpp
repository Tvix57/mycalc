#include "credit_calc.h"
#include <QtMath>


Credit_calc::Credit_calc(double summ, int term, double nalog) {
    this->summ = summ;
    this->term = term;
    this->nalog = nalog/(100*12);
    all_payed = 0;
}

void Credit_calc::calculated_anuited() {
    month_pay = summ * (nalog + (nalog / (pow((1 + nalog),term)-1)));
    month_pay *=100;
    month_pay = round(month_pay);
    month_pay /=100;
    all_payed = month_pay * term;
    all_payed *=100;
    all_payed = round(all_payed);
    all_payed /=100;
    overpay = all_payed - summ;
    overpay *=100;
    overpay = round(overpay);
    overpay /=100;
}

void Credit_calc::calculated_differ() {
    double credit_part = summ / term;
    credit_part *=100;
    credit_part = round(credit_part);
    credit_part /=100;
    double bank_part = 0;
    double credit_body = summ;
    for (int i = 1; i <= term; i++) {
        bank_part = credit_body * nalog;
        bank_part *=100;
        bank_part = round(bank_part);
        bank_part /=100;
        if (all_payed == 0) {
            month_pay = credit_part + bank_part;
            month_pay *=100;
            month_pay = round(month_pay);
            month_pay /=100;
        } else if (i == term) {
            final_monthpay = credit_part + bank_part;
            final_monthpay *=100;
            final_monthpay = round(final_monthpay);
            final_monthpay /=100;
        }
        all_payed += credit_part + bank_part;
        all_payed *=100;
        all_payed = round(all_payed);
        all_payed /=100;
        credit_body -= credit_part;
        credit_body *=100;
        credit_body = round(credit_body);
        credit_body /=100;
    }
    overpay = all_payed - summ;
    overpay *=100;
    overpay = round(overpay);
    overpay /=100;
}
