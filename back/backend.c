#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "backend.h"

func_node_t *func_stac;
num_node_t *num_stac;

void scrole_one_num(char **str) {
  char *num = "0123456789";
  while (*str && **str != '\0' && **str != EOF) {
    char *tmp = *str;
    if (strchr(num, *tmp)) {
      *str = tmp+1;
    } else if (**str == '.') {
      *str = tmp+1;
    } else if (**str == 'e' || **str == 'E') {
      tmp++;
      if (*tmp == '+' || *tmp == '-') {
      tmp++;
      }
      *str = tmp;
    } else  if (!strncmp(*str, "inf", 3)) {
      *str += 3;
    } else  if (!strncmp(*str, "-inf", 3)) {
      *str += 4;
    } else {
      break;
    }
  }
}

int parser(char *string) {
  double num  = 0;
  int CUR_PRIORITY = 0;
  for (; string != NULL && *string != '\0' && *string != EOF;) {
    if (sscanf(string, "%lf", &num)) {
      if ((*string == '+' || *string == '-')) {
        if (*(string-1) != '(') {
          CUR_PRIORITY = func_stac->priority;
            push_func("+");
          if (CUR_PRIORITY > func_stac->priority && func_stac->type_fnc != ZERO_ARG) {
              sub_calculate(CUR_PRIORITY);
          }
        } else {
          if (func_stac->fnc_ptr == unar_min) {
            num *=-1;
            pop_fnc();
          }
        }

      string++;
      }
      if (func_stac->fnc_ptr == unar_min) {
        num *=-1;
        pop_fnc();
      }
      push_num(num);
      if (func_stac->fnc_ptr == div_fnc) {
        calculated();
      }
      num = 0;
      scrole_one_num(&string);
    } else {
      if (func_stac->next_node != NULL) {
        CUR_PRIORITY = func_stac->priority;
      }
      int lengh = 0;
      if (string != NULL && *string != '\0') {
        lengh = push_func(string);
      if (lengh) {
        if (CUR_PRIORITY > func_stac->priority && func_stac->type_fnc != ZERO_ARG) {
          sub_calculate(CUR_PRIORITY);
        }
        string += lengh;
      }
    }
    if (string != NULL && *string != '\0') {
      if (!lengh) {
        switch (*string) {
        case ')':
          string++;
          while (func_stac->type_fnc != ZERO_ARG && func_stac->next_node != NULL) {
            calculated();
          }
          if (func_stac->next_node == NULL) {
            return 1;
          } else {
            pop_fnc();
          }
          if (func_stac->type_fnc == ONE_ARG) {
            calculated();
          } else if  (func_stac->fnc_ptr == div_fnc) {
            calculated();
          } else if (func_stac->fnc_ptr == sub_fnc) {
            num_stac->value *=-1;
            pop_fnc();
            push_func("+");
          }
          break;
        default:
          return 1;
        }
      }
    }
    }
  }
  return 0;
}
void sub_calculate(int CUR_PRIORITY ) {
  func_node_t *tmp = cut_fnc_node();
  if (func_stac->type_fnc != ZERO_ARG) {
    do {
      calculated();
    } while (func_stac->priority > tmp->priority && func_stac->next_node != NULL &&
             func_stac->type_fnc != ZERO_ARG);
  }
  paste_fnc_node(tmp);
}

int is_geo(char *str) {
  int result = 0;
  if (*str == 'a') {
    if (*(str+1) != '\0') {
    str++;
    result++;
    } else {
      return result;
    }
  }
  char fnc_arr[3][4] = {{"sin\0"}, {"cos\0"}, {"tan\0"}};
  for (int i = 0; i < 3; i++) {
    if (!strncmp(str, fnc_arr[i], 3)) {
      func_stac->priority = ULTRA;
      switch (i) {
      case 0:
        if (result == 1) {
          func_stac->fnc_ptr = asin_fnc;
        } else {
          func_stac->fnc_ptr = sin_fnc;
        }
        break;
      case 1:
        if (result == 1) {
          func_stac->fnc_ptr = acos_fnc;
        } else {
          func_stac->fnc_ptr = cos_fnc;
        }
        break;
      case 2:
        if (result == 1) {
          func_stac->fnc_ptr = atan_fnc;
        } else {
          func_stac->fnc_ptr = tan_fnc;
        }
        break;
      default:
        break;
      }
      result += 3;
      break;
    }
  }
  if (result == 1) {
    result = 0;
  }
  return result;
}

