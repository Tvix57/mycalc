#include "credit_calc.h"

Credit_calc::Credit_calc(double summ_input, int term_input, double nalog_input)
{
    summ = summ_input;
    term = term_input;
    nalog = nalog_input;
}

void Credit_calc::calculated_anuited()
{
    month_pay = summ * (nalog + (nalog/(pow(1+nalog, month)-1)));
    month_pay *= 100;
    month_pay = round(month_pay);
    month_pay /= 100;
    all_payed = month_pay * month;
    all_payed *= 100;
    all_payed = round(all_payed);
    all_payed /= 100;
    overpay = all_payed - summ;
    overpay *= 100;
    overpay = round(overpay);
    overpay /= 100;
}

void Credit_calc::calculated_differ()
{
    double credit_part = summ / month;
    double bank_part = 0;
    for (int i = 0; i < month; i++) {
        bank_part = (credit_part * (month - i)) * nalog;
        if (all_payed == 0) {
            month_pay = credit_part + bank_part;
        }
        all_payed += credit_part + bank_part;
    }
    final_monthpay = credit_part + bank_part;
}
