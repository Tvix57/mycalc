#ifndef TST_MATH_TEST_H
#define TST_MATH_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "back.h"
#include <QString>
#include <cmath>
#define EPS 1e-6
using namespace testing;

TEST(calc_simple_math_test, math_tes1) {
  QString test1 = "1.23+2.23";
  back test_b(test1);
  double r1 = test_b.calculate();
  double cp1 = 1.23 + 2.23;
  ASSERT_NEAR(r1, cp1, EPS);
}

//TEST(calc_simple_math_test, math_test2) {
//  QString test2 = "1.4356789-2.245";
//  back test_b(test2);
//  double r2 = test_b.calculate();
//  double cp2 = 1.4356789 - 2.245;
//  ASSERT_NEAR(r2, cp2, EPS);
//}

//TEST(calc_simple_math_test, only_number) {
//  QString test3 = "100.456";
//  back test_b(test3);
//  double r3 = test_b.calculate();
//  double cp3 = 100.456;
//  ASSERT_NEAR(r3, cp3, EPS);
//}

//TEST(calc_simple_math_test, only_number_v_brace) {
//  QString test4 = "(100.456)";
//  back test_b(test4);
//  double r4 = test_b.calculate();
//  double cp4 = 100.456;
//  ASSERT_NEAR(r4, cp4, EPS);
//}

//TEST(calc_simple_math_test, math_test3) {
//  QString test5 = "2.1/(1.5+1.678)";
//  back test_b(test5);
//  double r5 = test_b.calculate();
//  double cp5 = 2.1 / (1.5 + 1.678);
//  ASSERT_NEAR(r5, cp5, EPS);
//}

//TEST(calc_simple_math_test, math_test4) {
//  QString test6 = "2.7856*(5.345-2.345)";
//  back test_b(test6)
//  double r6 = test_b.calculate();
//  double cp6 = 2.7856 * (5.345 - 2.345);
//  ASSERT_NEAR(r6, cp6, EPS);
//}

//TEST(test7) {
//  QString test7 = "2.25*(5.67-2.543)";
//  back test_b(test7);
//  double r7 = test_b.calculate();
//  double cp7 = 2.25 * (5.67 - 2.543);
//  ASSERT_NEAR(r7, cp7, EPS);
//}

//TEST(test8) {
//  QString test8 = "(2^2)+(2^2)";
//  back test_b(test8);
//  double r8 = test_b.calculate();
//  double cp8 = pow(2, 2) + pow(2, 2);
//  ASSERT_NEAR(r8, cp8, EPS);
//}

//TEST(test9) {
//  QString test9 = "(2^2)^(2^2)";
//  back test_b(test9);
//  double r9 = test_b.calculate();
//  double cp9 = 256;
//  ASSERT_NEAR(r9, cp9, EPS);
//}

//TEST(test10) {
//  QString test10 = "0%2";
//  back test_b(test10);
//  double r10 = test_b.calculate();
//  double cp_10 = 0;
//  ASSERT_DOUBLE_EQ(r10, cp_10);
//}

//TEST(test11) {
//  QString test11 = "(sqrt(4))";
//  back test_b(test11);
//  double r11 = test_b.calculate();
//  double cp11 = 2;
//  ASSERT_NEAR(r11, cp11, EPS);
//}

//TEST(test12) {
//  QString test12 = "1/0";
//  back test_b(test12);
//  double r12 = test_b.calculate();
//  double cp_error12 = INFINITY;
//  ASSERT_DOUBLE_EQ(r12, cp_error12);
//}

//TEST(test13) {
//  QString test13 = "2%0";
//  back test_b(test13);
//  double r13 = test_b.calculate();
//  ASSERT_DOUBLE_EQ(r13, NAN);
//}

//TEST(test14) {
//  QString test14 = "((((10.987))))";
//  back test_b(test14);
//  double r14 = test_b.calculate();
//  double cp14 = 10.987;
//  ASSERT_NEAR(r14, cp14, EPS);
//}

//TEST(test15) {
//  QString test15 = "sqrt(9)";
//  back test_b(test15);
//  double r15 =  test_b.calculate();
//  double cp15 = 3;
//  ASSERT_NEAR(r15, cp15, EPS);
//}

//TEST(test16) {
//  QString test16 = "10%5";
//  back test_b(test16);
//  double r16 = test_b.calculate();
//  double cp16 = 0;
//  ASSERT_NEAR(r16, cp16, EPS);
//}

