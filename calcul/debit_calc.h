#ifndef DEBIT_CALC_H
#define DEBIT_CALC_H
#include <QDate>

class Debit_calc
{
public:
    Debit_calc(double, double, double, QDate, QDate);
    double get_dayly_proc();

    void add_summ_on_bill(double addition);

    double get_summ_on_bill() {return summ_on_bill;}
    double get_nalog() {return nalog;}
    double get_profit() {return profit;}

    void set_start_date(QDate date);


private:
    QDate start_date, end_date;
    double summ, proc, nalog;

    double summ_on_bill;
    double nalog_on_profit;
    double profit;
};

#endif // DEBIT_CALC_H
