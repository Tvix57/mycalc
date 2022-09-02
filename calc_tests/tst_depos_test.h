#ifndef TST_DEPOS_TEST_H
#define TST_DEPOS_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../back/depos/debit_calc.h"
#include <QString>
#include <QDate>
#include <cmath>
#define EPS 1e-6
using namespace testing;
using namespace s21;

TEST(calc_depos_test, test1_d) {
  QDate start_date;
  start_date.setDate(2022,8,20);
  QDate end_date = start_date.addDays(100);
  Debit_calc test(2000, 10, 0, start_date, end_date);

  test.getNewAddition(start_date.addDays(3), -500);
  test.getNewAddition(start_date, 500);
  test.getNewAddition(start_date, 200);
  test.getNewAddition(start_date.addDays(1), 1000);

  test.getNewAddition(start_date.addDays(10), 200);

  test.calculateNOcapit();
  double debit_bill = 3400.00;
  double debit_nalog = 0;
  double debit_perc = 92.75;

  ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
  ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
  ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}

TEST(calc_depos_test, test4_d) {
    QDate start_date;
    start_date.setDate(2022,8,20);
    QDate end_date = start_date.addDays(1000);
    Debit_calc test(2000, 10, 0, start_date, end_date);

    test.getNewAddition(start_date, 500);
    test.getNewAddition(start_date, 200);
    test.getNewAddition(start_date.addDays(1), 1000);
    test.getNewAddition(start_date.addDays(3), -500);
    test.getNewAddition(start_date.addDays(10), 200);
  test.calculateNOcapit();
  double debit_bill = 3400.00;
  double debit_nalog = 0;
  double debit_perc = 931.10;
  ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
  ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
  ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}

TEST(calc_depos_test, test7_d) {
    QDate start_date;
    start_date.setDate(2022,8,20);
    QDate end_date = start_date.addDays(100);
    Debit_calc test(2000, 10, 0,start_date, end_date);

    test.getNewAddition(start_date, 500);
    test.getNewAddition(start_date, 200);
    test.getNewAddition(start_date.addDays(1), 1000);
    test.getNewAddition(start_date.addDays(3), -500);
    test.getNewAddition(start_date.addDays(10), 200);

    test.calculate(0);

  double debit_bill = 3494.02;
  double debit_nalog = 0;
  double debit_perc = 94.02;
  ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
  ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
  ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}


TEST(calc_depos_test, test8_d) {
    QDate start_date;
    start_date.setDate(2022,8,20);
    QDate end_date = start_date.addDays(100);
    Debit_calc test(2000, 10, 0,start_date, end_date);

    test.getNewAddition(start_date, 500);
    test.getNewAddition(start_date, 200);
    test.getNewAddition(start_date.addDays(1), 1000);
    test.getNewAddition(start_date.addDays(3), -500);
    test.getNewAddition(start_date.addDays(10), 200);

    test.calculate(1);

  double debit_bill = 3493.87;
  double debit_nalog = 0;
  double debit_perc = 93.87;
  ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
  ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
  ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}


TEST(calc_depos_test, test9_d) {
    QDate start_date;
    start_date.setDate(2022,8,20);
    QDate end_date = start_date.addDays(100);
    Debit_calc test(2000, 10, 0,start_date, end_date);

    test.getNewAddition(start_date, 500);
    test.getNewAddition(start_date, 200);
    test.getNewAddition(start_date.addDays(1), 1000);
    test.getNewAddition(start_date.addDays(3), -500);
    test.getNewAddition(start_date.addDays(10), 200);

    test.calculate(2);
  double debit_bill = 3493.78;
  double debit_nalog = 0;
  double debit_perc = 93.78;
  ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
  ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
  ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}


TEST(calc_depos_test, test10_d) {
  QDate start_date;
  start_date.setDate(2022,8,20);
  QDate end_date = start_date.addDays(1000);
  Debit_calc test(200000, 10, 0,start_date, end_date);

  test.getNewAddition(start_date, 500);
  test.getNewAddition(start_date, 200);
  test.getNewAddition(start_date.addDays(1), 1000);
  test.getNewAddition(start_date.addDays(3), -500);
  test.getNewAddition(start_date.addDays(10), 200);

  test.calculate(0);

  double debit_bill = 264794.08;
  double debit_nalog = 0;
  double debit_perc = 63394.08;
  ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
  ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
  ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}


TEST(calc_depos_test, test11_d) {
    QDate start_date;
    start_date.setDate(2022,8,20);
    QDate end_date = start_date.addDays(1000);
    Debit_calc test(200000, 10, 0,start_date, end_date);

    test.getNewAddition(start_date, 500);
    test.getNewAddition(start_date, 200);
    test.getNewAddition(start_date.addDays(1), 1000);
    test.getNewAddition(start_date.addDays(3), -500);
    test.getNewAddition(start_date.addDays(10), 200);

    test.calculate(1);

    double debit_bill = 264734.92;
    double debit_nalog = 0;
    double debit_perc = 63334.92;
    ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
    ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
    ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}


TEST(calc_depos_test, test12_d) {
    QDate start_date;
    start_date.setDate(2022,8,20);
    QDate end_date = start_date.addDays(1000);
    Debit_calc test(200000, 10, 0,start_date, end_date);

    test.getNewAddition(start_date, 500);
    test.getNewAddition(start_date, 200);
    test.getNewAddition(start_date.addDays(1), 1000);
    test.getNewAddition(start_date.addDays(3), -500);
    test.getNewAddition(start_date.addDays(10), 200);

    test.calculate(2);

    double debit_bill = 264505.25;
    double debit_nalog = 0;
    double debit_perc = 63105.25;
    ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
    ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
    ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}

TEST(calc_depos_construct_test, copy_construct1) {
    QDate start_date;
    start_date.setDate(2022,8,20);
    QDate end_date = start_date.addDays(1000);
    Debit_calc test(200000, 10, 0,start_date, end_date);

    test.getNewAddition(start_date, 500);
    test.getNewAddition(start_date, 200);
    test.getNewAddition(start_date.addDays(1), 1000);
    test.getNewAddition(start_date.addDays(3), -500);
    test.getNewAddition(start_date.addDays(10), 200);

    test.calculate(2);

    double debit_bill = 264505.25;
    double debit_nalog = 0;
    double debit_perc = 63105.25;
    ASSERT_NEAR(debit_bill, test.get_summ_on_bill(), 1e-2);
    ASSERT_NEAR(debit_nalog, test.get_nalog(), 1e-2);
    ASSERT_NEAR(debit_perc, test.get_profit(), 1e-2);
}




#endif // TST_DEPOS_TEST_H
