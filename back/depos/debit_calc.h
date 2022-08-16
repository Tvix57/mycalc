#ifndef DEBIT_CALC_H
#define DEBIT_CALC_H
#include <QDate>
#include <QSet>

class Debit_calc
{
public:
    Debit_calc(double, double, double, QDate, QDate);
    double get_dayly_proc();

    void add_summ_on_bill(double addition);

    double get_summ_on_bill() {return summ_on_bill;}
    double get_nalog() {return nalog;}
    double get_profit() {return profit;}
    void calculateNOcapit();
    void calculate(int);
    void getNewAddition(QDate, double);
private:
    QDate start_date, end_date;
    QSet <double> addition_list;
    double summ, proc, nalog;

    double summ_on_bill;
    double nalog_on_profit;
    double profit;
};

#endif // DEBIT_CALC_H
