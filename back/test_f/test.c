#include <check.h>
#include <math.h>
#include <stdlib.h>
#include "./../backend.h"

#define EPS 0.000001

START_TEST(test1) {
  char *test1 = "1.23+2.23";
  double r1 = main_calc(test1);
  double cp1 = 1.23 + 2.23;
  ck_assert_double_eq_tol(r1, cp1, EPS);
}
END_TEST

START_TEST(test2) {
  char *test2 = "1.4356789-2.245";
  double r2 = main_calc(test2);
  double cp2 = 1.4356789 - 2.245;
  ck_assert_double_eq_tol(r2, cp2, EPS);
}
END_TEST

START_TEST(test3) {
  char *test3 = "100.456";
  double r3 = main_calc(test3);
  double cp3 = 100.456;
  ck_assert_double_eq_tol(r3, cp3, EPS);
}
END_TEST

START_TEST(test4) {
  char *test4 = "(100.456)";
  double r4 = main_calc(test4);
  double cp4 = 100.456;
  ck_assert_double_eq_tol(r4, cp4, EPS);
}
END_TEST

START_TEST(test5) {
  char *test5 = "2.1/(1.5+1.678)";
  double r5 = main_calc(test5);
  double cp5 = 2.1 / (1.5 + 1.678);
  ck_assert_double_eq_tol(r5, cp5, EPS);
}
END_TEST

START_TEST(test6) {
  char *test6 = "2.7856*(5.345-2.345)";
  double r6 = main_calc(test6);
  double cp6 = 2.7856 * (5.345 - 2.345);
  ck_assert_double_eq_tol(r6, cp6, EPS);
}
END_TEST

START_TEST(test7) {
  char *test7 = "2.25*(5.67-2.543)";
  double r7 = main_calc(test7);
  double cp7 = 2.25 * (5.67 - 2.543);
  ck_assert_double_eq_tol(r7, cp7, EPS);
}
END_TEST

START_TEST(test8) {
  char *test8 = "(2^2)+(2^2)";
  double r8 = main_calc(test8);
  double cp8 = pow(2, 2) + pow(2, 2);
  ck_assert_double_eq_tol(r8, cp8, EPS);
}
END_TEST

START_TEST(test9) {
  char *test9 = "(2^2)^(2^2)";
  double r9 = main_calc(test9);
  double cp9 = 256;
  ck_assert_double_eq_tol(r9, cp9, EPS);
}
END_TEST

START_TEST(test10) {
  char *test10 = "0%2";
  double r10 = main_calc(test10);
  double cp_10 = 0;
  ck_assert_double_eq(r10, cp_10);
}
END_TEST

START_TEST(test11) {
  char *test11 = "(sqrt(4))";
  double r11 = main_calc(test11);
  double cp11 = 2;
  ck_assert_double_eq_tol(r11, cp11, EPS);
}
END_TEST

START_TEST(test12) {
  char *test12 = "1/0";
  double r12 = main_calc(test12);
  double cp_error12 = INFINITY;
  ck_assert_double_eq(r12, cp_error12);
}
END_TEST

START_TEST(test13) {
  char *test13 = "2%0";
  double r13 = main_calc(test13);
  ck_assert_double_nan(r13);
}
END_TEST

START_TEST(test14) {
  char *test14 = "((((10.987))))";
  double r14 = main_calc(test14);
  double cp14 = 10.987;
  ck_assert_double_eq_tol(r14, cp14, EPS);
}
END_TEST

START_TEST(test15) {
  char *test15 = "sqrt(9)";
  double r15 =  main_calc(test15);
  double cp15 = 3;
  ck_assert_double_eq_tol(r15, cp15, EPS);
}
END_TEST

START_TEST(test16) {
  char *test16 = "10%5";
  double r16 = main_calc(test16);
  double cp16 = 0;
  ck_assert_double_eq_tol(r16, cp16, EPS);
}
END_TEST

START_TEST(test17) {
  char *test17 = "log(10)";
  double r17 = main_calc(test17);
  double cp17 = 1;
  ck_assert_double_eq_tol(r17, cp17, EPS);
}
END_TEST

START_TEST(test18) {
  char *test18 = "ln(2.718281828459045)";
  double r18 = main_calc(test18);
  double cp18 = 1;
  ck_assert_double_eq_tol(r18, cp18, EPS);
}
END_TEST

