#include "back.h"
#include <cmath>

back::back(QString input) {
    parsing(input);
    polishConvertation();
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

void back::polishConvertation() {
  auto iter_nums = nums.begin();
  auto iter_func = func.begin();
  for (int last_priority = 0; iter_func!= func.end(); iter_func++) {
    int curent_priority = getPriority(*iter_func);
    if (last_priority && last_priority > curent_priority) {
      if (getArgs(*iter_func) == 1) {
        auto tmp_iter = iter_func;
        for (tmp_iter--; getPriority(*tmp_iter) > curent_priority; tmp_iter--);
        func.insert(tmp_iter, *iter_func);
        func.erase(iter_func);
        iter_func = tmp_iter;
      } else {

      }
    }
    last_priority = curent_priority;
  }
}

int back::getPriority(QString input) {
  if (input.length() > 1) {
    if (QString("asinaconatan").contains(input)) {
      return 3;
    } else {
      return 2;
    }
  } else {
    switch (input.at(0).row()) {
    case '-':
    case '+':
    case ')':
      return 1;
      break;
    case '*':
    case '/':
    case '%':
      return 2;
    case '^':
    case '(':
      return 3;
    default:
      break;
    }
  }
}

int back::getArgs(QString input) {
  switch (input.at(0).row()) {
    case '-':
    case '+':
    case '*':
    case '/':
    case '%':
    case '^':
      return 2;
      break;
    default:
      return 1;
      break;
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
      addAddress(&*nums.begin());/// swtich on nums.end()
    } else if (two_arg_fnc.contains(tmp_char)) {
      func.push_front(tmp_char);
    } else {
      tmp += tmp_char;
      if (tmp.contains(reg_str)) {
        func.push_front(tmp);
        tmp.clear();
      }
    }
  }
}

double back::actionOne(double x,QString input) {
  if (input.contains("sin")) {
    if (input.startsWith("a")) {
      return asin(x);
    } else {
      return sin(x);
    }
  } else if (input.contains("cos")) {
    if (input.startsWith("a")) {
      return acos(x);
    } else {
      return cos(x);
    }
  } else if (input.contains("tan")) {
    if (input.startsWith("a")) {
      return atan(x);
    } else {
      return tan(x);
    }
  } else if (input.contains("log")) {
    return log10(x);
  } else if (input.contains("ln")) {
    return log(x);
  } else if (input.contains("sqrt")) {
    return sqrt(x);
  }
}

double back::actionTwo(double x,double arg2, QString input) {
  switch (input.at(1).row()){
  case '+':
   arg2 += x;
    break;
  case '-':
   arg2 -= x;
    break;
  case '*':
   arg2 *= x;
    break;
  case '/':
   arg2 /= x;
    break;
  case '%':
   arg2 = fmod(arg2, x);
    break; 
  case '^':
   arg2 = pow(arg2, x);
    break;
  default:
    break;
  }
  return arg2;
}

double back::calculate() {
  double result = 0;
  auto iter_nums = nums.begin();
  auto iter_func = func.begin();
  for (result = *iter_nums; iter_func != func.end(); iter_func++) {
    if (iter_func->length() == 1) {
      if (iter_func->at(0) == '(') {
        nums_out.push_back(result);
        result = *iter_nums;///////// iter_nums++
      } else if (iter_func->at(0) == ')') {
        nums.push_front(*nums_out.end());
        nums_out.pop_back();////////
      } else {
        iter_nums++;
        result = actionTwo(result, *iter_nums, *iter_func);
      }
    } else {
      result = actionOne(result, *iter_func);
    }
  }
  return result ;
}
