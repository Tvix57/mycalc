#ifndef TST_MATH_TEST_H
#define TST_MATH_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../back/math/back.h"
#include <QString>
#include <cmath>
#define EPS 1e-6
using namespace testing;
using namespace s21;

TEST(calc_simple_math_test, math_tes1) {
  QString test1 = "1.23+2.23";
  back test_b(test1);
  double r1 = test_b.calculate();
  double cp1 = 1.23 + 2.23;
  ASSERT_NEAR(r1, cp1, EPS);
}

TEST(calc_simple_math_test, math_test2) {
  QString test2 = "1.4356789-2.245";
  back test_b(test2);
  double r2 = test_b.calculate();
  double cp2 = 1.4356789 - 2.245;
  ASSERT_NEAR(r2, cp2, EPS);
}

TEST(calc_simple_math_test, only_number) {
  QString test3 = "100.456";
  back test_b(test3);
  double r3 = test_b.calculate();
  double cp3 = 100.456;
  ASSERT_NEAR(r3, cp3, EPS);
}

TEST(calc_simple_math_test, only_number_in_brace) {
  QString test4 = "(100.456)";
  back test_b(test4);
  double r4 = test_b.calculate();
  double cp4 = 100.456;
  ASSERT_NEAR(r4, cp4, EPS);
}

TEST(calc_simple_math_test, math_test3) {
  QString test5 = "2.1/(1.5+1.678)";
  back test_b(test5);
  double r5 = test_b.calculate();
  double cp5 = 2.1 / (1.5 + 1.678);
  ASSERT_NEAR(r5, cp5, EPS);
}

TEST(calc_simple_math_test, math_test4) {
  QString test6 = "2.7856*(5.345-2.345)";
  back test_b(test6);
  double r6 = test_b.calculate();
  double cp6 = 2.7856 * (5.345 - 2.345);
  ASSERT_NEAR(r6, cp6, EPS);
}

TEST(calc_simple_math_test, math_test5) {
  QString test7 = "2.25*(5.67-2.543)";
  back test_b(test7);
  double r7 = test_b.calculate();
  double cp7 = 2.25 * (5.67 - 2.543);
  ASSERT_NEAR(r7, cp7, EPS);
}

TEST(calc_medium_math_test, math_test6) {
  QString test8 = "(2^2)+(2^2)";
  back test_b(test8);
  double r8 = test_b.calculate();
  double cp8 = pow(2, 2) + pow(2, 2);
  ASSERT_NEAR(r8, cp8, EPS);
}

TEST(calc_medium_math_test, math_test7) {
  QString test9 = "(2^2)^(2^2)";
  back test_b(test9);
  double r9 = test_b.calculate();
  double cp9 = 256;
  ASSERT_NEAR(r9, cp9, EPS);
}

TEST(calc_simple_math_test, test10) {
  QString test10 = "0%2";
  back test_b(test10);
  double r10 = test_b.calculate();
  double cp_10 = 0;
  ASSERT_DOUBLE_EQ(r10, cp_10);
}

TEST(calc_simple_math_test, test11) {
  QString test11 = "(sqrt(4))";
  back test_b(test11);
  double r11 = test_b.calculate();
  double cp11 = 2;
  ASSERT_NEAR(r11, cp11, EPS);
}

TEST(calc_simple_math_test, zero_dev1) {
  QString test12 = "1/0";
  back test_b(test12);
  double r12 = test_b.calculate();
  double cp_error12 = INFINITY;
  ASSERT_DOUBLE_EQ(r12, cp_error12);
}

TEST(calc_simple_math_test, zero_dev2) {
  QString test13 = "2%0";
  back test_b(test13);
  double r13 = test_b.calculate();
  ASSERT_TRUE(r13 != r13);
}

TEST(calc_simple_math_test, more_branch) {
  QString test14 = "((((10.987))))";
  back test_b(test14);
  double r14 = test_b.calculate();
  double cp14 = 10.987;
  ASSERT_NEAR(r14, cp14, EPS);
}