START_TEST(test19) {
  char *test19 = "log(-10)";
  double r19 = main_calc(test19);
  ck_assert_double_nan(r19);
}
END_TEST

START_TEST(test20) {
  char *test20 = "ln(-10)";
  double r20 = main_calc(test20);
  ck_assert_double_nan(r20);
}
END_TEST

START_TEST(test21) {
  char *test21 = "sqrt(-10)";
  double r21 = main_calc(test21);
  ck_assert_double_nan(r21);
}
END_TEST

START_TEST(test22) {
  char *test22 = "(-(-(-5)))";
  double r22 = main_calc(test22);
  double cp22 = -5;
  ck_assert_double_eq_tol(r22, cp22, EPS);
}
END_TEST

START_TEST(test23) {
  char *test23 = "(-(-(+(+5))))";
  double r23 = main_calc(test23);
  double cp23 = 5;
  ck_assert_double_eq_tol(r23, cp23, EPS);
}
END_TEST

START_TEST(test24) {
  char *test24 = "5.25-10.01";
  double r24 = main_calc(test24);
  double cp24 = 5.25 - 10.01;
  ck_assert_double_eq_tol(r24, cp24, EPS);
}
END_TEST

START_TEST(test25) {
  char *test25 = "3.01*3.02";
  double r25 = main_calc(test25);
  double cp25 = 3.01 * 3.02;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test26) {
  char *test26 = "9.45/3.26";
  double r26 = main_calc(test26);
  double cp26 = 9.45 / 3.26;
  ck_assert_double_eq_tol(r26, cp26, EPS);
}
END_TEST

START_TEST(test27) {
  char *test27 = "0*3";
  double r27 = main_calc(test27);
  double cp27 = 0 * 3;
  ck_assert_double_eq_tol(r27, cp27, EPS);
}
END_TEST

START_TEST(test28) {
  char *test28 = "0^(-1)";
  double r28 = main_calc(test28);
  double cp28 = INFINITY;
  ck_assert_double_eq(r28, cp28);
}
END_TEST

START_TEST(test29) {
  char *test29 = "ln(0)";
  double r29 = main_calc(test29);
  double cp29 = -INFINITY;
  ck_assert_double_eq(r29, cp29);
}
END_TEST

START_TEST(test30) {
  char *test30 = "(-0)";
  double r30 = main_calc(test30);
  double cp30 = 0;
  ck_assert_double_eq_tol(r30, cp30, EPS);
}
END_TEST

START_TEST(test31) {
  char *test25 = "(2+2)*6^2";
  double r25 = main_calc(test25);
  double cp25 = 144;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test32) {
  char *test25 = "2*2+6/3";
  double r25 = main_calc(test25);
  double cp25 = 6;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test33) {
  char *test25 = "2^(3+4*5)*(2*2)+2+6/3";
  double r25 = main_calc(test25);
  double cp25 = 33554436;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test34) {
  char *test25 = "sin(2)*2^2+6^2*2";
  double r25 = main_calc(test25);
  double cp25 = 75.637189707302724;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test35) {
  char *test25 = "2.+4";
  double r25 = main_calc(test25);
  double cp25 = 6;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test36) {
  char *test25 = "sin(2-1)*2^2+6^2*2";
  double r25 = main_calc(test25);
  double cp25 = 75.365883939231579;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test37) {
  char *test25 = "2.6+4";
  double r25 = main_calc(test25);
  double cp25 = 6.6;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test38) {
  char *test25 = ".2+5.6";
  double r25 = main_calc(test25);
  double cp25 = 5.8;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test39) {
  char *test25 = "2*(2+4)*2";
  double r25 = main_calc(test25);
  double cp25 = 24;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test40) {
  char *test25 = "(-(-(-5)";
  double r25 = main_calc(test25);
  double cp25 = -5;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test41) {
  char *test25 = "(-(-5)))";
  double r25 = main_calc(test25);
  double cp25 = 5;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test42) {
  char *test25 = "(-(-(-5)))*(-(-5))";
  double r25 = main_calc(test25);
  double cp25 = -25;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test43) {
  char *test25 = "(-2^(3+4*5)*(2*2)+2+6/3";
  double r25 = main_calc(test25);
  double cp25 = -33554428;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test44) {
  char *test25 = "(-2^(3+4*5)*(2*2)+2+6/3)";
  double r25 = main_calc(test25);
  double cp25 = -33554428;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test45) {
  char *test25 = "tan(2";
  double r25 = main_calc(test25);
  double cp25 = tan(2);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test46) {
  char* str = "5+3*sin(10)";
  double standart = 3.367937;
  double res = main_calc(str);
  ck_assert_double_eq_tol(res, standart, EPS);
}
END_TEST

