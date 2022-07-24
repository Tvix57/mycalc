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



double back::calculate() {
  double result = 0;
  auto iter_nums = nums.begin();
  auto iter_func = func.begin();
  for (result = *iter_nums; iter_func != func.end(); iter_func++) {

    
  }
  return result ;
}