TEST(calc_simple_math_test, test15) {
  QString test15 = "sqrt(9)";
  back test_b(test15);
  double r15 =  test_b.calculate();
  double cp15 = 3;
  ASSERT_NEAR(r15, cp15, EPS);
}

TEST(calc_simple_math_test, test16) {
  QString test16 = "10%5";
  back test_b(test16);
  double r16 = test_b.calculate();
  double cp16 = 0;
  ASSERT_NEAR(r16, cp16, EPS);
}

TEST(calc_simple_math_test, test17) {
  QString test17 = "log(10)";
  back test_b(test17);
  double r17 = test_b.calculate();
  double cp17 = 1;
  ASSERT_NEAR(r17, cp17, EPS);
}

TEST(calc_simple_math_test, test18) {
  QString test18 = "ln(2.718281828459045)";
  back test_b(test18);
  double r18 = test_b.calculate();
  double cp18 = 1;
  ASSERT_NEAR(r18, cp18, EPS);

}

TEST(calc_simple_math_test, nan_test1) {
  QString test19 = "log(-10)";
  back test_b(test19);
  double r19 = test_b.calculate();
   ASSERT_TRUE(r19 != r19);
}

TEST(calc_simple_math_test, nan_test3) {
  QString test20 = "ln(-10)";
  back test_b(test20);
  double r20 = test_b.calculate();
  ASSERT_TRUE(r20 != r20);
}

TEST(calc_simple_math_test, nan_test2) {
  QString test21 = "sqrt(-10)";
  back test_b(test21);
  double r21 = test_b.calculate();
  ASSERT_TRUE(r21 != r21);
}

TEST(calc_logic_math_test, more_unar_mins) {
  QString test22 = "(-sqrt(2))";
  back test_b(test22);
  double r22 = test_b.calculate();
  double cp22 = -1.4142135623731;
  ASSERT_NEAR(r22, cp22, EPS);
}

TEST(calc_logic_math_test, unar_mins_and_sqrt) {
  QString test22 = "(-sqrt(2"; ////2 sqrt unar
  back test_b(test22);
  double r22 = test_b.calculate();
  double cp22 = -1.4142135623731;
  ASSERT_NEAR(r22, cp22, EPS);
}

TEST(calc_logic_math_test, unar_mins_and_sqrt_branch) {
  QString test22 = "(-(-(-5)))";
  back test_b(test22);
  double r22 = test_b.calculate();
  double cp22 = -5;
  ASSERT_NEAR(r22, cp22, EPS);
}

TEST(calc_logic_math_test, more_unar_mins2) {
  QString test23 = "(-(-(+(+5))))";
  back test_b(test23);
  double r23 = test_b.calculate();
  double cp23 = 5;
  ASSERT_NEAR(r23, cp23, EPS);
}

TEST(calc_simple_math_test, test24) {
  QString test24 = "5.25-10.01";
  back test_b(test24);
  double r24 = test_b.calculate();
  double cp24 = 5.25 - 10.01;
  ASSERT_NEAR(r24, cp24, EPS);
}

TEST(calc_simple_math_test, test25) {
  QString test25 = "3.01*3.02";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 3.01 * 3.02;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test26) {
  QString test26 = "9.45/3.26";
  back test_b(test26);
  double r26 = test_b.calculate();
  double cp26 = 9.45 / 3.26;
  ASSERT_NEAR(r26, cp26, EPS);
}

TEST(calc_simple_math_test, test27) {
  QString test27 = "0*3";
  back test_b(test27);
  double r27 = test_b.calculate();
  double cp27 = 0 * 3;
  ASSERT_NEAR(r27, cp27, EPS);
}

TEST(calc_simple_math_test, test28) {
  QString test28 = "0^(-1)";
  back test_b(test28);
  double r28 = test_b.calculate();
  double cp28 = INFINITY;
  ASSERT_DOUBLE_EQ(r28, cp28);
}