//TEST(test17) {
//  QString test17 = "log(10)";
//  double r17 = test_b.calculate()(test17);
//  double cp17 = 1;
//  ASSERT_NEAR(r17, cp17, EPS);
//}


//TEST(test18) {
//  QString test18 = "ln(2.718281828459045)";
//  double r18 = test_b.calculate()(test18);
//  double cp18 = 1;
//  ASSERT_NEAR(r18, cp18, EPS);
//}


//TEST(test19) {
//  QString test19 = "log(-10)";
//  double r19 = test_b.calculate()(test19);
//  ck_assert_double_nan(r19);
//}


//TEST(test20) {
//  QString test20 = "ln(-10)";
//  double r20 = test_b.calculate()(test20);
//  ck_assert_double_nan(r20);
//}


//TEST(test21) {
//  QString test21 = "sqrt(-10)";
//  double r21 = test_b.calculate()(test21);
//  ck_assert_double_nan(r21);
//}


//TEST(test22) {
//  QString test22 = "(-(-(-5)))";
//  double r22 = test_b.calculate()(test22);
//  double cp22 = -5;
//  ASSERT_NEAR(r22, cp22, EPS);
//}


//TEST(test23) {
//  QString test23 = "(-(-(+(+5))))";
//  double r23 = test_b.calculate()(test23);
//  double cp23 = 5;
//  ASSERT_NEAR(r23, cp23, EPS);
//}


//TEST(test24) {
//  QString test24 = "5.25-10.01";
//  double r24 = test_b.calculate()(test24);
//  double cp24 = 5.25 - 10.01;
//  ASSERT_NEAR(r24, cp24, EPS);
//}


//TEST(test25) {
//  QString test25 = "3.01*3.02";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 3.01 * 3.02;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test26) {
//  QString test26 = "9.45/3.26";
//  double r26 = test_b.calculate()(test26);
//  double cp26 = 9.45 / 3.26;
//  ASSERT_NEAR(r26, cp26, EPS);
//}


//TEST(test27) {
//  QString test27 = "0*3";
//  double r27 = test_b.calculate()(test27);
//  double cp27 = 0 * 3;
//  ASSERT_NEAR(r27, cp27, EPS);
//}


//TEST(test28) {
//  QString test28 = "0^(-1)";
//  double r28 = test_b.calculate()(test28);
//  double cp28 = INFINITY;
//  ASSERT_DOUBLE_EQ(r28, cp28);
//}


//TEST(test29) {
//  QString test29 = "ln(0)";
//  double r29 = test_b.calculate()(test29);
//  double cp29 = -INFINITY;
//  ASSERT_DOUBLE_EQ(r29, cp29);
//}


//TEST(test30) {
//  QString test30 = "(-0)";
//  double r30 = test_b.calculate()(test30);
//  double cp30 = 0;
//  ASSERT_NEAR(r30, cp30, EPS);
//}


//TEST(test31) {
//  QString test25 = "(2+2)*6^2";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 144;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test32) {
//  QString test25 = "2*2+6/3";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 6;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test33) {
//  QString test25 = "2^(3+4*5)*(2*2)+2+6/3";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 33554436;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test34) {
//  QString test25 = "sin(2)*2^2+6^2*2";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 75.637189707302724;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test35) {
//  QString test25 = "2.+4";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 6;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test36) {
//  QString test25 = "sin(2-1)*2^2+6^2*2";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 75.365883939231579;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test37) {
//  QString test25 = "2.6+4";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 6.6;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test38) {
//  QString test25 = ".2+5.6";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 5.8;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test39) {
//  QString test25 = "2*(2+4)*2";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 24;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test40) {
//  QString test25 = "(-(-(-5)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -5;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test41) {
//  QString test25 = "(-(-5)))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 5;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test42) {
//  QString test25 = "(-(-(-5)))*(-(-5))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -25;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test43) {
//  QString test25 = "(-2^(3+4*5)*(2*2)+2+6/3";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -33554428;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test44) {
//  QString test25 = "(-2^(3+4*5)*(2*2)+2+6/3)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -33554428;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test45) {
//  QString test25 = "tan(2";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = tan(2);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test46) {
//  char* str = "5+3*sin(10)";
//  double standart = 3.367937;
//  double res = test_b.calculate()(str);
//  ASSERT_NEAR(res, standart, EPS);
//}