int is_math(char *str) {
  int result = 0;
  char fnc_arr[3][5] = {{"log\0"}, {"ln\0"}, {"sqrt\0"}};
  for (int i = 0; i < 3; i++) {
    int len = strlen(fnc_arr[i]);
    if (!strncmp(str, fnc_arr[i], len)) {
      func_stac->priority = HIGH_PRIORITY;
      switch (i) {
      case 0:
        func_stac->fnc_ptr = log_fnc;
        break;
      case 1:
          func_stac->fnc_ptr = ln_fnc;
        break;
      case 2:
          func_stac->fnc_ptr = sqrt_fnc;
        break;
      default:
        break;
      }
      result += len;
      break;
    }
  }
  return result;
}

void push_num(double num) {
  num_node_t *new_node = (num_node_t *)calloc(1, sizeof(num_node_t));
  new_node->value = num;
  new_node->next_node = num_stac;
  num_stac = new_node;
}

int push_func(char *str) {
  int lengh_to_scrol = 0;
  func_node_t *new_node = (func_node_t *)calloc(1, sizeof(func_node_t));
  new_node->next_node = func_stac;
  func_stac = new_node;
  func_stac->type_fnc = ONE_ARG;
  switch (*str) {
    case '(':
      lengh_to_scrol++;
      func_stac->type_fnc = ZERO_ARG;
      func_stac->priority = HIGH_PRIORITY;
      if (*(str+1) == '-') {
        func_node_t *new_node = (func_node_t *)calloc(1, sizeof(func_node_t));
        new_node->next_node = func_stac;
        func_stac = new_node;
        func_stac->type_fnc = ONE_ARG;
        func_stac->fnc_ptr = unar_min;
        func_stac->priority = LOW_PRIORITY;
        lengh_to_scrol++;
      }
      break;
    case '+':
    case '-':
      if (*str == '+') {
        func_stac->fnc_ptr = add_fnc;
      } else {
        func_stac->fnc_ptr = sub_fnc;
      }
      func_stac->type_fnc = TWO_ARG;
      func_stac->priority = LOW_PRIORITY;
      lengh_to_scrol++;
      break;
    case '*':
    case '/':
    case '%':
      if (*str == '*') {
        func_stac->fnc_ptr = mul_fnc;
      } else if (*str == '%') {
        func_stac->fnc_ptr = mod_fnc;
      } else {
        func_stac->fnc_ptr = div_fnc;
      }
      func_stac->type_fnc = TWO_ARG;
      func_stac->priority = HIGH_PRIORITY;
      lengh_to_scrol++;
      break;
    case '^':
      func_stac->fnc_ptr = pow_fnc;
      func_stac->type_fnc = TWO_ARG;
      func_stac->priority = ULTRA;
      lengh_to_scrol++;
    default:
      break;
  }
  if (!lengh_to_scrol) {
    lengh_to_scrol = is_geo(str);
  }
  if (!lengh_to_scrol) {
    lengh_to_scrol = is_math(str);
  }
  if (!lengh_to_scrol) {
    pop_fnc();
  }
  return lengh_to_scrol;
}

void pop_num() {
  if (num_stac->next_node != NULL) {
    num_node_t *tmp = num_stac;
    num_stac = num_stac->next_node;
    free(tmp);
  }
}
void pop_fnc() {
  if (func_stac->next_node != NULL) {
    func_node_t *tmp = func_stac;
    func_stac = func_stac->next_node;
    free(tmp);
  }
}

func_node_t *cut_fnc_node() {
  func_node_t *tmp = func_stac;
  func_stac = func_stac->next_node;
  return tmp;
}
void paste_fnc_node(func_node_t *tmp) {
  tmp->next_node = func_stac;
  func_stac = tmp;
}

num_node_t *cut_num_node() {
  num_node_t *tmp = num_stac;
  num_stac = num_stac->next_node;
  return tmp;
}
void paste_num_node(num_node_t *tmp) {
  tmp->next_node = num_stac;
  num_stac = tmp;
}

