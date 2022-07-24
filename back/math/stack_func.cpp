#include "stack_func.h"
#include <cmath>

stack_func::stack_func() {
    head = nullptr;
}

bool stack_func::empty() {
    if (head != nullptr) {
        if (head->prev != nullptr) {
            return false;
        }
    }
    return true;
}

void stack_func::addSumm() {
    addNode();
    head->fnc_ptr = add_fnc;
    args = true;
}

void stack_func::addSub() {
    addNode();
    head->fnc_ptr = sub_fnc;
    args = true;
}

void stack_func::addSub() {
    addNode();
    head->fnc_ptr = log_fnc;
    args = false;
}

void stack_func::addNode() {
    node *tmp = new node();
    tmp->prev = head;
    head = tmp;
}

double add_fnc(double arg1, double arg2 = NAN) {
  return arg1 + arg2;
}
double sub_fnc(double num1, double num2 = NAN) {
  return num1 - num2;
}
double mul_fnc(double num1, double num2 = NAN) {
  return num1 * num2;
}
double div_fnc(double num1, double num2 = NAN) {
  return num1 / num2;
}
double sin_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return sin(num1);
    } else {
      return NAN;
    }
}
double cos_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return cos(num1);
    } else {
      return NAN;
    }
}
double acos_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return acos(num1);
    } else {
      return NAN;
    }
}
double asin_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return asin(num1);
    } else {
      return NAN;
    }
}
double tan_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return tan(num1);
    } else {
      return NAN;
    }
}
double atan_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return atan(num1);
    } else {
      return NAN;
    }
}
double sqrt_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return sqrt(num1);
    } else {
      return NAN;
    }
}
double ln_fnc(double num1) {
      return log(num1);
}
// double ln_fnc(double num1, double num2 = NAN) {
//     if (num2 != NAN) {
//       return log(num1);
//     } else {
//       return NAN;
//     }
// }

double log_fnc(double num1, double num2 = NAN) {
    if (num2 != NAN) {
      return log10(num1);
    } else {
      return NAN;
    }
}
double pow_fnc(double num1, double num2 = NAN) {
  return pow(num1, num2);
}
double mod_fnc(double num1, double num2 = NAN) {
  return fmod(num1, num2);
}
double unar_min(double num1, double num2 = NAN) {
  return num1*-1;
}
