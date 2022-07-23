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
        addFunctions(tmp);
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
      addTwoArgFunc(tmp_char); 
    } else {
      tmp += tmp_char;
      if (tmp.contains(reg_str)) {
        addOneArgFunc(tmp);
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

void back::addTwoArgFunc(QChar in) {
  switch (in.row()) {
    case '+':
      stack.addSumm();
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
  double result = 0;
  auto iter_nums = nums.begin();
  auto iter_func = stack.begin();
  for (; iter_func->prev != nullptr; --iter_func) {
    double tmp = iter_func->fnc_ptr(result, 2);
    result += tmp;
  }
  return result;
}