void init_num_stack() {
  num_stac = (num_node_t *)calloc(1, sizeof(num_node_t));
  num_stac->next_node = NULL;
  num_stac->value = 0;
}
void init_func_stack() {
  func_stac = (func_node_t *)calloc(1, sizeof(func_node_t));
  func_stac->next_node = NULL;
  func_stac->priority = LOW_PRIORITY;
  func_stac->type_fnc = TWO_ARG;
  func_stac->fnc_ptr = add_fnc;
}
void remove_num_stack() {
  while (num_stac->next_node != NULL) {
    pop_num();
  }
  free(num_stac);
}
void remove_func_stack() {
  while (func_stac->next_node != NULL) {
    pop_fnc();
  }
  free(func_stac);
}

double add_fnc(double num1, double num2) {
  return num1 + num2;
}
double sub_fnc(double num1, double num2) {
  return num1 - num2;
}
double mul_fnc(double num1, double num2) {
  return num1 * num2;
}
double div_fnc(double num1, double num2) {
  return num1 / num2;
}
double sin_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return sin(num1);
    } else {
      return NAN;
    }
}
double cos_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return cos(num1);
    } else {
      return NAN;
    }
}
double acos_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return acos(num1);
    } else {
      return NAN;
    }
}
double asin_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return asin(num1);
    } else {
      return NAN;
    }
}
double tan_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return tan(num1);
    } else {
      return NAN;
    }
}
double atan_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return atan(num1);
    } else {
      return NAN;
    }
}
double sqrt_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return sqrt(num1);
    } else {
      return NAN;
    }
}
double ln_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return log(num1);
    } else {
      return NAN;
    }
}
double log_fnc(double num1, double num2) {
    if (num2 != NAN) {
      return log10(num1);
    } else {
      return NAN;
    }
}
double pow_fnc(double num1, double num2) {
  return pow(num1, num2);
}
double mod_fnc(double num1, double num2) {
  return fmod(num1, num2);
}
double unar_min(double num1, double num2) {
  return num1*-1;
}
void calculated() {
    if (func_stac->type_fnc < 2) {
      if (func_stac->type_fnc) {
        double tmp = num_stac->value;
        pop_num();
        num_stac->value = func_stac->fnc_ptr(num_stac->value, tmp);
      } else {
        num_stac->value = func_stac->fnc_ptr(num_stac->value, NAN);
      }
    pop_fnc();
  }
}

double main_calc(char *argv) {
  double result = NAN;
  init_num_stack();
  init_func_stack();
  parser(argv);
  while (func_stac->next_node != NULL) {
    calculated();
    if (func_stac->type_fnc == ZERO_ARG) {
      pop_fnc();
    }
  }
  result = num_stac->value;
  remove_func_stack();
  remove_num_stack();
  return result;
}

double *credit_calk(int argc, char *argv[]) {
  double *result = calloc(4, sizeof(double));  //  1- первый платеж 3 - последний платеж //type - 1 differ
  if (argc != 4) {
    result[0] = NAN;
  } else {
    char spec_arr[4][3] = {{"%lf"}, {"%d"}, {"%lf"}, {"%d"}};
    double summ = 0;
    int month = 0;
    double percent = 0;
    int type = 0;
    void *data_ptr[4] = {&summ, &month, &percent, &type};
    while (argc) {
      argc--;
      if (!sscanf(argv[argc], spec_arr[argc], data_ptr[argc])) {
        result[0] = NAN;
        break;
      }
    }
    percent /=12;
    percent /=100;
    if (type) {
      double credit_part = summ / month;
      double bank_part = 0;
      for (size_t i = 0; i < month; i++) {
        bank_part = (credit_part * (month - i)) * percent;
        if (result[2] == 0) {
          result[0] = credit_part + bank_part;
        }
        result[2] += credit_part + bank_part;
      }
      result[3] = credit_part + bank_part;
    } else {
      result[0] = summ * (percent + (percent/(pow(1+percent, month)-1)));
      result[0] *= 100;
      result[0] = round(result[0]);
      result[0] /= 100;
      result[2] = result[0] * month;
      result[2] *= 100;
      result[2] = round(result[2]);
      result[2] /= 100;
    }
    result[1] = result[2] - summ;
    result[1] *= 100;
    result[1] = round(result[1]);
    result[1] /= 100;
  return result;
  }
}

