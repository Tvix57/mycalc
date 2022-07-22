
TEST(test1_c) {
  QString input_data[8];
  input_data[0] = "2000"; /// summ
  input_data[1] = "12";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "0" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay = 175.83;
  double overpay = 109.96;
  double summ = 2109.96;
  ASSERT_NEAR(month_pay, output_data[0], 1e-2);
  ASSERT_NEAR(overpay, output_data[1], 1e-2);
  ASSERT_NEAR(summ, output_data[2], 1e-2);
  free(output_data); 
}


TEST(test2_c) {
  QString input_data[8];
  input_data[0] = "400000"; /// summ
  input_data[1] = "30";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "0" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay = 15124.56;
  double overpay = 53736.80;
  double summ = 453736.80;
  ASSERT_NEAR(month_pay, output_data[0], 1e-2);
  ASSERT_NEAR(overpay, output_data[1], 1e-2);
  ASSERT_NEAR(summ, output_data[2], 1e-2);
  free(output_data); 
}


TEST(test3_c) {
  QString input_data[8];
  input_data[0] = "2000"; /// summ
  input_data[1] = "12";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "1" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay_1 = 183.33;
  double month_pay_2 = 168.06;
  double overpay = 108.33;
  double summ = 2108.33;
  ASSERT_NEAR(month_pay_1, output_data[0], 1e-2);
  ASSERT_NEAR(overpay, output_data[1], 1e-2);
  ASSERT_NEAR(summ, output_data[2], 1e-2);
  ASSERT_NEAR(month_pay_2, output_data[3], 1e-2);
  free(output_data); 
}


TEST(test4_c) {
  QString input_data[8];
  input_data[0] = "400000"; /// summ
  input_data[1] = "30";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "1" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay_1 = 16666.67;
  double month_pay_2 = 13444.44;
  double overpay = 51666.67;
  double summ = 451666.67;
  ASSERT_NEAR(month_pay_1, output_data[0], 1e-2);
  ASSERT_NEAR(overpay, output_data[1], 1e-2);
  ASSERT_NEAR(summ, output_data[2], 1e-2);
  ASSERT_NEAR(month_pay_2, output_data[3], 1e-2);
  free(output_data); 
}


TEST(test5_c) {
  QString input_data[8];
  input_data[0] = "50000000"; /// summ
  input_data[1] = "60";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "0" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay_1 = 1062352.24;
  double overpay = 13741134.40;
  double summ = 63741134.40;
  ASSERT_NEAR(month_pay_1, output_data[0], 1e-2);
  ASSERT_NEAR(overpay, output_data[1], 1e-2);
  ASSERT_NEAR(summ, output_data[2], 1e-2);
  free(output_data); 
}


TEST(test6_c) {
  QString input_data[8];
  input_data[0] = "50000000"; /// summ
  input_data[1] = "60";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "1" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay_1 = 1250000.00;
  double month_pay_2 = 840277.78;
  double overpay = 12708333.33;
  double summ = 62708333.33;
  ASSERT_NEAR(month_pay_1, output_data[0], 1e-2);
  ASSERT_NEAR(overpay, output_data[1], 1e-2);
  ASSERT_NEAR(summ, output_data[2], 1e-2);
  ASSERT_NEAR(month_pay_2, output_data[3], 1e-2);
  free(output_data); 
}