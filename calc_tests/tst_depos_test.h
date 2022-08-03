#ifndef TST_DEPOS_TEST_H
#define TST_DEPOS_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../back/depos/debit_calc.h"
#include <QString>
#include <cmath>
#define EPS 1e-6
using namespace testing;


TEST(test1_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "2000"; /// summ
  input_data[1] = "100";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "1";   // payrate
  input_data[5] = "0";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 3400.00;
  double debit_nalog = 0;
  double debit_perc = 92.62;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test2_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "2000"; /// summ
  input_data[1] = "100";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "7";   // payrate
  input_data[5] = "0";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 3400.00;
  double debit_nalog = 0;
  double debit_perc = 92.73;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test3_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "2000"; /// summ
  input_data[1] = "100";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "30";   // payrate
  input_data[5] = "0";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 3400.00;
  double debit_nalog = 0;
  double debit_perc = 92.74;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test4_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "200000"; /// summ
  input_data[1] = "1000";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "1";   // payrate
  input_data[5] = "0";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 201400.00;
  double debit_nalog = 0;
  double debit_perc = 55124.65;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test5_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "200000"; /// summ
  input_data[1] = "1000";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "7";   // payrate
  input_data[5] = "0";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 201400.00;
  double debit_nalog = 0;
  double debit_perc = 55122.72;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test6_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "200000"; /// summ
  input_data[1] = "1000";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "30";   // payrate
  input_data[5] = "0";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 201400.00;
  double debit_nalog = 0;
  double debit_perc = 55122.49;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test7_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "2000"; /// summ
  input_data[1] = "100";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "1";   // payrate
  input_data[5] = "1";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 3494.02;
  double debit_nalog = 0;
  double debit_perc = 94.02;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test8_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "2000"; /// summ
  input_data[1] = "100";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "7";   // payrate
  input_data[5] = "1";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 3493.92;
  double debit_nalog = 0;
  double debit_perc = 93.92;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test9_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "2000"; /// summ
  input_data[1] = "100";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "30";   // payrate
  input_data[5] = "1";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 3493.64;
  double debit_nalog = 0;
  double debit_perc = 93.64;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test10_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "200000"; /// summ
  input_data[1] = "1000";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "1";   // payrate
  input_data[5] = "1";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 264794.01;
  double debit_nalog = 0;
  double debit_perc = 63394.01;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test11_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "200000"; /// summ
  input_data[1] = "1000";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "7";   // payrate
  input_data[5] = "1";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 264734.60;
  double debit_nalog = 0;
  double debit_perc = 63334.60;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}


TEST(test12_d) {
  QString input_data[8];
  double *output_data;
  input_data[0] = "200000"; /// summ
  input_data[1] = "1000";  ///  day
  input_data[2] = "10" ;  // percent
  input_data[3] = "0";   // nalog
  input_data[4] = "30";   // payrate
  input_data[5] = "1";   // type
  input_data[6] = "0 0 1 3 10 ";   // addition day
  input_data[7] = "500 200 1000 -500 200 ";   // addition summ
  output_data = debit_calk(8, input_data);
  double debit_bill = 200700.00;
  double debit_nalog = 0;
  double debit_perc = 54930.97;
  ASSERT_NEAR(debit_bill, output_data[2], 1e-2);
  ASSERT_NEAR(debit_nalog, output_data[1], 1e-2);
  ASSERT_NEAR(debit_perc, output_data[0], 1e-2);
  free(output_data);
}

#endif // TST_DEPOS_TEST_H
