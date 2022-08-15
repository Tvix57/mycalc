#include "back.h"
#include <cmath>

back::back(QString input) {
    start = 0;
    end = 0;
    step = 0;
    parsing(input);
    polishConvertation();
}

void back::parsing(QString input) {
  QTextStream stream(&input);
  QString tmp;
  while (!stream.atEnd()) {
    if (stream.string()->at(stream.pos()).isNumber() || stream.string()->at(stream.pos()).cell() == '.') {
      int last_pos = stream.pos();
      QChar sign_char = stream.string()->at(stream.pos());
      double number;
      stream >> number;
      int new_pos = stream.pos();
      if (!tmp.isEmpty()) {
        addFunctions(tmp);
        tmp.clear();
      }
      if (sign_char == '+' || sign_char == '-') {
          if (sign_char == '-') {
              number *= -1;
          }
          addFunctions(sign_char);
      }
      data_t tmp_node;
      tmp_node.num = number;
      tmp_node.fun.clear();
      polish_stack.push_front(tmp_node);
      if ((sign_char == '+' || sign_char == '-') && new_pos - last_pos == 1) {
        polish_stack.pop_front();
      }
    } else {
      QChar tmp_char;
      stream >> tmp_char;
      tmp += tmp_char;
    }
  }
  if (!tmp.isEmpty()) {
    addFunctions(tmp);
    tmp.clear();
  }
}

void back::addAllIndex() {
    for(auto i = position_x.begin(); i != position_x.end(); i++) {
        *i = *i+1;
    }
}

void back::subAllIndex() {
    for(auto i = position_x.begin(); i != position_x.end(); i++) {
        *i = *i-1;
    }
}

void back::polishConvertation() {
  QList <data_t> tmp_stack;
  data_t tmp;
  for (int i = polish_stack.length()-1; i >= 0;  i--) {
    tmp = polish_stack.at(i);
    if (!tmp.fun.isEmpty() && !tmp.fun.contains('X')) {
      polish_stack.removeAt(i);
      if (!position_x.empty()) {
          subAllIndex();
      }
      //////если встретил приоритет выше //////
      if (!tmp_stack.isEmpty() &&
         (!tmp.fun.contains('(') && !tmp.fun.contains(')')) &&
         ((getPriority(tmp.fun) < getPriority(tmp_stack.first().fun)) ||
          (getPriority(tmp.fun) == getPriority(tmp_stack.first().fun)) && leftAssotiation(tmp.fun))) {

          while (!tmp_stack.isEmpty() &&
                 ((getPriority(tmp.fun) < getPriority(tmp_stack.first().fun)) ||
                  (getPriority(tmp.fun) == getPriority(tmp_stack.first().fun)) && leftAssotiation(tmp.fun))) {
            if (!(tmp_stack.first().fun.contains('(') || tmp_stack.first().fun.contains(')'))) {
              polish_stack.insert(i, tmp_stack.first());
            if (!position_x.empty()) {
              addAllIndex();
            }
            }
            tmp_stack.pop_front();
          }
//////если встретил закрывающую скобку//////
      } else if (tmp.fun.contains(')')  &&
                 !tmp_stack.isEmpty()) {
          while (!tmp_stack.isEmpty() && !tmp_stack.first().fun.contains('(')) {
            if (!(tmp_stack.first().fun.contains('(') || tmp_stack.first().fun.contains(')'))) {
              polish_stack.insert(i, tmp_stack.first());
            if (!position_x.empty()) {
              addAllIndex();
            }
            }
            tmp_stack.pop_front();
          }
          if (!tmp_stack.isEmpty()) {
              tmp_stack.pop_front();
          }
          if (!tmp_stack.isEmpty() && (tmp_stack.first().fun.length() > 1 || tmp_stack.first().fun.contains('^')) ) {
              polish_stack.insert(i, tmp_stack.first());
                if (!position_x.empty()) {
                    addAllIndex();
                }
              tmp_stack.pop_front();
          }
          continue;
      }
      tmp_stack.push_front(tmp);
    } else {
        if (tmp.fun.contains('X')) {
            tmp.fun.clear();
            polish_stack.replace(i,tmp);
            position_x.push_front(i);
        }
    }
  }
  if (!tmp_stack.isEmpty()) {
      while (!tmp_stack.isEmpty()) {
          if (!(tmp_stack.first().fun.contains('(') || tmp_stack.first().fun.contains(')'))) {
            polish_stack.insert(0, tmp_stack.first());
            if (!position_x.empty()) {
            addAllIndex();
            }
          }
          tmp_stack.pop_front();
      }
  }
}

