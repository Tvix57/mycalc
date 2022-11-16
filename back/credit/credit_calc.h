#ifndef SRC_BACK_CREDIT_CREDIT_CALC_H_
#define SRC_BACK_CREDIT_CREDIT_CALC_H_

namespace s21 {
class Credit_calc {
 public:
    Credit_calc(double summ, int term, double nalog);
    void calculated_anuited();
    void calculated_differ();
    double get_month_pay() {return month_pay;}
    double get_overpay() {return overpay;}
    double get_allpayed() {return all_payed;}
    double get_final_pay() {return final_monthpay;}

 private:
    double summ;
    int term;
    double nalog;
    double month_pay;
    double overpay;
    double all_payed;
    double final_monthpay;
};
}  // namespace s21
#endif  // SRC_BACK_CREDIT_CREDIT_CALC_H_