TEST(calc_simple_math_test, test29) {
  QString test29 = "ln(0)";
  back test_b(test29);
  double r29 = test_b.calculate();
  double cp29 = -INFINITY;
  ASSERT_DOUBLE_EQ(r29, cp29);
}

TEST(calc_simple_math_test, test30) {
  QString test30 = "(-0)";
  back test_b(test30);
  double r30 = test_b.calculate();
  double cp30 = 0;
  ASSERT_NEAR(r30, cp30, EPS);
}

TEST(calc_simple_math_test, test31) {
  QString test25 = "(2+2)*6^2";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 144;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test32) {
  QString test25 = "2*2+6/3";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 6;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_medium_math_test, test33) {
  QString test25 = "2^(3+4*5)*(2*2)+2+6/3";
  back test_b(test25); //// 2 3 4 5 * + ^ 2 2 * * 2 + 6 3 / +
  double r25 = test_b.calculate();
  double cp25 = 33554436;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_medium_math_test, test34) {
  QString test25 = "sin(2)*2^2+6^2*2";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 75.637189707302724;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test35) {
  QString test25 = "2.+4";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 6;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_medium_math_test, test36) {
  QString test25 = "sin(2-1)*2^2+6^2*2";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 75.365883939231579;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test37) {
  QString test25 = "2.6+4";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 6.6;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test38) {
  QString test25 = ".2+5.6";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 5.8;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test39) {
  QString test25 = "2*(2+4)*2";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 24;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, more_unar_mins3) {
  QString test25 = "(-(-(-5)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, more_unar_mins4) {
  QString test25 = "(-(-5)))";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, more_unar_mins5) {
  QString test25 = "(-(-(-5)))*(-(-5))"; //// 5 - - - 5 - - *
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -25;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test43) {
  QString test25 = "(-2^(3+4*5)*(2*2)+2+6/3"; ////2 3 4 5 * + ^ 2 2 * * - 2 + 6 3 / +
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -33554428;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test44) {
  QString test25 = "(-2^(3+4*5)*(2*2)+2+6/3)";  //// 2 3 4 5 * + ^ 2 2 * * - 2 + 6 3 / +
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -33554428;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test45) {
  QString test25 = "tan(2";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = tan(2);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test46) {
  QString test25 = "5+3*sin(10)";
  back test_b(test25);
  double standart = 3.367937;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}


TEST(calc_medium_math_test, test47) {
  QString test25 = "56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))";
  back test_b(test25);  /// 56 21 + 376 - 56 22 - + 13 10 + - 11 7 3 2 + - + +
  double standart = -275;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}


TEST(calc_medium_math_test, test48) {
  QString test25 = "(15-5)%(5^3)";
  back test_b(test25);
  double standart = 10;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}


TEST(calc_hard_math_test, test49) {
  QString test25 = "tan(10)*((5-3)*ln(4)-log(8))*2+7";
  back test_b(test25);
  double standart = 9.4242194938376841;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}


