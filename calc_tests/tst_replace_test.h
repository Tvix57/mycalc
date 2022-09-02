#ifndef TST_REPLACE_TEST_H
#define TST_REPLACE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../back/math/back.h"
#include <QString>
#include <cmath>
#define EPS 1e-6
using namespace testing;
using namespace s21;

TEST(X_simple_math_test, test1) {
  QString test25 = "X";
  back test_b(test25);
  test_b.replaceAllX(-1);
  double r25 = test_b.calculate();
  double cp25 = -1;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test2) {
  QString test25 = "X+2-X";
  back test_b(test25);
  test_b.replaceAllX(1);
  double r25 = test_b.calculate();
  double cp25 = 2;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test3) {
  QString test25 = "X+2*3";
  back test_b(test25);
  test_b.replaceAllX(-1);
  double r25 = test_b.calculate();
  double cp25 = 5;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test4) {
  QString test25 = "X+1";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 3;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test5) {
  QString test25 = "2*X";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 4;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test6) {
  QString test25 = "2+X*3";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 8;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test7) {
  QString test25 = "2+3*X";
  back test_b(test25);
  test_b.replaceAllX(3);
  double r25 = test_b.calculate();
  double cp25 = 11;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, only_number_in_brace) {
  QString test4 = "(X)";
  back test_b(test4);
  test_b.replaceAllX(100.456);
  double r4 = test_b.calculate();
  double cp4 = 100.456;
  ASSERT_NEAR(r4, cp4, EPS);
}

TEST(X_simple_math_test, math_test3) {
  QString test5 = "X/(1.5+1.678)";
  back test_b(test5);
  test_b.replaceAllX(2.1);
  double r5 = test_b.calculate();
  double cp5 = 2.1 / (1.5 + 1.678);
  ASSERT_NEAR(r5, cp5, EPS);
}

TEST(X_simple_math_test, math_test4) {
  QString test6 = "2.7856*(X-2.345)";
  back test_b(test6);
  test_b.replaceAllX(5.345);
  double r6 = test_b.calculate();
  double cp6 = 2.7856 * (5.345 - 2.345);
  ASSERT_NEAR(r6, cp6, EPS);
}

TEST(X_simple_math_test, math_test5) {
  QString test7 = "2.25*(5.67-X)";
  back test_b(test7);
  test_b.replaceAllX(2.543);
  double r7 = test_b.calculate();
  double cp7 = 2.25 * (5.67 - 2.543);
  ASSERT_NEAR(r7, cp7, EPS);
}

TEST(X_medium_math_test, math_test6) {
  QString test8 = "(2^X)+(X^2)";
  back test_b(test8);
  test_b.replaceAllX(2);
  double r8 = test_b.calculate();
  double cp8 = pow(2, 2) + pow(2, 2);
  ASSERT_NEAR(r8, cp8, EPS);
}

TEST(X_medium_math_test, math_test7) {
  QString test9 = "(X^2)^(X^2)";
  back test_b(test9);
  test_b.replaceAllX(2);
  double r9 = test_b.calculate();
  double cp9 = 256;
  ASSERT_NEAR(r9, cp9, EPS);
}

TEST(X_simple_math_test, test10) {
  QString test10 = "X%2";
  back test_b(test10);
  test_b.replaceAllX(0);
  double r10 = test_b.calculate();
  double cp_10 = 0;
  ASSERT_DOUBLE_EQ(r10, cp_10);
}

TEST(X_simple_math_test, test11) {
  QString test11 = "(sqrt(X))";
  back test_b(test11);
  test_b.replaceAllX(4);
  double r11 = test_b.calculate();
  double cp11 = 2;
  ASSERT_NEAR(r11, cp11, EPS);
}

TEST(X_simple_math_test, zero_dev1) {
  QString test12 = "1/X";
  back test_b(test12);
  test_b.replaceAllX(0);
  double r12 = test_b.calculate();
  double cp_error12 = INFINITY;
  ASSERT_DOUBLE_EQ(r12, cp_error12);
}

TEST(X_simple_math_test, more_branch) {
  QString test14 = "((((X))))";
  back test_b(test14);
  test_b.replaceAllX(10.987);
  double r14 = test_b.calculate();
  double cp14 = 10.987;
  ASSERT_NEAR(r14, cp14, EPS);
}

