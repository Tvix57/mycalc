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
    if (stream.string()->at(stream.pos()).isNumber()) {
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

void back::polishConvertation() {
  QList <data_t> tmp_stack;
  data_t tmp;
  for (int i = polish_stack.length()-1; i >= 0;  i--) {
    tmp = polish_stack.at(i);
    if (!tmp.fun.isEmpty()) {
      polish_stack.removeAt(i);
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
            }
            tmp_stack.pop_front();
          }

//////если встретил закрывающую скобку//////
      } else if (!tmp_stack.isEmpty() &&
                 tmp_stack.first().fun.contains(')')) {
          while (!tmp_stack.isEmpty() && !tmp_stack.first().fun.contains('(')) {
            if (!(tmp_stack.first().fun.contains('(') || tmp_stack.first().fun.contains(')'))) {
              polish_stack.insert(i, tmp_stack.first());
            }
            tmp_stack.pop_front();
          }
          if (!tmp_stack.isEmpty()) {
              tmp_stack.pop_front();
          }
          if (!tmp_stack.isEmpty() && tmp_stack.first().fun.length() > 1) {
              polish_stack.insert(i, tmp_stack.first());
              tmp_stack.pop_front();
          }
      }
      tmp_stack.push_front(tmp);
    }
  }

  if (!tmp_stack.isEmpty()) {
      while (!tmp_stack.isEmpty()) {
          if (!(tmp_stack.first().fun.contains('(') || tmp_stack.first().fun.contains(')'))) {
            polish_stack.insert(0, tmp_stack.first());
          }
          tmp_stack.pop_front();
        }
  }
}

bool back::leftAssotiation(QString input) {
  if (input.contains('^')|| input.contains("unar")) {
    return false;
  } else {
    return true;
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
//    case ')':
//    case '(':
      return 3;
    default:
      return 0;
      break;
    }
  }
}

int back::getArgs(QString input) {
  switch ((char)input.at(0).cell()) {
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
//      polish_stack.push_front(0);
//      addAddress(&*polish_stack.begin());/// swtich on nums.end()
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


    ////////заменить порядок забора элементов на обратный


  QList<QString> func_stack;
  QList<double> nums_out;
  auto iter_stack = polish_stack.begin();
  for (; iter_stack != polish_stack.end(); iter_stack++) {
    if (iter_stack->fun.isEmpty()) {
      nums_out.push_back(iter_stack->num);
        if (!func_stack.isEmpty()) {
            if (func_stack.first().length() == 1) {
                if (nums_out.length() > 1) {
                  double tmp = nums_out.first();
                  nums_out.pop_front();
                  nums_out.first() = actionTwo(nums_out.first(), tmp, func_stack.first());
                  func_stack.pop_front();
                }
            } else {
              nums_out.first() = actionOne(nums_out.first(), func_stack.first());
              func_stack.pop_front();
            }
        }
    } else {
        func_stack.push_front(iter_stack->fun);
    }
  }
  if (!func_stack.empty()) {
      while (!func_stack.empty()) {
          if (func_stack.first().length() == 1) {
              if (nums_out.length() > 1) {
                double tmp = nums_out.first();
                nums_out.pop_front();
                nums_out.first() = actionTwo(nums_out.first(), tmp, func_stack.first());
                func_stack.pop_front();
              } else {
                  break;
              }
          } else {
            nums_out.first() = actionOne(nums_out.first(), func_stack.first());
            func_stack.pop_front();
          }
      }
  }
  return nums_out.last();
}