TEST(calc_logic_math_test, test50) {
  QString test25 = "12+0.0";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 12;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test51) {
  QString test25 = "(-12+2.34";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -12 + 2.34;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test52) {
  QString test25 = "100+(-234.";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 100 + -234.;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test53) {
  QString test25 = "9+(8+6)+1+(3+9)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 9 + (8 + 6) + 1 + (3 + 9);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test54) {
  QString test25 = "21892683+(-60607476)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 21892683 + (-60607476);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test55) {
  QString test25 = "416-434-(190-490)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 416 - 434 - (190 - 490);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test56) {
  QString test25 = "107-(928-166-438)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 107 - (928 - 166 - 438);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test57) {
  QString test25 = "(399-985)-63-352";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (399 - 985) - 63 - 352;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test58) {
  QString test25 = "10.7-(0.98-166-438)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 10.7 - (0.98 - 166 - 438);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test59) {
  QString test25 = "10-(-928-16.6-438)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 10 - (-928 - 16.6 - 438);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test60) {
  QString test25 = "399-(985-(63-352))";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 399 - (985 - (63 - 352));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test61) {
  QString test25 = "317-141-(118-695)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 317 - 141 - (118 - 695);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test62) {
  QString test25 = "(3879294-5309583)-(3744311-2467480-4787696)-3324295";
  back test_b(test25); //// 3879294 5309583 - 3744311 2467480 - 4787696 - - 3324295 -
  double r25 = test_b.calculate();
  double cp25 = (3879294 - 5309583) - (3744311 - 2467480 - 4787696) - 3324295;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_logic_math_test, test63) {
  QString test25 = "(-0.38227*7856.815-0.)*(7759.3*(-51507.96))";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (-0.38227 * 7856.815 - 0.) * (7759.3 * -51507.96);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_logic_math_test, test64) {
  QString test25 = "6916.08*(-(5855.31*75.6934))*(-(-3272.10*4382.36))"; // 6916.08* (-(443208.321954))*(-(-14339520.156))
                                                                       // 6916.08* -6355394665966.320304824
  back test_b(test25);
  long double r25 = test_b.calculate();                               /// -43954417941396344
  long double cp25 = 6916.08*-(5855.31*75.6934)*-(-3272.10*4382.36); /// -43954417941396348.53378716992
  ASSERT_NEAR(r25, cp25, (fabsl(cp25)/1e+15) );
}


TEST(calc_hard_math_test, test65) {
  QString test25 = "(-816.484*5.2422)*5106.881*(4849.3*401.9244)";
  back test_b(test25);
  long double r25 = test_b.calculate();
  long double cp25 = -42603024051457.537604;
  ASSERT_NEAR(r25, cp25, (fabsl(cp25)/1e+15) );
}