TEST(X_simple_math_test, test15) {
  QString test15 = "sqrt(X)";
  back test_b(test15);
  test_b.replaceAllX(9);
  double r15 =  test_b.calculate();
  double cp15 = 3;
  ASSERT_NEAR(r15, cp15, EPS);
}

TEST(X_simple_math_test, test17) {
  QString test17 = "log(X)";
  back test_b(test17);
  test_b.replaceAllX(10);
  double r17 = test_b.calculate();
  double cp17 = 1;
  ASSERT_NEAR(r17, cp17, EPS);
}

TEST(X_simple_math_test, nan_test1) {
  QString test19 = "log(-X)";
  back test_b(test19);
  test_b.replaceAllX(10);
  double r19 = test_b.calculate();
   ASSERT_TRUE(r19 != r19);
}

TEST(X_simple_math_test, nan_test3) {
  QString test20 = "ln(X)";
  back test_b(test20);
  test_b.replaceAllX(-10);
  double r20 = test_b.calculate();
  ASSERT_TRUE(r20 != r20);
}

TEST(X_hard_math_test, more_unar_mins) {
  QString test22 = "(-(-(X)))";
  back test_b(test22);
  test_b.replaceAllX(-5);
  double r22 = test_b.calculate();
  double cp22 = -5;
  ASSERT_NEAR(r22, cp22, EPS);
}


TEST(X_simple_math_test, test28) {
  QString test28 = "0^(-X)";
  back test_b(test28);
  test_b.replaceAllX(1);
  double r28 = test_b.calculate();
  double cp28 = INFINITY;
  ASSERT_DOUBLE_EQ(r28, cp28);
}

TEST(X_simple_math_test, test30) {
  QString test30 = "(-X)";
  back test_b(test30);
  test_b.replaceAllX(0);
  double r30 = test_b.calculate();
  double cp30 = 0;
  ASSERT_NEAR(r30, cp30, EPS);
}

TEST(X_simple_math_test, test31) {
  QString test25 = "(X+X)*6^X";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 144;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test32) {
  QString test25 = "X*X+6/3";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 6;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test33) {
  QString test25 = "X^(3+4*5)*(X*X)+X+6/3";
  back test_b(test25); //// 2 3 4 5 * + ^ 2 2 * * 2 + 6 3 / +
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 33554436;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test34) {
  QString test25 = "sin(X)*2^X+6^X*2";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 75.637189707302724;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test36) {
  QString test25 = "sin(X-1)*X^2+6^X*2";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 75.365883939231579;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test39) {
  QString test25 = "X*(X+4)*X";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 24;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, more_unar_mins3) {
  QString test25 = "(-(-(-X)";
  back test_b(test25);
  test_b.replaceAllX(5);
  double r25 = test_b.calculate();
  double cp25 = -5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, more_unar_mins4) {
  QString test25 = "(-(-X)))";
  back test_b(test25);
  test_b.replaceAllX(5);
  double r25 = test_b.calculate();
  double cp25 = 5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, more_unar_mins5) {
  QString test25 = "(-(-(-X)))*(-(-X))"; //// 5 - - - 5 - - *
  back test_b(test25);
  test_b.replaceAllX(5);
  double r25 = test_b.calculate();
  double cp25 = -25;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test43) {
  QString test25 = "(-X^(3+4*5)*(2*X)+X+6/3"; ////2 3 4 5 * + ^ 2 2 * * - 2 + 6 3 / +
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = -33554428;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test44) {
  QString test25 = "(-2^(X+4*5)*(2*2)+2+6/X)";  //// 2 3 4 5 * + ^ 2 2 * * - 2 + 6 3 / +
  back test_b(test25);
  test_b.replaceAllX(3);
  double r25 = test_b.calculate();
  double cp25 = -33554428;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test45) {
  QString test25 = "tan(X";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = tan(2);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_simple_math_test, test46) {
  QString test25 = "5+3*sin(X)";
  back test_b(test25);
  test_b.replaceAllX(10);
  double standart = 3.367937;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}


TEST(X_medium_math_test, test47) {
  QString test25 = "56+21-376+(56-22)-(X+10)+(11+(7-(3+2)))";
  back test_b(test25);  /// 56 21 + 376 - 56 22 - + 13 10 + - 11 7 3 2 + - + +
  test_b.replaceAllX(13);
  double standart = -275;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}


