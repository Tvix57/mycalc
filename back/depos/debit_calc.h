#ifndef SRC_BACK_DEPOS_DEBIT_CALC_H_
#define SRC_BACK_DEPOS_DEBIT_CALC_H_
#include <QDate>
#include <QMap>

namespace s21 {
class Debit_calc {
 public:
    Debit_calc(double, double, double, QDate, QDate);

    Debit_calc(const Debit_calc&);
    Debit_calc(Debit_calc&&);
    Debit_calc& operator=(const Debit_calc&);
    Debit_calc& operator=(Debit_calc&&);
    ~Debit_calc();

    double get_summ_on_bill() {return summ_on_bill;}
    double get_nalog() {return nalog_on_profit;}
    double get_profit() {return profit;}
    void calculateNOcapit();
    void calculate(int);
    void getNewAddition(QDate, double);

 private:
    QDate start_date, end_date;
    QMap <QDate, double> addition_list;
    double summ, proc, nalog;

    double summ_on_bill;
    double nalog_on_profit;
    double profit;

    QDate updateCapitDay(QDate, int);
};
}  // namespace s21
#endif  // SRC_BACK_DEPOS_DEBIT_CALC_H_