//TEST(test47) {
//  char* str = "56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))";
//  double standart = -275;
//  double res = test_b.calculate()(str);
//  ASSERT_NEAR(res, standart, EPS);
//}


//TEST(test48) {
//  char* str = "(15-5)%(5^3)";
//  double standart = 10;
//  double res = test_b.calculate()(str);
//  ASSERT_NEAR(res, standart, EPS);
//}


//TEST(test49) {
//  char* str = "tan(10)*((5-3)*ln(4)-log(8))*2+7";
//  double standart = 9.4242194938376841;
//  double res = test_b.calculate()(str);
//  ASSERT_NEAR(res, standart, EPS);
//}


//TEST(test50) {
//  QString test25 = "12+0.0";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 12;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test51) {
//  QString test25 = "-12+2.34";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -12 + 2.34;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test52) {
//  QString test25 = "100+(-234.";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 100 + -234.;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test53) {
//  QString test25 = "9+(8+6)+1+(3+9)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 9 + (8 + 6) + 1 + (3 + 9);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test54) {
//  QString test25 = "21892683+(-60607476)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 21892683 + (-60607476);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test55) {
//  QString test25 = "416-434-(190-490)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 416 - 434 - (190 - 490);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test56) {
//  QString test25 = "107-(928-166-438)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 107 - (928 - 166 - 438);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test57) {
//  QString test25 = "(399-985)-63-352";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (399 - 985) - 63 - 352;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test58) {
//  QString test25 = "10.7-(0.98-166-438)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 10.7 - (0.98 - 166 - 438);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test59) {
//  QString test25 = "10-(-928-16.6-438)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 10 - (-928 - 16.6 - 438);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test60) {
//  QString test25 = "399-(985-(63-352))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 399 - (985 - (63 - 352));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test61) {
//  QString test25 = "317-141-(118-695)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 317 - 141 - (118 - 695);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test62) {
//  QString test25 = "(3879294-5309583)-(3744311-2467480-4787696)-3324295";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (3879294 - 5309583) - (3744311 - 2467480 - 4787696) - 3324295;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test63) {
//  QString test25 = "(-0.38227*7856.815-0.)*(7759.3*(-51507.96))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (-0.38227 * 7856.815 - 0.) * (7759.3 * -51507.96);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test64) {
//  QString test25 = "6916.08*(-(5855.31*75.6934))*(-(-3272.10*4382.36))"; // 6916.08* (-(443208.321954))*(-(-14339520.156))
//                                                                       // 6916.08* -6355394665966.320304824
//  long double r25 = test_b.calculate()(test25);                               /// -43954417941396344
//  long double cp25 = 6916.08*-(5855.31*75.6934)*-(-3272.10*4382.36); /// -43954417941396348.53378716992
//  ck_assert_ldouble_eq_tol(r25, cp25, (fabsl(cp25)/1e+15) );
//}


//TEST(test65) {
//  QString test25 = "(-816.484*5.2422)*5106.881*(4849.3*401.9244)";
//  long double r25 = test_b.calculate()(test25);
//  long double cp25 = -42603024051457.537604;
//  ck_assert_ldouble_eq_tol(r25, cp25, (fabsl(cp25)/1e+15) );
//}