TEST(X_medium_math_test, test48) {
  QString test25 = "(15-X)%(X^3)";
  back test_b(test25);
  test_b.replaceAllX(5);
  double standart = 10;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}

TEST(X_hard_math_test, test49) {
  QString test25 = "tan(10)*((X-3)*ln(4)-log(8))*2+7";
  back test_b(test25);
  test_b.replaceAllX(5);
  double standart = 9.4242194938376841;
  double res = test_b.calculate();
  ASSERT_NEAR(res, standart, EPS);
}

TEST(X_hard_math_test, test51) {
  QString test25 = "(-X+2.34";
  back test_b(test25);
  test_b.replaceAllX(12);
  double r25 = test_b.calculate();
  double cp25 = -12 + 2.34;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test53) {
  QString test25 = "9+(8+X)+1+(3+9)";
  back test_b(test25);
  test_b.replaceAllX(6);
  double r25 = test_b.calculate();
  double cp25 = 9 + (8 + 6) + 1 + (3 + 9);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_hard_math_test, test55) {
  QString test25 = "416-434-(X-490)";
  back test_b(test25);
  test_b.replaceAllX(190);
  double r25 = test_b.calculate();
  double cp25 = 416 - 434 - (190 - 490);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_hard_math_test, test56) {
  QString test25 = "107-(928-X-438)";
  back test_b(test25);
  test_b.replaceAllX(166);
  double r25 = test_b.calculate();
  double cp25 = 107 - (928 - 166 - 438);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_hard_math_test, test57) {
  QString test25 = "(399-985)-X-352";
  back test_b(test25);
  test_b.replaceAllX(63);
  double r25 = test_b.calculate();
  double cp25 = (399 - 985) - 63 - 352;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_hard_math_test, test59) {
  QString test25 = "10-(-X-16.6-438)";
  back test_b(test25);
  test_b.replaceAllX(928);
  double r25 = test_b.calculate();
  double cp25 = 10 - (-928 - 16.6 - 438);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test60) {
  QString test25 = "399-(X-(63-352))";
  back test_b(test25);
  test_b.replaceAllX(985);
  double r25 = test_b.calculate();
  double cp25 = 399 - (985 - (63 - 352));
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test61) {
  QString test25 = "317-141-(118-X)";
  back test_b(test25);
  test_b.replaceAllX(695);
  double r25 = test_b.calculate();
  double cp25 = 317 - 141 - (118 - 695);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test62) {
  QString test25 = "(3879294-5309583)-(X-2467480-4787696)-X";
  back test_b(test25); //// 3879294 5309583 - 3744311 2467480 - 4787696 - - 3324295 -
  test_b.replaceAllX(3324295);
  double r25 = test_b.calculate();
  double cp25 = (3879294 - 5309583) - (3324295 - 2467480 - 4787696) - 3324295;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_hard_math_test, test64) {
  QString test25 = "6916.08*(-(X*75.6934))*(-(-X*4382.36))"; // 6916.08* (-(443208.321954))*(-(-14339520.156))
                                                                       // 6916.08* -6355394665966.320304824
  back test_b(test25);
  test_b.replaceAllX(3272.10);
  long double r25 = test_b.calculate();                               /// -43954417941396344
  long double cp25 = 6916.08*-(3272.10*75.6934)*-(-3272.10*4382.36); /// -43954417941396348.53378716992
  ASSERT_NEAR(r25, cp25, (fabsl(cp25)/1e+15) );
}

TEST(X_hard_math_test, test66) {
  QString test25 = "(X*(-51.9))*(X*85.481)";
  back test_b(test25);
  test_b.replaceAllX(-7.797);
  double r25 = test_b.calculate();
  double cp25 = (-7.797 * -51.9) * (-7.797 * 85.481);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test67) {
  QString test25 = "(X*(-(-626.93*508.657)*(X*400.162))";
  back test_b(test25);
  test_b.replaceAllX(-25.9655);
  double r25 = test_b.calculate();
  double cp25 = -25.9655 * -(-626.93 * 508.657) * (-25.9655 * 400.162);
  ASSERT_DOUBLE_EQ(r25, cp25);
}


