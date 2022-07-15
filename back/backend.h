#ifndef SRC_BACK_BACKEND_H_
#define SRC_BACK_BACKEND_H_

typedef struct num_node {
  double value;
  struct num_node *next_node;
}num_node_t;

typedef enum {
    ONE_ARG = 0,
    TWO_ARG = 1,
    ZERO_ARG = 2,
} TYPE_FNC;
typedef enum {
    LOW_PRIORITY = 0,
    HIGH_PRIORITY = 1,
    ULTRA = 2,
} CALC_PRIORITY;
typedef struct func_node {
  double (*fnc_ptr)(double, double);
  struct func_node *next_node;
  CALC_PRIORITY priority;
  TYPE_FNC type_fnc;
} func_node_t;



int is_geo(char *str);
int is_math(char *str);
void push_num(double num);
int push_func(char *str);
void pop_num();
void pop_fnc();

func_node_t *cut_fnc_node();
void paste_fnc_node(func_node_t *tmp);
num_node_t *cut_num_node();
void paste_num_node(num_node_t *tmp);

void init_num_stack();
void init_func_stack();
void remove_num_stack();
void remove_func_stack();
void sub_calculate(int CUR_PRIORITY);

double add_fnc(double num1, double num2);
double sub_fnc(double num1, double num2);
double mul_fnc(double num1, double num2);
double div_fnc(double num1, double num2);
double sin_fnc(double num1, double num2);
double cos_fnc(double num1, double num2);
double acos_fnc(double num1, double num2);
double asin_fnc(double num1, double num2);
double tan_fnc(double num1, double num2);
double atan_fnc(double num1, double num2);
double sqrt_fnc(double num1, double num2);
double ln_fnc(double num1, double num2);
double log_fnc(double num1, double num2);
double pow_fnc(double num1, double num2);
double mod_fnc(double num1, double num2);
double unar_min(double num1, double num2);

int parser(char *string);
void scrole_one_num(char **str);
void calculated();

double *credit_calk(int argc, char *argv[]);
double *debit_calk(int argc, char *argv[]);
double main_calc(char *argv);

#endif  //  SRC_BACK_BACKEND_H_
