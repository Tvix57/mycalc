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
    QChar sign_char = stream.string()->at(stream.pos());
    stream >> number;
    if (last_pos != stream.pos()) {
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
    } else {
      QChar tmp_char;
      stream >> tmp_char;
      tmp += tmp_char;
    }
  }
}

void back::polishConvertation() {
  auto iter_stack = polish_stack.begin();
  auto insert_positin = iter_stack;
  QList <data_t> tmp_stack;
  data_t tmp;
  for (; iter_stack != polish_stack.end(); iter_stack++) {


    if (!iter_stack->fun.isEmpty()) {
        tmp = *iter_stack;
        polish_stack.erase(iter_stack);
        if (tmp_stack.isEmpty()) {
            insert_positin = iter_stack;
        }
        if (!tmp_stack.isEmpty() && (getPriority(tmp.fun) > getPriority(tmp_stack.last().fun))) {
            for (;!tmp_stack.isEmpty();) {
                insert_positin--;
//                data_t tmp3 = *insert_positin;

                polish_stack.insert(insert_positin, tmp_stack.last());
                tmp_stack.pop_back();
            }
        }
        if (!(tmp.fun.contains('(') || (tmp.fun.contains(')')))) {
            tmp_stack.push_front(tmp);
        }
    }
  }
  if (!tmp_stack.isEmpty()) {
      for (--insert_positin;!tmp_stack.isEmpty();--insert_positin) {
          polish_stack.insert(insert_positin, tmp_stack.last());
          tmp_stack.pop_back();
      }
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
    switch ((char)input.at(0).cell()) {
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
      tmp_node.fun = tmp2;
      polish_stack.push_front(tmp_node);
    } else {
      tmp += tmp_char;
      if (tmp.contains(reg_str)) {
//        polish_stack.push_front(tmp);
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
  switch ((char)input.at(0).cell()){
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
  QList<QString> func_stack;
  QList<double> nums_out;
  auto iter_stack = polish_stack.begin();
  for (; iter_stack != polish_stack.end(); iter_stack++) {
    if (iter_stack->fun.isEmpty()) {
      nums_out.push_back(iter_stack->num);
        if (!func_stack.isEmpty()) {
            if (func_stack.last().length() == 1) {
                if (nums_out.length() > 1) {
                  double tmp = nums_out.last();
                  nums_out.pop_back();
                  nums_out.last() = actionTwo(nums_out.last(), tmp, func_stack.last());
                  func_stack.pop_front();
                }
            } else {
              nums_out.last() = actionOne(nums_out.last(), func_stack.last());
              func_stack.pop_front();
            }
        }
    } else {
        func_stack.push_front(iter_stack->fun);
    }
  }
  return nums_out.last();
}