bool back::leftAssotiation(QString input) {
  if (input.length() > 1) {
        return false;
  } else {
    if (input.contains('^'))  {
        return false;
    } else {
        return true;
    }
  }
}

int back::getPriority(QString input) {
  if (input.length() > 1) {
    if (QString("asinaconatanunar").contains(input)) {
      return 3;
    } else {
      return 2;
    }
  } else {
    switch ((char)input.at(0).cell()) {
    case '-':
    case '+':
      return 1;
      break;
    case '*':
    case '/':
    case '%':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
      break;
    }
  }
}

void back::addAddress(int position) {
  position_x.push_front(position);
}

void back::replaceAllX(double x) {
  data_t new_x;
  new_x.num = x;
  auto iter = position_x.begin();
  for (; iter != position_x.end(); iter++) {
    polish_stack.replace(*iter, new_x);
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
    if (tmp_char.cell() == 'X') {
      data_t tmp_node;
      tmp_node.num = 0;
      tmp_node.fun = tmp_char;
      polish_stack.push_front(tmp_node);
    } else if (two_arg_fnc.contains(tmp_char)) {
      QString tmp2 = tmp_char;
      data_t tmp_node;
      tmp_node.num = 0;
      if (tmp2.contains('-') && polish_stack.first().fun.contains('(')) {
          tmp2 = "unar";
      }
      tmp_node.fun = tmp2;
      polish_stack.push_front(tmp_node);
    } else {
      tmp += tmp_char;
      if (tmp.contains(reg_str)) {
        data_t tmp_node;
        tmp_node.num = 0;
        tmp_node.fun = tmp;
        polish_stack.push_front(tmp_node);
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
  } else if (input.contains("unar")) {
      return (x*-1);
    }
}

double back::actionTwo(double arg1, double arg2, QString input) {
  switch ((char)input.at(0).cell()){
  case '+':
   arg1 = arg1 + arg2;
    break;
  case '-':
   arg1 = arg1 - arg2;
    break;
  case '*':
   arg1 = arg1 * arg2;
    break;
  case '/':
   arg1 = arg1 / arg2;
    break;
  case '%':
   arg1 = fmod(arg1, arg2);
    break; 
  case '^':
   arg1 = pow(arg1, arg2);
    break;
  default:
    break;
  }
  return arg1;
}

double back::calculate() {
  QList<double> nums_out;
  for (int i = polish_stack.length()-1; i >= 0; i--) {
    if (polish_stack.at(i).fun.isEmpty()) {
        nums_out.push_front(polish_stack.at(i).num);
    } else {
        if (polish_stack.at(i).fun.length() == 1) {
            if (nums_out.length() > 1) {
              double tmp = nums_out.first();
              nums_out.pop_front();
              nums_out.first() = actionTwo(nums_out.first(), tmp, polish_stack.at(i).fun);
            }
        } else {
          nums_out.first() = actionOne(nums_out.first(), polish_stack.at(i).fun);
        }
    }
  }
  return nums_out.first();
}

void back::setRange(double start, double end, double step) {
    this->start = start;
    this->end = end;
    this->step = step;
}

void back::calculateGraph() {
    for (; start <= end; start += step) {
        replaceAllX(start);
        double y = calculate();
        emit new_coord(start, y);
    }
}
