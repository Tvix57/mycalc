#include "back.h"

back::back(QString input) {
    parsing(input);
    ///sort();
}

void back::parsing(QString input) {
  QTextStream stream(&input);
  QString tmp;
  while (!stream.atEnd()) {
    double number;
    int last_pos = stream.pos();
    stream >> number;
    if (last_pos != stream.pos()) {
      if (!tmp.isEmpty()) {
        addFunction(tmp);
        tmp.clear();
      }
      nums.push_front(number);
    } else {
      QChar tmp_char;
      stream >> tmp_char;
      tmp += tmp_char;
    }
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

void back::addFunctions(QString input) {
  QTextStream stream(&input);
  QString tmp;
  QString two_arg_fnc = "+-*/^%()";
  QRegularExpression reg_str("^([a]?((sin)|(cos)|(tan))|(log)|(ln)|(sqrt))$");
  while (!stream.atEnd()) {
    QChar tmp_char;
    stream >> tmp_char;
    if (tmp_char.row() == 'X') {
      nums.push_front(0);
      addAddress(&*nums.begin());
    } else if (two_arg_fnc.contains(tmp_char)) {
      twoArgFunc(tmp_char); 
    } else {
      tmp += tmp_char;
      if (tmp.contains(reg_str)) {
        oneArgFunc(tmp);
        tmp.clear();
      }
    }
  }
}

void back::addOneArgFunc(QString input) {
  bool a_flag = false;
  if (input.startsWith("a")) {
    a_flag = true;
  } 
  if (input.contains("sin")) {
    if (a_flag) {

    } else {

    }
  } else if (input.contains("cos")) {
    if (a_flag) {

    } else {

    }
  } else if (input.contains("tan")) {
    if (a_flag) {

    } else {

    }
  } else if (input.contains("sqrt")) {

  } else if (input.contains("log")) {

  } else if (input.contains("ln")) {

  }
}

double back::my_summ(double arg1, double arg2) {
  return arg1 + arg2;
}

void back::addTwoArgFunc(QChar in) {
  switch (in.row()) {
    case '+':
    int a = 1, b = 2;
      func.push_front([=]{my_summ(a, b);});
      break;
    case '-':
      break;
    case '*':
      break;
    case '/':
      break;
    case '^':
      break;
    case '%':
      break;
    case '(':
      break;
    case ')':
      break;
    default:
      break;
  }
}

double back::calculate() {
  double result;
  auto iter_nums = nums.begin();
  auto iter_fnc = func.begin();
  for (; iter_fnc != func.end(); iter_fnc++) {
    result = 0;
  }
  return result;
}
