#include <stdio.h>
#include <stdlib.h>

#include "../../backend.h"

int main() {
    // char *tmp = "sin(inf)";
    // char *tmp = "2*4";
    // char *tmp = "2*2+6"; // 10
    // char *tmp = "2+2*6"; // 14
    // char *tmp = "2+2*6^2"; // 74 
    //  char *tmp = "(2+2)*6^2"; // 144
    // char *tmp = "2*2+6/3"; // 6 
    // char *tmp = "2^(3+4*5)*(2*2)+2+6/3"; // 33554436
    // char *tmp = "sin(2)*2^2+6^2*2"; // 75.637189707302724
    // char *tmp = "sin(2-1)*2^2+6^2*2"; // 75.365883939231579//////
    // char *tmp = "sin(2-1)^2*2+6^(2*2)"; 
    // char *tmp = "(-(-(-5)))";
    // char *tmp = "2.+4";
    // char *tmp = "2.6+4";
    // char *tmp = ".2+5.6";
    // char *tmp = "(2+4)*2";
    // char *tmp = "2+4*2";
    // char *tmp = "2)+2+2";
    // printf("%f\n", main_calc(tmp));
 
    
    char *input_data[8];
    double *output_data;
    int num = 8;
    ///out 1 summ on bill
    ////   2 nalog
    ////   3 percent
    input_data[0] = "2000"; /// summ
    input_data[1] = "100";  ///  day
    input_data[2] = "10" ;  // percent
    input_data[3] = "0";   // nalog
    input_data[4] = "7";   // payrate
    input_data[5] = "1";   // type
    input_data[6] = "0 0 1 3 10 ";   // addition
    input_data[7] = "500 200 1000 -500 200 ";   // substute
    output_data = debit_calk(num, input_data);
    // int num = 4;
    // input_data[0] = "2000"; /// summ
    // input_data[1] = "12";  ///  month
    // input_data[2] = "10" ;  // percent
    // input_data[3] = "0" ;  // percent
    // double *output_data;
    // output_data = credit_calk(num, input_data);
    // num = 3;
    // while (num) {
    //   num--;
    //   printf("%lf\n", output_data[num]);
    // }
    free(output_data);
   return 0;
}