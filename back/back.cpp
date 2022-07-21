#include "back.h"

back::back(QString input) {
    parsing(input);
}


void back::parsing(QString input) {
  QTextStream stream(&input);
  while (!stream.atEnd()) {
//    if (stream.seek().isDigit()) {
      double number;
      stream >> number;
//      if (!stream.Status) {
          nums.push_front(number);
//      }
//    }else {
//      QString tmp;
//      while (!stream.isdigit()) {
//          stream >> tmp;
//      }
//      addFunction(tmp);
//    }
  }
}

void back::addAddress(double *x) {
  address_x.push_back(x);
}

void back::replaceAllX(const double &x) {
  auto iter = address_x.begin();
  for (; iter != address_x.end(); iter++) {
    **iter = x;
  }
}

void back::addFunction(QString input) {
  // int a = ..., b = ...;
  // func.push_front([=]{sin(a)});
  // func.push_front([]{my_summ(10, 10);});
}

double back::calculate() {
  double result;
  auto iter_nums = nums.begin();
  auto iter_fnc = func.begin();
  for (; iter_nums != nums.end(); iter_nums++, iter_fnc++) {
    result = 0;
  }
  return result;
}