double *debit_calk(int argc, char *argv[]) {
  double *result = calloc(3, sizeof(double));
  if (argc < 6) {
    result[0] = NAN;
  } else {
    char spec_arr[6][3] = {{"%lf"}, {"%d"}, {"%lf"}, {"%lf"}, {"%d"}, {"%d"}};
    double summ = 0;
    int day = 0;
    double percent = 0;
    double nalog = 0;
    int pay_rait = 0;  //  0-в конце, 1- день, 7 - неделю, 30 - месяц, 90- квартал, 183 -полгода, 365-год
    int type = 0;  //  1 - есть капитализация
    char *day_addition = NULL;
    char *summ_addition = NULL;
    void *data_ptr[8] = {&summ, &day, &percent, &nalog, &pay_rait, &type};
    if (argc == 8) {
      summ_addition = argv[7];
      argc--;
      day_addition = argv[6];
      argc--;
    }
    while (argc) {
      argc--;
      if (!sscanf(argv[argc], spec_arr[argc], data_ptr[argc])) {
        result[0] = NAN;
        break;
      }
    }
    nalog /= 100;
    int input_day = 0;
    double summ_add = 0;
    if (day_addition != NULL) {
      do {
        if (sscanf(day_addition, "%d", &input_day)) {
          scrole_one_num(&day_addition);
          if (*day_addition != '\0') {
            day_addition++;
          }
          if (!input_day) {
            if (sscanf(summ_addition, "%lf", &summ_add)) {
              if (*summ_addition == '-') {
                summ_addition++;
              }
              scrole_one_num(&summ_addition);
              if (*summ_addition != '\0') {
                summ_addition++;
              }
              summ += summ_add;
            }
          }
        }
      } while (!input_day && *day_addition != '\0');
    }
    if (type) {
    percent /= 100;
    double tmp = 0;
    result[2] = summ;
    for (int day_cont = 0; day_cont <= day; day_cont++) {
        tmp = (result[2] * pow(((percent/365)+1.0), pay_rait))-result[2];
        if (day_cont && !(day_cont %pay_rait)) {
          if (nalog !=0) {
            double nal = tmp * nalog;
            result[1] += nal;
            tmp -= nal;
          }
          tmp *=100;
          tmp = round(tmp);
          tmp /=100;
          result[2] += tmp;
          tmp = 0;
      }
        if (input_day && day_cont == input_day) {
          if (*summ_addition != '\0' && sscanf(summ_addition, "%lf", &summ_add)) {
            if (*summ_addition == '-') {
              summ_addition++;
            }
            scrole_one_num(&summ_addition);
            if (*summ_addition != '\0') {
              summ_addition++;
            }
          } else {
            summ_add = 0;
          }
          result[2] += summ_add;
          summ += summ_add;
          if (*day_addition != '\0' && sscanf(day_addition, "%d", &input_day)) {
          scrole_one_num(&day_addition);
          if (*day_addition != '\0') {
           day_addition++;
          }
          } else {
            input_day = 0;
          }
        }
    }
    if (tmp != 0) {
      tmp = (result[2] * pow((percent/365)+1.0, day%pay_rait))-result[2];
      tmp *=100;
      tmp = round(tmp);
      tmp /=100;
      result[2] += tmp;
    }
    result[0] = result[2] - summ;
    } else {
      double tmp = 0;
      for (int day_cont = 0; day_cont <= day; day_cont++) {
        if (day_cont) {
          tmp += (summ * percent)/365.0;
        }
        if (input_day && day_cont == input_day) {
          if (*summ_addition != '\0' && sscanf(summ_addition, "%lf", &summ_add)) {
            if (*summ_addition == '-') {
              summ_addition++;
            }
            scrole_one_num(&summ_addition);
            if (*summ_addition != '\0') {
              summ_addition++;
            }
          } else {
            summ_add = 0;
          }
          summ += summ_add;
          if (*day_addition != '\0' && sscanf(day_addition, "%d", &input_day)) {
          scrole_one_num(&day_addition);
          if (*day_addition != '\0') {
           day_addition++;
          }
          }
        }
        if (day_cont && !(day_cont % pay_rait)) {
          tmp = round(tmp);
          tmp /=100;
          result[0] += tmp;
          tmp = 0;
        }
      }
      if (tmp != 0) {
        tmp = round(tmp);
        tmp /=100;
        result[0] += tmp;
      }
      result[0] *=100;
      result[0] = round(result[0]);
      result[0] /=100;
      if (nalog != 0) {
        result[1] = result[0] * nalog;
        result[0] -= result[1];
      }
      result[2] = summ;
    }
  }
  return result;
}