START_TEST(test47) {
  char* str = "56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))";
  double standart = -275;
  double res = main_calc(str);
  ck_assert_double_eq_tol(res, standart, EPS);
}
END_TEST

START_TEST(test48) {
  char* str = "(15-5)%(5^3)";
  double standart = 10;
  double res = main_calc(str);
  ck_assert_double_eq_tol(res, standart, EPS);
}
END_TEST

START_TEST(test49) {
  char* str = "tan(10)*((5-3)*ln(4)-log(8))*2+7";
  double standart = 9.4242194938376841;
  double res = main_calc(str);
  ck_assert_double_eq_tol(res, standart, EPS);
}
END_TEST

START_TEST(test50) {
  char *test25 = "12+0.0";
  double r25 = main_calc(test25);
  double cp25 = 12;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test51) {
  char *test25 = "-12+2.34";
  double r25 = main_calc(test25);
  double cp25 = -12 + 2.34;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test52) {
  char *test25 = "100+(-234.";
  double r25 = main_calc(test25);
  double cp25 = 100 + -234.;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test53) {
  char *test25 = "9+(8+6)+1+(3+9)";
  double r25 = main_calc(test25);
  double cp25 = 9 + (8 + 6) + 1 + (3 + 9);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test54) {
  char *test25 = "21892683+(-60607476)";
  double r25 = main_calc(test25);
  double cp25 = 21892683 + (-60607476);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test55) {
  char *test25 = "416-434-(190-490)";
  double r25 = main_calc(test25);
  double cp25 = 416 - 434 - (190 - 490);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test56) {
  char *test25 = "107-(928-166-438)";
  double r25 = main_calc(test25);
  double cp25 = 107 - (928 - 166 - 438);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test57) {
  char *test25 = "(399-985)-63-352";
  double r25 = main_calc(test25);
  double cp25 = (399 - 985) - 63 - 352;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test58) {
  char *test25 = "10.7-(0.98-166-438)";
  double r25 = main_calc(test25);
  double cp25 = 10.7 - (0.98 - 166 - 438);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test59) {
  char *test25 = "10-(-928-16.6-438)";
  double r25 = main_calc(test25);
  double cp25 = 10 - (-928 - 16.6 - 438);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test60) {
  char *test25 = "399-(985-(63-352))";
  double r25 = main_calc(test25);
  double cp25 = 399 - (985 - (63 - 352));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test61) {
  char *test25 = "317-141-(118-695)";
  double r25 = main_calc(test25);
  double cp25 = 317 - 141 - (118 - 695);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test62) {
  char *test25 = "(3879294-5309583)-(3744311-2467480-4787696)-3324295";
  double r25 = main_calc(test25);
  double cp25 = (3879294 - 5309583) - (3744311 - 2467480 - 4787696) - 3324295;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test63) {
  char *test25 = "(-0.38227*7856.815-0.)*(7759.3*(-51507.96))";
  double r25 = main_calc(test25);
  double cp25 = (-0.38227 * 7856.815 - 0.) * (7759.3 * -51507.96);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test64) {
  char *test25 = "6916.08*(-(5855.31*75.6934))*(-(-3272.10*4382.36))"; // 6916.08* (-(443208.321954))*(-(-14339520.156))
                                                                       // 6916.08* -6355394665966.320304824
  long double r25 = main_calc(test25);                               /// -43954417941396344
  long double cp25 = 6916.08*-(5855.31*75.6934)*-(-3272.10*4382.36); /// -43954417941396348.53378716992
  ck_assert_ldouble_eq_tol(r25, cp25, (fabsl(cp25)/1e+15) );
}
END_TEST

START_TEST(test65) {
  char *test25 = "(-816.484*5.2422)*5106.881*(4849.3*401.9244)";
  long double r25 = main_calc(test25);
  long double cp25 = -42603024051457.537604;
  ck_assert_ldouble_eq_tol(r25, cp25, (fabsl(cp25)/1e+15) );
}
END_TEST

