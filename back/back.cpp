#include "back.h"

back::back(QString input) {
    parsing(input);
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

void back::addFunction(QString input) {
  QTextStream stream(&input);
  QString tmp;
  while (!stream.atEnd()) {
    QChar tmp_char;
    stream >> tmp_char;
    if (tmp_char.isLetter('X')) {
      nums.push_front(0);
      addAddress(&*nums.begin());
    } else if (tmp_char.isLetter("+-*/^%()")) {
      twoArgFunc(tmp_char); 
    } else {
      tmp += tmp_char;
      if (false) {
        oneArgFunc(tmp);
      }
    }
  }
}

void back::twoArgFunc(Qchar in) {
  switch (in.row()) {
    case '+':
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
  for (; iter_nums != nums.end(); iter_nums++, iter_fnc++) {
    result = 0;
  }
  return result;
}