TEST(calc_hard_math_test, test66) {
  QString test25 = "(91.226*(-51.9))*(7.797*85.481)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (91.226 * -51.9) * (7.797 * 85.481);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_math_test, test67) {
  QString test25 = "(-25.9655*(-(-626.93*508.657)*(85.108*400.162))";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -25.9655 * -(-626.93 * 508.657) * (85.108 * 400.162);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_math_test, test68) {
  QString test25 = "(-(-356.081*4598.63)*803.928*(70.592*0.1569)*(-36.1566)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * .1569) * -36.1566;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_math_test, test69) {
  QString test25 =   "(-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * -.1569) * -36.1566;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_math_test, test70) {
  QString test25 = "(432/9.57/321)/(76.4/78.0)/(-35.8";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (432 / 9.57 / 321) / (76.4 / 78.0) / -35.8;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_math_test, test71) {
  QString test25 = "43.1/(495.5/711.)/28.7";
  back test_b(test25);  //// 43.1 495.5 711. / / 28.7 /
  double r25 = test_b.calculate();
  double cp25 = 43.1 / (495.5 / 711.) / 28.7;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_math_test, test72) {
  QString test25 = "(0.5757/23.3/704.1/(-31.27)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (.5757 / 23.3 / 704.1 / -31.27);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test73) {
  QString test25 = "(1.375/930.0)/223.3/80.41";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (1.375 / 930.0) / 223.3 / 80.41;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test74) {
  QString test25 = "4.091/(23.04/1.075/42.8)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 4.091 / (23.04 / 1.075 / 42.8);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test75) {
  QString test25 = "(7068./33.59/9.13-4)/43.5";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (7068. / 33.59 / 9.13 - 4) / 43.5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test76) {
  QString test25 = "97.66/(705.2/2619.)/59.59";
  back test_b(test25); /// 97.66 705.2 2619. / / 59.59 /
  double r25 = test_b.calculate();
  double cp25 = 97.66 / (705.2 / 2619.) / 59.59;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test77) {
  QString test25 = "97.66/(705.2/2619.)/(-59.59";
  back test_b(test25); /// "97.66/(705.2/2619.)/(-59.59
  double r25 = test_b.calculate();
  double cp25 = 97.66 / (705.2 / 2619.) / -59.59;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test78) {
  QString test25 = "8^(3^4)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = pow(8, pow(3, 4));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test79) {
  QString test25 = "(2^9)^1";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = pow(pow(2, 9), 1);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test80) {
  QString test25 = "65991.*(0.5312*5213.)*(0.9450*897643)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 65991. * (0.5312 * 5213.) * (0.9450 * 897643);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test81) {
  QString test25 = "2^2^3";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (pow(2, pow(2, 3)));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test82) {
  QString test25 = "5^(3^3)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (pow(5, pow(3, 3)));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test83) {
  QString test25 = "(4^10)^3";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = pow(pow(4, 10), 3);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test84) {
  QString test25 = "(8^2)^8";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = pow(pow(8, 2), 8);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test85) {
  QString test25 = "(4^10)^3";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = pow(pow(4, 10), 3);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test86) {
  QString test25 = "(45.34%55.23)%79.4";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = fmod(fmod(45.34, 55.23), 79.4);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test87) {
  QString test25 = "357.34%(952.34%712.12)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = fmod(357.34, fmod(952.34, 712.12));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test88) {
  QString test25 = "15.234%(0.52%0.034)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = fmod(15.234, fmod(0.52, 0.034));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test89) {
  QString test25 = "499.23%(1.8%0.27)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = fmod(499.23, fmod(1.8, 0.27));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test90) {
  QString test25 = "(72*533+(-615))";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (72 * 533 + -615);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test91) {
  QString test25 = "826-(738-243))";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 826 - (738 - +243);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test92) {
  QString test25 = "17%863*(-173";
  back test_b(test25); /// 17 863 173 unar * %
  double r25 = test_b.calculate();
  double cp25 = -2941;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test93) {
  QString test25 = "40.34*(-0.424/(-252)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 40.34 * (-0.424 / -252);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test94) {
  QString test25 = "(944%918)/227";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = (fmod(944, 918)) / 227;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test95) {
  QString test25 = "acos(0.1)*sin(1)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = acos(0.1) * sin(1);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test96) {
  QString test25 = "cos(-1.34)+tan(2.0)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = cos(-1.34) + tan(2.0);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_medium_math_test, test97) {
  QString test25 = "(-(asin(0.3465346)/2)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -(asin(+0.3465346) / 2);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test98) {
  QString test25 = "atan(1.302+0.5)-1.2";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = atan(1.302 + 0.5) - 1.2;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test99) {
  QString test25 = "123%sqrt(100)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = fmod(123, sqrt(100));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test100) {
  QString test25 = "ln(256-3)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = log(256 - 3);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test101) {
  QString test25 = "log(123.345)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = log10(123.345);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_hard_math_test, test102) {
  QString test25 = "(-sin(13.4+atan(7)*56.4-17/4)*(cos(tan(2^4)))";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -sin(13.4 + atan(7) * 56.4 - 17 / 4.0) * (cos(tan(pow(2, 4))));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test103) {
  QString test25 = "34.4+34/3";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 45.7333333333333333;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test104) {
  QString test25 = "34./.4+5";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 34/0.4+5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test105) {
  QString test25 = "(-(-34))+5";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 34+5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test106) {
  QString test25 = "34*(-5";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 34 * -5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(calc_simple_math_test, test107) {
  QString test25 = "(-(2*2)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -4;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test108) {
  QString test25 = "(-sin(1)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -sin(1);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test109) {
  QString test25 = "2%(3)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = fmod(2, 3);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test110) {
  QString test25 = "2)+2+2";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = 6;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(calc_simple_math_test, test111) {
  QString test25 = "2+(-3)";
  back test_b(test25);
  double r25 = test_b.calculate();
  double cp25 = -1;
  ASSERT_NEAR(r25, cp25, EPS);
}

#endif // TST_MATH_TEST_H