START_TEST(test66) {
  char *test25 = "(91.226*(-51.9))*(7.797*85.481)";
  double r25 = main_calc(test25);
  double cp25 = (91.226 * -51.9) * (7.797 * 85.481);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test67) {
  char *test25 = "(-25.9655*(-(-626.93*508.657)*(85.108*400.162))";
  double r25 = main_calc(test25);
  double cp25 = -25.9655 * -(-626.93 * 508.657) * (85.108 * 400.162);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test68) {
  char *test25 = "(-(-356.081*4598.63)*803.928*(70.592*0.1569)*(-36.1566)";
  double r25 = main_calc(test25);
  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * .1569) * -36.1566;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test69) {
  char *test25 =   "(-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566";
  double r25 = main_calc(test25);
  double cp25 = -(-356.081 * 4598.63) * 803.928 * (70.592 * -.1569) * -36.1566;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test70) {
  char *test25 = "(432/9.57/321)/(76.4/78.0)/(-35.8";
  double r25 = main_calc(test25);
  double cp25 = (432 / 9.57 / 321) / (76.4 / 78.0) / -35.8;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test71) {
  char *test25 = "43.1/(495.5/711.)/28.7";
  double r25 = main_calc(test25);
  double cp25 = 43.1 / (495.5 / 711.) / 28.7;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test72) {
  char *test25 = "(0.5757/23.3/704.1/(-31.27)";
  double r25 = main_calc(test25);
  double cp25 = (.5757 / 23.3 / 704.1 / -31.27);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test73) {
  char *test25 = "(1.375/930.0)/223.3/80.41";
  double r25 = main_calc(test25);
  double cp25 = (1.375 / 930.0) / 223.3 / 80.41;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test74) {
  char *test25 = "4.091/(23.04/1.075/42.8)";
  double r25 = main_calc(test25);
  double cp25 = 4.091 / (23.04 / 1.075 / 42.8);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test75) {
  char *test25 = "(7068./33.59/9.13-4)/43.5";
  double r25 = main_calc(test25);
  double cp25 = (7068. / 33.59 / 9.13 - 4) / 43.5;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test76) {
  char *test25 = "97.66/(705.2/2619.)/59.59";
  double r25 = main_calc(test25);
  double cp25 = 97.66 / (705.2 / 2619.) / 59.59;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test77) {
  char *test25 = "97.66/(705.2/2619.)/(-59.59";
  double r25 = main_calc(test25);
  double cp25 = 97.66 / (705.2 / 2619.) / -59.59;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test78) {
  char *test25 = "8^(3^4)";
  double r25 = main_calc(test25);
  double cp25 = pow(8, pow(3, 4));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test79) {
  char *test25 = "(2^9)^1";
  double r25 = main_calc(test25);
  double cp25 = pow(pow(2, 9), 1);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test80) {
  char *test25 = "65991.*(0.5312*5213.)*(0.9450*897643)";
  double r25 = main_calc(test25);
  double cp25 = 65991. * (0.5312 * 5213.) * (0.9450 * 897643);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test81) {
  char *test25 = "2^2^3";
  double r25 = main_calc(test25);
  double cp25 = (pow(2, pow(2, 3)));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test82) {
  char *test25 = "5^(3^3)";
  double r25 = main_calc(test25);
  double cp25 = (pow(5, pow(3, 3)));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test83) {
  char *test25 = "(4^10)^3";
  double r25 = main_calc(test25);
  double cp25 = pow(pow(4, 10), 3);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test84) {
  char *test25 = "(8^2)^8";
  double r25 = main_calc(test25);
  double cp25 = pow(pow(8, 2), 8);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test85) {
  char *test25 = "(4^10)^3";
  double r25 = main_calc(test25);
  double cp25 = pow(pow(4, 10), 3);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test86) {
  char *test25 = "(45.34%55.23)%79.4";
  double r25 = main_calc(test25);
  double cp25 = fmod(fmod(45.34, 55.23), 79.4);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test87) {
  char *test25 = "357.34%(952.34%712.12)";
  double r25 = main_calc(test25);
  double cp25 = fmod(357.34, fmod(952.34, 712.12));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test88) {
  char *test25 = "15.234%(0.52%0.034)";
  double r25 = main_calc(test25);
  double cp25 = fmod(15.234, fmod(0.52, 0.034));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test89) {
  char *test25 = "499.23%(1.8%0.27)";
  double r25 = main_calc(test25);
  double cp25 = fmod(499.23, fmod(1.8, 0.27));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test90) {
  char *test25 = "(72*533+(-615))";
  double r25 = main_calc(test25);
  double cp25 = (72 * 533 + -615);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test91) {
  char *test25 = "826-(738-243))";
  double r25 = main_calc(test25);
  double cp25 = 826 - (738 - +243);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test92) {
  char *test25 = "17%863*(-173";
  double r25 = main_calc(test25);
  double cp25 = 17;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test93) {
  char *test25 = "40.34*(-0.424/(-252)";
  double r25 = main_calc(test25);
  double cp25 = 40.34 * (-0.424 / -252);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test94) {
  char *test25 = "(944%918)/227";
  double r25 = main_calc(test25);
  double cp25 = (fmod(944, 918)) / 227;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test95) {
  char *test25 = "acos(0.1)*sin(1)";
  double r25 = main_calc(test25);
  double cp25 = acos(0.1) * sin(1);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test96) {
  char *test25 = "cos(-1.34)+tan(2.0)";
  double r25 = main_calc(test25);
  double cp25 = cos(-1.34) + tan(2.0);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test97) {
  char *test25 = "(-(asin(0.3465346)/2)";
  double r25 = main_calc(test25);
  double cp25 = -(asin(+0.3465346) / 2);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test98) {
  char *test25 = "atan(1.302+0.5)-1.2";
  double r25 = main_calc(test25);
  double cp25 = atan(1.302 + 0.5) - 1.2;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test99) {
  char *test25 = "123%sqrt(100)";
  double r25 = main_calc(test25);
  double cp25 = fmod(123, sqrt(100));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test100) {
  char *test25 = "ln(256-3)";
  double r25 = main_calc(test25);
  double cp25 = log(256 - 3);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test101) {
  char *test25 = "log(123.345)";
  double r25 = main_calc(test25);
  double cp25 = log10(123.345);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test102) {
  char *test25 = "(-sin(13.4+atan(7)*56.4-17/4)*(cos(tan(2^4)))";
  double r25 = main_calc(test25);
  double cp25 = -sin(13.4 + atan(7) * 56.4 - 17 / 4.0) * (cos(tan(pow(2, 4))));
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test103) {
  char *test25 = "34.4+34/3";
  double r25 = main_calc(test25);
  double cp25 = 45.7333333333333333;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test104) {
  char *test25 = "34./.4+5";
  double r25 = main_calc(test25);
  double cp25 = 34/0.4+5;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test105) {
  char *test25 = "(-(-34))+5";
  double r25 = main_calc(test25);
  double cp25 = 34+5;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test106) {
  char *test25 = "34*(-5";
  double r25 = main_calc(test25);
  double cp25 = 34 * -5;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test107) {
  char *test25 = "(-(2*2)";
  double r25 = main_calc(test25);
  double cp25 = -4;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test108) {
  char *test25 = "(-sin(1)";
  double r25 = main_calc(test25);
  double cp25 = -sin(1);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test109) {
  char *test25 = "2%(3)";
  double r25 = main_calc(test25);
  double cp25 = fmod(2, 3);
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test110) {
  char *test25 = "2)+2+2";
  double r25 = main_calc(test25);
  double cp25 = 4;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

START_TEST(test111) {
  char *test25 = "2+(-3)";
  double r25 = main_calc(test25);
  double cp25 = -1;
  ck_assert_double_eq_tol(r25, cp25, EPS);
}
END_TEST

// START_TEST(test112) {
//   char *test25 = "cos(-10)*sin(-10)*ln(-10)^2";
//   double r25 = main_calc(test25);
//   double cp25 = -1;
//   ck_assert_double_eq_tol(r25, cp25, EPS);
// }
// END_TEST


START_TEST(test1_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test2_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test3_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test4_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test5_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test6_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test7_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test8_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test9_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test10_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test11_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test12_d) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(debit_bill, output_data[2], 1e-2);
  ck_assert_double_eq_tol(debit_nalog, output_data[1], 1e-2);
  ck_assert_double_eq_tol(debit_perc, output_data[0], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test1_c) {
  char *input_data[8];
  input_data[0] = "2000"; /// summ
  input_data[1] = "12";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "0" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay = 175.83;
  double overpay = 109.96;
  double summ = 2109.96;
  ck_assert_double_eq_tol(month_pay, output_data[0], 1e-2);
  ck_assert_double_eq_tol(overpay, output_data[1], 1e-2);
  ck_assert_double_eq_tol(summ, output_data[2], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test2_c) {
  char *input_data[8];
  input_data[0] = "400000"; /// summ
  input_data[1] = "30";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "0" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay = 15124.56;
  double overpay = 53736.80;
  double summ = 453736.80;
  ck_assert_double_eq_tol(month_pay, output_data[0], 1e-2);
  ck_assert_double_eq_tol(overpay, output_data[1], 1e-2);
  ck_assert_double_eq_tol(summ, output_data[2], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test3_c) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(month_pay_1, output_data[0], 1e-2);
  ck_assert_double_eq_tol(overpay, output_data[1], 1e-2);
  ck_assert_double_eq_tol(summ, output_data[2], 1e-2);
  ck_assert_double_eq_tol(month_pay_2, output_data[3], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test4_c) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(month_pay_1, output_data[0], 1e-2);
  ck_assert_double_eq_tol(overpay, output_data[1], 1e-2);
  ck_assert_double_eq_tol(summ, output_data[2], 1e-2);
  ck_assert_double_eq_tol(month_pay_2, output_data[3], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test5_c) {
  char *input_data[8];
  input_data[0] = "50000000"; /// summ
  input_data[1] = "60";  ///  month
  input_data[2] = "10" ;  // percent
  input_data[3] = "0" ;  // percent
  double *output_data;
  output_data = credit_calk(4, input_data);
  double month_pay_1 = 1062352.24;
  double overpay = 13741134.40;
  double summ = 63741134.40;
  ck_assert_double_eq_tol(month_pay_1, output_data[0], 1e-2);
  ck_assert_double_eq_tol(overpay, output_data[1], 1e-2);
  ck_assert_double_eq_tol(summ, output_data[2], 1e-2);
  free(output_data); 
}
END_TEST

START_TEST(test6_c) {
  char *input_data[8];
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
  ck_assert_double_eq_tol(month_pay_1, output_data[0], 1e-2);
  ck_assert_double_eq_tol(overpay, output_data[1], 1e-2);
  ck_assert_double_eq_tol(summ, output_data[2], 1e-2);
  ck_assert_double_eq_tol(month_pay_2, output_data[3], 1e-2);
  free(output_data); 
}
END_TEST

Suite *calc_math(void) {
  Suite *s;
  TCase *tc_math, *debit, *credit;
  s = suite_create("calc_math");
  tc_math = tcase_create("math");
  debit = tcase_create("debit");
  credit = tcase_create("credit");
  tcase_add_test(tc_math, test1);
  tcase_add_test(tc_math, test2);
  tcase_add_test(tc_math, test3);
  tcase_add_test(tc_math, test4);
  tcase_add_test(tc_math, test5);
  tcase_add_test(tc_math, test6);
  tcase_add_test(tc_math, test7);
  tcase_add_test(tc_math, test8);
  tcase_add_test(tc_math, test9);
  tcase_add_test(tc_math, test10);
  tcase_add_test(tc_math, test11);
  tcase_add_test(tc_math, test12);
  tcase_add_test(tc_math, test13);
  tcase_add_test(tc_math, test14);
  tcase_add_test(tc_math, test15);
  tcase_add_test(tc_math, test16);
  tcase_add_test(tc_math, test17);
  tcase_add_test(tc_math, test18);
  tcase_add_test(tc_math, test19);
  tcase_add_test(tc_math, test20);
  tcase_add_test(tc_math, test21);
  tcase_add_test(tc_math, test22);
  tcase_add_test(tc_math, test23);
  tcase_add_test(tc_math, test24);
  tcase_add_test(tc_math, test25);
  tcase_add_test(tc_math, test26);
  tcase_add_test(tc_math, test27);
  tcase_add_test(tc_math, test28);
  tcase_add_test(tc_math, test29);
  tcase_add_test(tc_math, test30);

  tcase_add_test(tc_math, test31);
  tcase_add_test(tc_math, test32);
  tcase_add_test(tc_math, test33);
  tcase_add_test(tc_math, test34);
  tcase_add_test(tc_math, test35);
  tcase_add_test(tc_math, test36);
  tcase_add_test(tc_math, test37);
  tcase_add_test(tc_math, test38);
  tcase_add_test(tc_math, test39);
  tcase_add_test(tc_math, test40);
  tcase_add_test(tc_math, test41);
  tcase_add_test(tc_math, test42);
  tcase_add_test(tc_math, test43);
  tcase_add_test(tc_math, test44);
  tcase_add_test(tc_math, test45);

  tcase_add_test(tc_math, test46);
  tcase_add_test(tc_math, test47);
  tcase_add_test(tc_math, test48);
  tcase_add_test(tc_math, test49);
  tcase_add_test(tc_math, test50);
  tcase_add_test(tc_math, test51);
  tcase_add_test(tc_math, test52);
  tcase_add_test(tc_math, test53);
  tcase_add_test(tc_math, test54);
  tcase_add_test(tc_math, test55);
  tcase_add_test(tc_math, test56);
  tcase_add_test(tc_math, test57);
  tcase_add_test(tc_math, test58);
  tcase_add_test(tc_math, test59);
  tcase_add_test(tc_math, test60);
  tcase_add_test(tc_math, test61);
  tcase_add_test(tc_math, test62);
  tcase_add_test(tc_math, test63);
  tcase_add_test(tc_math, test64);
  tcase_add_test(tc_math, test65);
  tcase_add_test(tc_math, test66);
  tcase_add_test(tc_math, test67);
  tcase_add_test(tc_math, test68);
  tcase_add_test(tc_math, test69);
  tcase_add_test(tc_math, test70);
  tcase_add_test(tc_math, test71);
  tcase_add_test(tc_math, test72);
  tcase_add_test(tc_math, test73);
  tcase_add_test(tc_math, test74);
  tcase_add_test(tc_math, test75);
  tcase_add_test(tc_math, test76);
  tcase_add_test(tc_math, test77);
  tcase_add_test(tc_math, test78);
  tcase_add_test(tc_math, test79);
  tcase_add_test(tc_math, test80);
  tcase_add_test(tc_math, test81);
  tcase_add_test(tc_math, test82);
  tcase_add_test(tc_math, test83);
  tcase_add_test(tc_math, test84);
  tcase_add_test(tc_math, test85);
  tcase_add_test(tc_math, test86);
  tcase_add_test(tc_math, test87);
  tcase_add_test(tc_math, test88);
  tcase_add_test(tc_math, test89);
  tcase_add_test(tc_math, test90);
  tcase_add_test(tc_math, test91);
  tcase_add_test(tc_math, test92);
  tcase_add_test(tc_math, test93);
  tcase_add_test(tc_math, test94);
  tcase_add_test(tc_math, test95);
  tcase_add_test(tc_math, test96);
  tcase_add_test(tc_math, test97);
  tcase_add_test(tc_math, test98);
  tcase_add_test(tc_math, test99);
  tcase_add_test(tc_math, test100);
  tcase_add_test(tc_math, test101);
  tcase_add_test(tc_math, test102);
  tcase_add_test(tc_math, test103);
  tcase_add_test(tc_math, test104);
  tcase_add_test(tc_math, test105);
  tcase_add_test(tc_math, test106);
  tcase_add_test(tc_math, test107);
  tcase_add_test(tc_math, test108);
  tcase_add_test(tc_math, test109);
  // tcase_add_test(tc_math, test110);
  tcase_add_test(tc_math, test111);
  // tcase_add_test(tc_math, test112);

  tcase_add_test(debit, test1_d);
  tcase_add_test(debit, test2_d);
  // tcase_add_test(debit, test3_d);//////
  // tcase_add_test(debit, test4_d);
  // tcase_add_test(debit, test5_d);
  // tcase_add_test(debit, test6_d);
  tcase_add_test(debit, test7_d);
  // tcase_add_test(debit, test8_d);/////
  // tcase_add_test(debit, test9_d);
  // tcase_add_test(debit, test10_d);
  // tcase_add_test(debit, test11_d);
  // tcase_add_test(debit, test12_d);

  tcase_add_test(credit, test1_c);
  tcase_add_test(credit, test2_c);
  tcase_add_test(credit, test3_c);
  tcase_add_test(credit, test4_c);
  tcase_add_test(credit, test5_c);
  tcase_add_test(credit, test6_c);

  suite_add_tcase(s, tc_math);
  suite_add_tcase(s, debit);
  suite_add_tcase(s, credit);
  return s;
}


void calc_test(SRunner **sr) {
  *sr = srunner_create(calc_math());
    
}

int main(void) {
  int number_failed;
  SRunner *sr = NULL;
  calc_test(&sr);
  srunner_run_all(sr, CK_ENV);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