TEST(X_hard_math_test, test68) {
  QString test25 = "(-(-356.081*4598.63)*X*(70.592*0.1569)*(-36.1566)";
  back test_b(test25);
  test_b.replaceAllX(803.928);
  double r25 = test_b.calculate();
  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * .1569) * -36.1566;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test69) {
  QString test25 =   "(-(-356.081*4598.63)*803.928*(X*(-0.1569))*(-36.1566";
  back test_b(test25);
  test_b.replaceAllX(70.592);
  double r25 = test_b.calculate();
  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * -.1569) * -36.1566;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test70) {
  QString test25 = "(432/X/321)/(76.4/78.0)/(-35.8";
  back test_b(test25);
  test_b.replaceAllX(9.57);
  double r25 = test_b.calculate();
  double cp25 = (432 / 9.57 / 321) / (76.4 / 78.0) / -35.8;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test71) {
  QString test25 = "43.1/(X/711.)/28.7";
  back test_b(test25);  //// 43.1 495.5 711. / / 28.7 /
  test_b.replaceAllX(495.5);
  double r25 = test_b.calculate();
  double cp25 = 43.1 / (495.5 / 711.) / 28.7;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_hard_math_test, test72) {
  QString test25 = "(0.5757/23.3/X/(-31.27)";
  back test_b(test25);
  test_b.replaceAllX(704.1);
  double r25 = test_b.calculate();
  double cp25 = (.5757 / 23.3 / 704.1 / -31.27);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test73) {
  QString test25 = "(1.375/930.0)/223.3/X";
  back test_b(test25);
  test_b.replaceAllX(80.41);
  double r25 = test_b.calculate();
  double cp25 = (1.375 / 930.0) / 223.3 / 80.41;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test74) {
  QString test25 = "X/(23.04/1.075/42.8)";
  back test_b(test25);
  test_b.replaceAllX(4.091);
  double r25 = test_b.calculate();
  double cp25 = 4.091 / (23.04 / 1.075 / 42.8);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test75) {
  QString test25 = "(7068./33.59/9.13-4)/X";
  back test_b(test25);
  test_b.replaceAllX(43.5);
  double r25 = test_b.calculate();
  double cp25 = (7068. / 33.59 / 9.13 - 4) / 43.5;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test76) {
  QString test25 = "97.66/(X/2619.)/59.59";
  back test_b(test25); /// 97.66 705.2 2619. / / 59.59 /
  test_b.replaceAllX(705.2);
  double r25 = test_b.calculate();
  double cp25 = 97.66 / (705.2 / 2619.) / 59.59;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test77) {
  QString test25 = "97.66/(705.2/2619.)/(X";
  back test_b(test25); /// "97.66/(705.2/2619.)/(-59.59
  test_b.replaceAllX(-59.59);
  double r25 = test_b.calculate();
  double cp25 = 97.66 / (705.2 / 2619.) / -59.59;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test78) {
  QString test25 = "8^(X^4)";
  back test_b(test25);
  test_b.replaceAllX(3);
  double r25 = test_b.calculate();
  double cp25 = pow(8, pow(3, 4));
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test79) {
  QString test25 = "(2^9)^X";
  back test_b(test25);
  test_b.replaceAllX(1);
  double r25 = test_b.calculate();
  double cp25 = pow(pow(2, 9), 1);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test81) {
  QString test25 = "X^X^3";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = (pow(2, pow(2, 3)));
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test82) {
  QString test25 = "5^(X^X)";
  back test_b(test25);
  test_b.replaceAllX(3);
  double r25 = test_b.calculate();
  double cp25 = (pow(5, pow(3, 3)));
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test84) {
  QString test25 = "(X^2)^X";
  back test_b(test25);
  test_b.replaceAllX(8);
  double r25 = test_b.calculate();
  double cp25 = pow(pow(8, 2), 8);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test85) {
  QString test25 = "(X^10)^3";
  back test_b(test25);
  test_b.replaceAllX(4);
  double r25 = test_b.calculate();
  double cp25 = pow(pow(4, 10), 3);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test86) {
  QString test25 = "(45.34%X)%79.4";
  back test_b(test25);
  test_b.replaceAllX(55.23);
  double r25 = test_b.calculate();
  double cp25 = fmod(fmod(45.34, 55.23), 79.4);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test87) {
  QString test25 = "X%(952.34%712.12)";
  back test_b(test25);
  test_b.replaceAllX(357.34);
  double r25 = test_b.calculate();
  double cp25 = fmod(357.34, fmod(952.34, 712.12));
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test90) {
  QString test25 = "(X*533+(-615))";
  back test_b(test25);
  test_b.replaceAllX(72);
  double r25 = test_b.calculate();
  double cp25 = (72 * 533 + -615);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test91) {
  QString test25 = "826-(X-243))";
  back test_b(test25);
  test_b.replaceAllX(738);
  double r25 = test_b.calculate();
  double cp25 = 826 - (738 - +243);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_medium_math_test, test93) {
  QString test25 = "40.34*(-0.424/(X)";
  back test_b(test25);
  test_b.replaceAllX(-252);
  double r25 = test_b.calculate();
  double cp25 = 40.34 * (-0.424 / -252);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test94) {
  QString test25 = "(X%918)/227";
  back test_b(test25);
  test_b.replaceAllX(944);
  double r25 = test_b.calculate();
  double cp25 = (fmod(944, 918)) / 227;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_simple_math_test, test95) {
  QString test25 = "acos(X)*sin(X)";
  back test_b(test25);
  test_b.replaceAllX(0.1);
  double r25 = test_b.calculate();
  double cp25 = acos(0.1) * sin(0.1);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_simple_math_test, test96) {
  QString test25 = "cos(-X)+tan(X)";
  back test_b(test25);
  test_b.replaceAllX(1.34);
  double r25 = test_b.calculate();
  double cp25 = cos(-1.34) + tan(1.34);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_medium_math_test, test97) {
  QString test25 = "(-(asin(0.3465346)/X)";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = -(asin(+0.3465346) / 2);
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_simple_math_test, test98) {
  QString test25 = "atan(1.302+0.5)-X";
  back test_b(test25);
  test_b.replaceAllX(1.2);
  double r25 = test_b.calculate();
  double cp25 = atan(1.302 + 0.5) - 1.2;
  ASSERT_NEAR(r25, cp25, EPS);
}


