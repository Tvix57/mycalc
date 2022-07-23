#include "stack_func.h"
#include <cmath>

stack_func::stack_func() {
    head = nullptr;
}

stack_func::~stack_func()
{

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
}

void stack_func::addSub() {
    addNode();
    head->fnc_ptr = sub_fnc;
}

void stack_func::addNode() {
    node *tmp = new node();
    tmp->prev = head;
    head = tmp;
}

stack_func::node * stack_func::begin() {
    return head;
}

double add_fnc(double arg1, double arg2) {
  return arg1 + arg2;
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