//TEST(test66) {
//  QString test25 = "(91.226*(-51.9))*(7.797*85.481)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (91.226 * -51.9) * (7.797 * 85.481);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test67) {
//  QString test25 = "(-25.9655*(-(-626.93*508.657)*(85.108*400.162))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -25.9655 * -(-626.93 * 508.657) * (85.108 * 400.162);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test68) {
//  QString test25 = "(-(-356.081*4598.63)*803.928*(70.592*0.1569)*(-36.1566)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * .1569) * -36.1566;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test69) {
//  QString test25 =   "(-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * -.1569) * -36.1566;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test70) {
//  QString test25 = "(432/9.57/321)/(76.4/78.0)/(-35.8";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (432 / 9.57 / 321) / (76.4 / 78.0) / -35.8;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test71) {
//  QString test25 = "43.1/(495.5/711.)/28.7";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 43.1 / (495.5 / 711.) / 28.7;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test72) {
//  QString test25 = "(0.5757/23.3/704.1/(-31.27)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (.5757 / 23.3 / 704.1 / -31.27);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test73) {
//  QString test25 = "(1.375/930.0)/223.3/80.41";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (1.375 / 930.0) / 223.3 / 80.41;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test74) {
//  QString test25 = "4.091/(23.04/1.075/42.8)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 4.091 / (23.04 / 1.075 / 42.8);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test75) {
//  QString test25 = "(7068./33.59/9.13-4)/43.5";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (7068. / 33.59 / 9.13 - 4) / 43.5;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test76) {
//  QString test25 = "97.66/(705.2/2619.)/59.59";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 97.66 / (705.2 / 2619.) / 59.59;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test77) {
//  QString test25 = "97.66/(705.2/2619.)/(-59.59";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 97.66 / (705.2 / 2619.) / -59.59;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test78) {
//  QString test25 = "8^(3^4)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = pow(8, pow(3, 4));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test79) {
//  QString test25 = "(2^9)^1";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = pow(pow(2, 9), 1);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test80) {
//  QString test25 = "65991.*(0.5312*5213.)*(0.9450*897643)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 65991. * (0.5312 * 5213.) * (0.9450 * 897643);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test81) {
//  QString test25 = "2^2^3";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (pow(2, pow(2, 3)));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test82) {
//  QString test25 = "5^(3^3)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (pow(5, pow(3, 3)));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test83) {
//  QString test25 = "(4^10)^3";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = pow(pow(4, 10), 3);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test84) {
//  QString test25 = "(8^2)^8";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = pow(pow(8, 2), 8);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test85) {
//  QString test25 = "(4^10)^3";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = pow(pow(4, 10), 3);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test86) {
//  QString test25 = "(45.34%55.23)%79.4";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = fmod(fmod(45.34, 55.23), 79.4);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test87) {
//  QString test25 = "357.34%(952.34%712.12)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = fmod(357.34, fmod(952.34, 712.12));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test88) {
//  QString test25 = "15.234%(0.52%0.034)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = fmod(15.234, fmod(0.52, 0.034));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test89) {
//  QString test25 = "499.23%(1.8%0.27)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = fmod(499.23, fmod(1.8, 0.27));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test90) {
//  QString test25 = "(72*533+(-615))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (72 * 533 + -615);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test91) {
//  QString test25 = "826-(738-243))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 826 - (738 - +243);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test92) {
//  QString test25 = "17%863*(-173";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 17;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test93) {
//  QString test25 = "40.34*(-0.424/(-252)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 40.34 * (-0.424 / -252);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test94) {
//  QString test25 = "(944%918)/227";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = (fmod(944, 918)) / 227;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test95) {
//  QString test25 = "acos(0.1)*sin(1)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = acos(0.1) * sin(1);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test96) {
//  QString test25 = "cos(-1.34)+tan(2.0)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = cos(-1.34) + tan(2.0);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test97) {
//  QString test25 = "(-(asin(0.3465346)/2)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -(asin(+0.3465346) / 2);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test98) {
//  QString test25 = "atan(1.302+0.5)-1.2";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = atan(1.302 + 0.5) - 1.2;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test99) {
//  QString test25 = "123%sqrt(100)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = fmod(123, sqrt(100));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test100) {
//  QString test25 = "ln(256-3)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = log(256 - 3);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test101) {
//  QString test25 = "log(123.345)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = log10(123.345);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test102) {
//  QString test25 = "(-sin(13.4+atan(7)*56.4-17/4)*(cos(tan(2^4)))";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -sin(13.4 + atan(7) * 56.4 - 17 / 4.0) * (cos(tan(pow(2, 4))));
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test103) {
//  QString test25 = "34.4+34/3";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 45.7333333333333333;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test104) {
//  QString test25 = "34./.4+5";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 34/0.4+5;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test105) {
//  QString test25 = "(-(-34))+5";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 34+5;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test106) {
//  QString test25 = "34*(-5";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 34 * -5;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test107) {
//  QString test25 = "(-(2*2)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -4;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test108) {
//  QString test25 = "(-sin(1)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -sin(1);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test109) {
//  QString test25 = "2%(3)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = fmod(2, 3);
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test110) {
//  QString test25 = "2)+2+2";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = 4;
//  ASSERT_NEAR(r25, cp25, EPS);
//}


//TEST(test111) {
//  QString test25 = "2+(-3)";
//  double r25 = test_b.calculate()(test25);
//  double cp25 = -1;
//  ASSERT_NEAR(r25, cp25, EPS);
//}

#endif // TST_MATH_TEST_H