TEST(X_simple_math_test, test99) {
  QString test25 = "X%sqrt(100)";
  back test_b(test25);
  test_b.replaceAllX(123);
  double r25 = test_b.calculate();
  double cp25 = fmod(123, sqrt(100));
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test100) {
  QString test25 = "ln(256-X)";
  back test_b(test25);
  test_b.replaceAllX(3);
  double r25 = test_b.calculate();
  double cp25 = log(256 - 3);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_hard_math_test, test102) {
  QString test25 = "(-sin(13.4+atan(7)*56.4-17/X)*(cos(tan(2^X)))";
  back test_b(test25);
  test_b.replaceAllX(4);
  double r25 = test_b.calculate();
  double cp25 = -sin(13.4 + atan(7) * 56.4 - 17 / 4.0) * (cos(tan(pow(2, 4))));
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test105) {
  QString test25 = "(-(-X))+5";
  back test_b(test25);
  test_b.replaceAllX(34);
  double r25 = test_b.calculate();
  double cp25 = 34+5;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test106) {
  QString test25 = "X*(-5";
  back test_b(test25);
  test_b.replaceAllX(34);
  double r25 = test_b.calculate();
  double cp25 = 34 * -5;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test107) {
  QString test25 = "(-(2*X)";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = -4;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test108) {
  QString test25 = "(-sin(X)";
  back test_b(test25);
  test_b.replaceAllX(1);
  double r25 = test_b.calculate();
  double cp25 = -sin(1);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test109) {
  QString test25 = "2%(X)";
  back test_b(test25);
  test_b.replaceAllX(3);
  double r25 = test_b.calculate();
  double cp25 = fmod(2, 3);
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test110) {
  QString test25 = "2)+X+2";
  back test_b(test25);
  test_b.replaceAllX(2);
  double r25 = test_b.calculate();
  double cp25 = 6;
  ASSERT_NEAR(r25, cp25, EPS);
}

TEST(X_simple_math_test, test111) {
  QString test25 = "2+(-X)";
  back test_b(test25);
  test_b.replaceAllX(3);
  double r25 = test_b.calculate();
  double cp25 = -1;
  ASSERT_NEAR(r25, cp25, EPS);
}

#endif // TST_REPLACE_TEST_H
