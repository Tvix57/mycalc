#ifndef TST_CREDIT_TEST_H
#define TST_CREDIT_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../back/credit/credit_calc.h"
#include <QString>
#include <cmath>
#define EPS 1e-6
using namespace testing;


TEST(calc_credit_test, test1_c) {
  Credit_calc test(2000, 12, 10);
  test.calculated_anuited();
  double month_pay = 175.83;
  double overpay = 109.96;
  double summ = 2109.96;
  ASSERT_NEAR(month_pay, test.get_month_pay(), 1e-2);
  ASSERT_NEAR(summ, test.get_allpayed(), 1e-2);
  ASSERT_NEAR(overpay, test.get_overpay(), 1e-2);

}


TEST(calc_credit_test, test2_c) {
  Credit_calc test(400000, 30, 10);
  test.calculated_anuited();
  double month_pay = 15124.56;
  double overpay = 53736.80;
  double summ = 453736.80;
  ASSERT_NEAR(month_pay, test.get_month_pay(), 1e-2);
  ASSERT_NEAR(overpay, test.get_overpay(), 1e-2);
  ASSERT_NEAR(summ, test.get_allpayed(), 1e-2);
}

TEST(calc_credit_test, test3_c) {
  Credit_calc test(2000, 12, 10);
  test.calculated_differ();
  double month_pay_1 = 183.33;
  double month_pay_2 = 168.06;
  double overpay = 108.33;
  double summ = 2108.33;
  ASSERT_NEAR(month_pay_1, test.get_month_pay(), 1e-2);
//  ASSERT_NEAR(overpay, test.get_overpay(), 1e-2);
//  ASSERT_NEAR(summ, test.get_allpayed(), 1e-2);
  ASSERT_NEAR(month_pay_2, test.get_final_pay(), 1e-2);
}


TEST(calc_credit_test, test4_c) {
  Credit_calc test(400000, 30, 10);
  test.calculated_differ();
  double month_pay_1 = 16666.67;
  double month_pay_2 = 13444.44;
  double overpay = 51666.67;
  double summ = 451666.67;
  ASSERT_NEAR(month_pay_1, test.get_month_pay(), 1e-2);
//  ASSERT_NEAR(overpay, test.get_overpay(), 1e-2);
//  ASSERT_NEAR(summ, test.get_allpayed(), 1e-2);
  ASSERT_NEAR(month_pay_2, test.get_final_pay(), 1e-2);
}


TEST(calc_credit_test, test5_c) {
  Credit_calc test(50000000, 60, 10);
  test.calculated_anuited();
  double month_pay_1 = 1062352.24;
  double overpay = 13741134.40;
  double summ = 63741134.40;
  ASSERT_NEAR(month_pay_1, test.get_month_pay(), 1e-2);
  ASSERT_NEAR(overpay, test.get_overpay(), 1e-2);
  ASSERT_NEAR(summ, test.get_allpayed(), 1e-2);
}


TEST(calc_credit_test, test6_c) {
  Credit_calc test(50000000, 60, 10);
  test.calculated_differ();
  double month_pay_1 = 1250000.00;
  double month_pay_2 = 840277.78;
  double overpay = 12708333.33;
  double summ = 62708333.33;
  ASSERT_NEAR(month_pay_1, test.get_month_pay(), 1e-2);
//  ASSERT_NEAR(overpay, test.get_overpay(), 1e-2);
//  ASSERT_NEAR(summ, test.get_allpayed(), 1e-2);
  ASSERT_NEAR(month_pay_2, test.get_final_pay(), 1e-2);
}

#endif // TST_CREDIT_TEST_H
